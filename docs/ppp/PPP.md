---
marp: true
title: "Celestron CG-3 Go-To/Tracking Conversion"
---
# Celestron CG-3 Go-To/Tracking Conversion
---
## Project Description
Telescopes have become more affordable over time, but telescopes that can automatically track objects across the sky and/or point to specific objects in the sky are still a bit expensive. This tracking is indispensable for any kind of photography or scientific work, as the telescope needs an object in the same spot within its field of view for an extended period of time in order to collect any meaningful results. This project seeks to create such a conversion kit for the telescope that I own, which uses a Celestron CG-3 equatorial mount. An equatorial mount has two axes that can be manipulated: right ascension (left-right) and declination (up-down). To track an object across the sky, only the right ascension needs to be changed. To "go-to," or find, an object in the sky, however, both axes needs to be moved. 

---
## Requirements
- Create control software for the two required motors (right ascension and declination axes)
- Integrate user input (buttons and a display)
- Create a method to calibrate the system using a known star (like Polaris)
---
## Telescope image
![width:750px](https://www.celestron.com/cdn/shop/products/050234210492_PowerSeeker_127EQ_21049_2.jpg?v=1534172033)

---
## Learning with AI Topics
- Hardware: user IO (buttons and display), in order to show the user the current celestial coordinates that the telescope is pointing at and so they can choose what object to track
- Hardware: stepper motors, which are required to move the two axes on the telescope mount
- Software: how to drive the motors and how to handle user input with physical buttons

## How will AI be used?
I will use AI in more of an advisory role, asking it general questions about an approach or specifics of the implementation. I don't want to generate code necessarily; I just want to be pointed in the right direction.

---
## Milestones
### Milestone 1 (weeks 4-6):
- Present PPP
- Begin work on the project: research for particular components and how to integrate them into the system
- Source the hardware that has been researched and begin the integration steps

### Milestone 2 (weeks 7-8):
- Create MVP by continuing the integration
- Test the system as a whole: is it able to work as intended?
- Work on midterm presentation, which details the work done so far 
---
### Milestone 3 (weeks 9-12):
- Begin transitioning prototype into a final version: clean up any roughness/unsightliness in the prototype stage
- Find/create an enclosure for the Arduino and electronics for weatherproofing
- Fix issues which cropped up during the prototyping phase

### Milestone 4 (weeks 12-16):
- Finish the project and work on the final presentation
- Squash any remaining bugs
- Make project as presentable as possible: make it durable and able to be set up in the classroom
