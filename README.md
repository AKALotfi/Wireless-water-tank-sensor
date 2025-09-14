# Wireless-water-tank-sensor

Language: C++.

## Description:
This is a small project, using 2 Arduino Nano, one to measure the level of water in a water tank, the other, to use basic displays like LEDs and a buzzer to indicate the level of water, 2 HC-12 modules are used to build a link between the two Arduinos.

## Modules used:
- 2 Arduinos Nano
- JSN-SR04T sensor
- 2 HC-12
- 2 LED pins (Red & Green)
- Buzzer
- Dupont cables
- Potentiometer

- ## The project:
Using the JSN-SR04T, the first Arduino will calculate the level of the water in a tank, the sensor should put on the top of the tank, and the height, be changed with the potentiometer. When the level of water is detected, the informartions are directly sent to the second Arduino using the HC-12 modules, 2 informations will be sent through the modules, water level & pourcentage of the level compared to the height of the tank, the second Arduino will take the pourcentage and according to the protocol, display through the outputs, the level of the water to the user.

## Protocol:
- Level of water > 50% = Green light
- 50% > Level of water > 25% = Red light
- Level of water < 25% = Red light + Buzzer.

## Software Requirements:
- Arduino IDE
- Software Serial (library)

## Schematic:
- A picture will be added later

## Demo:
- A picture will be added later

## Contributing
-If you want to contribute to this project, please welcome to do so :)
