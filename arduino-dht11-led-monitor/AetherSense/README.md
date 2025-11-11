# Arduino UNO DHT11: Temperature & Humidity Monitoring with LED Control

This repo contains a simple Arduino sketch that reads temperature and humidity from a **DHT11** sensor, prints the values to the **Serial Monitor**, and turns an **LED** ON when the temperature crosses a threshold (default **30°C**).

## Hardware
- Arduino **UNO**
- DHT11 sensor/module
- LED + 220Ω–1kΩ resistor
- Jumper wires

### Wiring
```
DHT11       Arduino UNO
-----       -----------
VCC   --->  5V
GND   --->  GND
DATA  --->  D7    (use 10k pull‑up to 5V if your module doesn't include one)

LED         Arduino UNO
---         -----------
Anode --->  D12 (through a resistor)
Cathode ->  GND
```

## Software
- **Arduino IDE** 1.8.x or 2.x
- Install libraries via **Sketch ▸ Include Library ▸ Manage Libraries...**
  - `DHT sensor library` by **Adafruit**
  - `Adafruit Unified Sensor`

## Usage
1. Open `src/DHT11_LED_Control.ino` in Arduino IDE.
2. Select **Tools ▸ Board ▸ Arduino AVR Boards ▸ Arduino Uno**.
3. Select the correct **Port**.
4. **Upload** the sketch.
5. Open **Serial Monitor** (9600 baud) to see:
   ```
   TEMPERATURE: 28.5 °C  |  HUMIDITY: 62.0 %
   ```
6. The LED on **D12** turns **ON** when temperature `>= 30°C`.

## Customize
- Change the temperature threshold in the code:
  ```cpp
  const float TEMP_THRESHOLD_C = 30.0;
  ```
- Adjust the sampling interval by editing the `delay(5000);` line (milliseconds).

## Repo Structure
```
arduino-dht11-led-monitor/
├─ src/
│  └─ DHT11_LED_Control.ino
├─ .gitignore
├─ LICENSE
└─ README.md
```

## License
MIT
