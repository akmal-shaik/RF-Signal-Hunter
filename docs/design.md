# Design

## Goal

Build a handheld device that detects and displays relative changes in nearby RF activity.

The device is an educational RF detector. It is not intended to identify transmitters, determine frequencies or provide calibrated RF power measurements.

## System Overview

```text
RF activity
    ↓
Antenna or pickup
    ↓
Envelope detector
    ↓
Filtering and voltage protection
    ↓
ESP32 ADC
    ↓
Signal processing
    ↓
Display and serial output
```

The analogue front end will convert high-frequency RF energy into a slowly changing voltage that the ESP32 can measure.

## Main Hardware

* ESP32 DEVKIT V1
* Analogue RF envelope detector
* ADC filtering and protection
* User display
* Battery power system
* Handheld enclosure

Exact analogue components will be selected through breadboard experiments.

## Software

* PlatformIO
* Arduino framework for ESP32
* C++
* USB serial data logging
* Python for later data analysis

## Current Progress

* ESP32 firmware environment configured
* Firmware successfully built and uploaded
* Serial communication verified
* ESP32 bring-up test passed
* ADC characterisation is next

## Development Approach

Major circuits will be tested on a breadboard before designing a PCB.

Only meaningful results, important design changes and completed milestones will be documented.
