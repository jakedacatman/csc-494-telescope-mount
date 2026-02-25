---
marp: true
title: "S1P for Jacob Canada"
---
# S1P - Jacob Canada
---
## Current prototype
### Components:
- ESP32C6
- Level shifter
- Arduino Nano
- 28BYJ-48 stepper motor with ULN2003 driver board
- MB102 power supply module
---
## The setup
- Laptop and ESP32C6 connected to phone hotspot
- Send an HTTP POST request with the "steps" parameter set to the desired number of motor steps
- Arduino receives that value over serial and turns the motor
---
