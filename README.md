#URUSARO Narasha ReadMe 
# Automatic Gate Demo Kit

This Arduino project demonstrates an automatic gate system using:

- Ultrasonic sensor (HC-SR04)
- Servo motor
- Red and Blue LEDs
- Buzzer

## 🔧 Functionality

- The ultrasonic sensor continuously checks for objects.
- When an object is detected within 15 cm:
  - The servo rotates to 90° to open the gate.
  - The **blue LED** turns on.
  - The **buzzer** beeps continuously.
- After 5 seconds:
  - The servo returns to 0° to close the gate.
  - The **red LED** turns on.
  - The **buzzer** turns off.

## 🛠 Hardware Components

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- Red and Blue LEDs
- Piezo Buzzer
- Resistors
- Breadboard and Jumper Wires

## 📁 File

- `automatic_gate.ino`: Main Arduino sketch

Upload this code to your Arduino Uno and connect the components as described to see the automatic gate in action.

