/**
 * Arduino Nano - AHT10 Sensor Reader (SoftwareSerial Version)
 * 
 * Uses SoftwareSerial to avoid conflict with USB Serial (D0/D1)
 * Reads temperature and humidity from AHT10 sensor
 * and sends data to ESP32C6 via Software Serial pins D2/D3
 * 
 * Hardware Connections:
 * AHT10:
 *   VCC -> 5V
 *   GND -> GND
 *   SDA -> A4
 *   SCL -> A5
 * 
 * To ESP32C6 (via Level Shifter):
 *   D2 (SW TX) -> Level Shifter HV1 -> LV1 -> ESP32C6 RX (GPIO17)
 *   D3 (SW RX) -> Level Shifter HV2 -> LV2 -> ESP32C6 TX (GPIO16)
 *   5V -> Level Shifter HV
 *   GND -> Level Shifter GND (and ESP32C6 GND)
 * 
 * IMPORTANT: D0/D1 are now FREE for USB communication!
 */

#include <SoftwareSerial.h>
#include <AccelStepper.h>

// Define step constant
#define MODE 4

// Creates an instance
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
AccelStepper myStepper(MODE, 7, 8, 9, 10);

// Software Serial pins for ESP32C6 communication
// D2 = TX (to ESP32C6 RX)
// D3 = RX (from ESP32C6 TX)
SoftwareSerial esp32Serial(11, 12); // RX, TX

void setup() {
  // Hardware Serial for USB debugging (can use Serial Monitor!)
  //Serial.begin(9600);
  //Serial.println("Arduino Nano to ESP32C6");
  
  // Software Serial for ESP32C6 communication
  esp32Serial.begin(9600);
  //Serial.println("started!");

  myStepper.setMaxSpeed(250.0);
  myStepper.setAcceleration(50.0);
  myStepper.setSpeed(250);
  myStepper.moveTo(0);
  //Serial.println("motor reset");
}

void loop() {
  if (myStepper.distanceToGo() == 0) {
    while (!esp32Serial.available()) {}
    String data = esp32Serial.readStringUntil('\n');
    data.trim();

    //Serial.println(data);
    int to = data.toInt();

    esp32Serial.println("ack");
    myStepper.moveTo(to);
  }

  // Move the motor one step
  myStepper.run();
}