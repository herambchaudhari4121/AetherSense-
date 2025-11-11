/*
  Project: AetherSense
  Description:
    AetherSense is an Arduino UNO-based temperature and humidity monitoring system 
    using the DHT11 sensor. It displays real-time readings on the Serial Monitor 
    and controls an LED indicator when temperature exceeds a set threshold.

  Hardware:
    - Arduino UNO
    - DHT11 sensor (connected to pin 7)
    - LED with resistor (connected to pin 12)
  
  Libraries Required:
    - DHT sensor library by Adafruit
    - Adafruit Unified Sensor library
*/

#include <DHT.h>

// ------------------ Pin Configuration ------------------
#define DHTPIN 7        // DHT11 Data pin connected to Arduino pin 7
#define DHTTYPE DHT11   // Define sensor type
#define LED_PIN 12      // LED connected to pin 12

// ------------------ Threshold & Constants ------------------
const float TEMP_THRESHOLD = 30.0; // Temperature threshold in °C

// Create DHT object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);        // Initialize Serial Monitor
  dht.begin();               // Initialize DHT11 sensor
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output
  
  Serial.println(F("🌡️ AetherSense Initialized"));
  Serial.println(F("Monitoring Temperature & Humidity..."));
  Serial.println(F("-----------------------------------"));
}

void loop() {
  // Read temperature (°C) and humidity (%)
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if reading failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Error: Failed to read from DHT11 sensor!"));
    delay(2000);
    return;
  }

  // ------------------ LED Control ------------------
  if (temperature >= TEMP_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // Turn LED ON if hot
  } else {
    digitalWrite(LED_PIN, LOW);  // Turn LED OFF if normal
  }

  // ------------------ Serial Output ------------------
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.print(F(" °C | Humidity: "));
  Serial.print(humidity);
  Serial.println(F(" %"));

  delay(5000); // Wait for 5 seconds before next reading
}
