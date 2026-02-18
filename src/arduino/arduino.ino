#include <SoftwareSerial.h>
#include <AccelStepper.h>

// Define step constant
#define MODE 4

//mode, IN1, IN2, IN3, IN4
AccelStepper myStepper(MODE, 7, 8, 9, 10);

// Software Serial pins for ESP32C6 communication
// D11 = TX (to ESP32C6 RX)
// D12 = RX (from ESP32C6 TX)
SoftwareSerial esp32Serial(11, 12); // RX, TX

void setup() {
  //Serial.begin(9600);
  //Serial.println("Arduino Nano to ESP32C6");
  
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
