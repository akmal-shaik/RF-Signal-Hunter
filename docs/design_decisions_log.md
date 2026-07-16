# Design Decisions Log

## DDL-001 — Instrument Classification

**Decision:**  
The device will be described as a relative RF activity detector.

**Alternatives considered:**

- Spectrum analyser
- RF power meter
- Frequency detector
- Transmitter locator
- Relative RF activity detector

**Selected option:**  
Relative RF activity detector.

**Reasoning:**  
A simple broadband detector can indicate changes in received RF energy, but without frequency-selective hardware and calibration it cannot accurately identify frequencies or measure absolute RF power.

**Trade-offs:**  
This produces a less ambitious headline capability, but creates an honest and experimentally defensible instrument.

**Validation required:**  
Demonstrate repeatable changes in detector output under controlled RF-source conditions.

**Status:**  
Accepted.

---

## DDL-002 — Development Before PCB Design

**Decision:**  
All major subsystems will be validated on a breadboard before PCB release.

**Reasoning:**  
Breadboard development allows circuit values, interfaces and firmware behaviour to be changed without the cost and delay of manufacturing a new PCB.

**Trade-offs:**  
Breadboards are poor RF environments and contain significant parasitic effects. The breadboard prototype will validate the detector concept and interfaces, but its exact performance may not represent the final PCB.

**Validation required:**  
Documented breadboard tests for the analogue detector, ADC interface, firmware, display and data capture.

**Status:**  
Accepted.

---

## DDL-003 — Relative Output Units

**Decision:**  
The initial interface will use relative or normalised activity units rather than dBm.

**Reasoning:**  
Displaying dBm would imply an absolute calibration that the initial detector does not possess.

**Trade-offs:**  
Measurements cannot be directly compared with calibrated RF instruments, but the displayed result remains honest and useful for relative testing.

**Validation required:**  
Confirm that the displayed relative scale responds consistently to controlled detector inputs.

**Status:**  
Accepted.

## DDL-004 — Envelope-Detection Architecture

**Decision:**  
Use an analogue RF envelope detector before the ESP32 ADC.

**Alternatives considered:**

- Directly sample RF using the ESP32 ADC
- Use a software-defined radio
- Use an analogue envelope detector
- Use a dedicated frequency-selective receiver

**Selected option:**  
Analogue envelope detector.

**Reasoning:**  
Most RF signals of interest operate far beyond the practical sampling bandwidth of the ESP32 ADC. An envelope detector converts the high-frequency signal into a slowly varying voltage that the ESP32 can measure.

**Trade-offs:**  
The detector loses frequency and protocol information. Its output represents combined broadband activity rather than a spectrum.

**Validation required:**  
Demonstrate that controlled RF activity produces a measurable detector-output change.

**Status:**  
Accepted at architecture level; circuit implementation not yet frozen.

---

## DDL-005 — Modular Subsystem Validation

**Decision:**  
The RF detector, analogue conditioning, ADC acquisition, digital processing and display shall be tested separately before integration.

**Reasoning:**  
Testing subsystems independently makes faults easier to isolate and prevents several unverified sections from failing simultaneously.

**Trade-offs:**  
Development takes longer than assembling the complete system immediately, but produces stronger evidence and reduces debugging uncertainty.

**Validation required:**  
A documented test procedure and pass/fail result for every subsystem.

**Status:**  
Accepted.

---

## DDL-006 — Serial Data Logging

**Decision:**  
The ESP32 shall output both raw and processed measurement values over USB serial.

**Reasoning:**  
Raw data is needed to evaluate noise, filtering, repeatability and processing performance. Display-only testing would hide important measurement behaviour.

**Trade-offs:**  
Firmware and data formatting become slightly more complex.

**Validation required:**  
Capture a timestamped dataset and successfully analyse it using Python.

**Status:**  
Accepted.

## DDL-007 — Firmware Development Environment

**Decision:**  
Use PlatformIO in VS Code with the Arduino ESP32 framework.

**Alternatives considered:**

- Arduino IDE
- PlatformIO with Arduino framework
- Native ESP-IDF

**Selected option:**  
PlatformIO with the Arduino framework.

**Reasoning:**  
PlatformIO stores the board and framework configuration in the repository, supports repeatable builds and integrates with the existing VS Code workflow. The Arduino framework provides sufficiently direct access to the required ESP32 peripherals without introducing the additional complexity of native ESP-IDF.

**Trade-offs:**  
The Arduino framework abstracts some low-level ESP32 behaviour and offers less direct control than ESP-IDF. That additional control is not currently required by the instrument.

**Validation required:**  
Successfully build, upload and execute a serial bring-up program on the selected ESP32 board.

**Status:** 
Accepted and frozen following successful completion of TEST-ESP-001.