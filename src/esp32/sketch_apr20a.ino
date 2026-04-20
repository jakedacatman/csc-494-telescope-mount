#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Button2.h>
#include <AccelStepper.h>

//Define constants for rate calculation
#define SIDEREAL_DAY 86164.0905 //Sidereal day in seconds
#define STEP_SIZE 1.8/16 //Step size in degrees (1.8 deg/16 for microstepping)
#define RA_RATIO 48/5 //Ratio of knob rotations to degrees in RA (360 deg / 37.5 deg) 
#define SIDEREAL_RATE 360 / SIDEREAL_DAY //Rate in deg/s that the telescope needs to track

// Define stepper motor connections and motor interface type. 
// Motor interface type must be set to 1 when using a driver
#define dirPin D10
#define stepPin D9

Adafruit_SSD1306 display(128, 64, &Wire, -1);
AccelStepper stepper = AccelStepper(AccelStepper::DRIVER, stepPin, dirPin);
Button2 start_button;
Button2 clear_button;

void start(Button2& b) {  
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Tracking");
  display.display();
  stepper.setSpeed(SIDEREAL_RATE / STEP_SIZE / RA_RATIO);
}

void clear(Button2& b) {  
  display.clearDisplay();
  display.display();
  stepper.setSpeed(0);
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  start_button.begin(D1);
  start_button.setTapHandler(start);

  clear_button.begin(D2);
  clear_button.setTapHandler(clear);

  display.setCursor(0, 10);
  display.print("Initialized!");
  display.display();

  stepper.setSpeed(0);
  stepper.setMaxSpeed(1000);
}

void loop() {
  start_button.loop();
  clear_button.loop();
  stepper.runSpeed();
}