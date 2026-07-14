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