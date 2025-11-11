// DHT11 Temperature & Humidity Monitor with LED control
// Board: Arduino UNO (AVR)
// Library: "DHT sensor library" by Adafruit + "Adafruit Unified Sensor" (install from Library Manager)
//
// Wiring
//   DHT11 --> Arduino
//   VCC   --> 5V
//   GND   --> GND
//   DATA  --> D7  (with a 10k pull-up to 5V if your module doesn't have one)
//   LED   --> D12 (through a 220Ω–1kΩ resistor to GND)
//
// Behavior
// - Reads temp (°C) and humidity (%) every 5s
// - If temperature >= 30°C, the LED turns ON; otherwise OFF
// - Prints values to the Serial Monitor at 9600 baud

#include <DHT.h>

#define DHTPIN 7       // DHT11 data pin
#define DHTTYPE DHT11  // Sensor type
const int LED_PIN = 12;
const float TEMP_THRESHOLD_C = 30.0;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);
  Serial.println(F("DHT11 Monitor started. Open Serial Monitor at 9600 baud."));
}

void loop() {
  float t = dht.readTemperature(); // in °C
  float h = dht.readHumidity();    // in %

  if (isnan(t) || isnan(h)) {
    Serial.println(F("Failed to read from DHT11 sensor!"));
    delay(2000);
    return;
  }

  // LED logic
  if (t >= TEMP_THRESHOLD_C) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Print nicely
  Serial.print(F("TEMPERATURE: "));
  Serial.print(t, 1);
  Serial.print(F(" °C  |  HUMIDITY: "));
  Serial.print(h, 1);
  Serial.println(F(" %"));

  delay(5000); // ms
}
