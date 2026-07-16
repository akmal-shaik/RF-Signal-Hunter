# Release Notes

## v0.1 — Requirements Definition

### Objectives

- Define the project purpose.
- Establish realistic instrument capabilities.
- Define functional and engineering requirements.
- Define initial verification methods.
- Establish project documentation practices.

### Completed

- Initial project mission statement
- Functional requirements
- Performance requirements
- User-interface requirements
- Electrical and power requirements
- Mechanical requirements
- Firmware and software requirements
- Documentation requirements
- Safety requirements
- Explicit non-requirements
- Initial Design Decisions Log
- Initial Engineering Log
- Initial success criteria

### Known Unknowns

- Detector architecture
- Practical frequency response
- Sensitivity
- Detection distance
- Antenna arrangement
- Analogue gain requirements
- ADC conditioning requirements
- Display type
- Power architecture
- Final enclosure dimensions

### Release Status

Approved

## v0.2 — System Architecture

### Objectives

- Define the complete instrument architecture.
- Separate the design into independently testable subsystems.
- Define preliminary electrical and data interfaces.
- Establish the validation order.

### Completed

- System block diagram
- Subsystem definitions
- Preliminary interface definitions
- Envelope-detector architecture decision
- Serial data-logging decision
- Subsystem validation sequence

### Remaining Before v0.2 Approval

- Complete available-hardware inventory
- Confirm ESP32 board model
- Identify available display hardware
- Identify available diode types
- Review preliminary power options
- Confirm that each requirement maps to a subsystem

### Release Status

Approved

## v0.3 — Breadboard Prototype

### Status

In progress.

### Completed

- PlatformIO firmware environment created
- ESP32 board configuration recorded
- Minimal firmware application implemented
- USB upload path validated
- Serial heartbeat implemented
- ESP32 bring-up test documented

### Next Validation

- Select a safe ESP32 ADC pin
- Create a controlled voltage-divider test source
- Measure applied voltages independently
- Compare measured voltage with ESP32 ADC readings