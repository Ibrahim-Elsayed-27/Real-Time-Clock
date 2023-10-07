# Real Time Clock Project

Welcome to the Real Time Clock (RTC) Project, a precise clock system that displays real-time on six seven-segment displays and supports 3 different modes. This project is powered by the ATmega32 microcontroller and offers accurate timekeeping with interactive adjustments via a keypad interface. Whether for industrial applications, home use, or educational purposes, this RTC is a valuable tool for keeping track of time.

## Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Drivers Used](#drivers-used)
- [How to Use](#how-to-use)
- [Scenarios](#Scenarios)

## Features

- **Real-Time Clock Mode**: Displays the current time with separate segments for seconds, minutes, and hours.

- **Stop-Watch Mode**: Allows the user to set a specific time, and the timer will decrement until it reaches zero. The red LED alarm will be on for 10 seconds.
 
- **Alarm Mode**: Allows the user to set a specific time, and the timer operates as a real-time clock until reaching the specified time. The red LED alarm will be on for 10 seconds.

- **Interactive Keypad**: Adjust the time settings interactively through the keypad.

- **ON/OFF Button**: Press the ON/OFF button on the keypad to request time adjustment.

- **LCD Display**: Provides user-friendly interactions during time adjustments.

- **Efficient Data Handling**: Utilizes BCD to 7-segment conversion for efficient data representation.

- **Seven-Segment Display**: Utilizes only one port for data (4 pins) and three pins for enable using a 3-to-8 decoder.

## Hardware Requirements

- ATmega32 Microcontroller
- LCD Display
- LED
- Six Seven-Segment Displays
- Keypad
- BCD to 7-Segment Decoder
- 3-to-8 Decoder

## Drivers Used

- **HAL (Hardware Abstraction Layer)**:
  - LCD
  - LED
  - Seven-Segment Displays
  - Keypad
  - 3-to-8 Decoder


- **MCAL (Microcontroller Abstraction Layer)**:
  - Digital Input/Output (DIO)
  - Timer0 
  - Timer2 

## How to Use

1. Press the ON/OFF button on the keypad to request time adjustment.
   
2. Use the keypad to Select the desired mode.

3. Use the keypad to set the desired time values for seconds, minutes, and hours.

4. Interact with the LCD display for feedback during time adjustments.

5. The real-time clock will display the adjusted time on the six seven-segment displays.

6. Enjoy precise timekeeping and accurate time displays with your Real Time Clock Project!

## Scenarios


https://drive.google.com/file/d/1tKxOTKTkAgGDxuU7398ajAqcXIdo7iHx/view?usp=sharing

