---
marp: true
size: 4:3
paginate: true
title: Telescope Mount
---
# Final Presentation - Telescope Mount
## Jacob Canada
---
#### Problem Domain
- For small telescopes like mine, tracking is needed in order to either take pictures of faint objects or more conveniently follow any type of object across the sky as the night progresses. There are existing solutions such as conversion kits or entire mounts, but these are expensive.
---
#### Solution Domain
- My solution is to mount a stepper motor to the RA axis of the telescope. With an equatorial mount such as my own, this is all that is needed to track objects. The stepper motor needs to be driven at a very specific rate. In the past, this was done mechanically, but nowadays it is easily achievable with microcontrollers like the ESP32C6.
---
## Technology stack
I used a few things:
- ESP32C6
- BIQU 42BYGH439-24Db stepper motor
- A4988 driver board
- 42CH42 driver expansion board
- SSD1306 display
- Adafruit tactile buttons
- MB102 power supply module
---
#### Demonstration Video
https://youtube.com/shorts/9DJ-Y1PWckY?feature=share

---
## Learning with AI
### Topic 1
I learned how to better ask for what I want in addition to learning about several hardware components that I could use on future projects. 
### Topic 2
I learned a few software libraries that I could use with my project as well as in the future. I also learned some new techniques for writing Arduino code that I did not know of when I first started.

---