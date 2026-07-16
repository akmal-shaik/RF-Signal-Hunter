# ESP32 Bring-Up

## Goal

Confirm that the ESP32 firmware can be built, uploaded and monitored through USB serial.

## Setup

* ESP32 DEVKIT V1
* PlatformIO
* Arduino ESP32 framework
* USB serial at 115200 baud

## Result

**Passed**

The firmware:

* Built successfully
* Uploaded successfully
* Started correctly
* Produced continuous serial output
* Produced 13 heartbeats with 1000 ms between each recorded value
* Continued operating without unexpected resets

The captured output is available in [`serial_output.txt`](serial_output.txt).

The ESP32 setup is ready for ADC characterisation.
