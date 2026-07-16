# Engineering Log

## Session 001 — Requirements Definition

**Project version:** v0.1 approved baseline

### Objective

Define the intended capabilities, constraints, verification methods and limitations of the RF Signal Hunter before selecting the detailed architecture.

### Work completed

- Created the initial repository structure.
- Defined the project mission statement.
- Defined functional requirements.
- Defined performance requirements.
- Defined electrical, mechanical, firmware and documentation requirements.
- Defined explicit non-requirements.
- Established initial project success criteria.
- Created the first Design Decisions Log entries.

### Implementation

No hardware or firmware was implemented during this session.

This was intentional because the project requirements must be understood before selecting components or designing circuits.

### Testing

No electrical testing was performed.

The requirements were reviewed for:

- Clarity
- Testability
- Realistic scope
- Honest capability claims
- Compatibility with the intended handheld final product

### Results

A draft requirements specification was produced for v0.1.

Several performance quantities remain TBD, including:

- Practical sensitivity
- Useful detection distance
- Effective frequency response
- Required sampling rate
- Display update rate
- Final power source
- Enclosure dimensions

These values will be determined through architecture analysis and experimental testing rather than guessed.

### Lessons Learned

- A broadband RF detector measures a combined response to received RF energy; it does not automatically reveal frequency.
- Absolute units require calibration and a characterised signal path.
- Requirements should describe both desired behaviour and the method used to prove that behaviour.
- Explicit non-requirements help prevent uncontrolled project expansion.

### Next controlled action

Review and approve the v0.1 requirements before beginning the v0.2 system architecture.

## Session 002 — System Architecture

**Project version:** v0.2 approved at system-architecture level

### Objective

Define the complete high-level architecture and divide the instrument into independently testable subsystems.

### Work completed

- Created the system block diagram.
- Defined the responsibilities of each subsystem.
- Defined preliminary subsystem interfaces.
- Selected an envelope-detection architecture.
- Established a subsystem validation order.
- Began an inventory of available hardware.

### Engineering reasoning

The ESP32 cannot directly sample the intended RF carrier frequencies using its normal ADC. The RF signal must therefore be converted into a low-frequency envelope before digital acquisition.

The architecture separates RF detection, analogue conditioning, ADC acquisition, processing and display so that each function can be validated independently.

### Testing

No electrical testing was performed during this session.

The architecture was reviewed against:

- Project requirements
- ESP32 compatibility
- Breadboard testability
- Final handheld integration
- Documentation requirements
- Scope limitations

### Results

A preliminary modular architecture was produced.

Exact circuit topology, detector diode, antenna design, display interface and power arrangement remain TBD pending hardware inventory and component evaluation.

### Lessons learned

- The RF carrier and its envelope are different signals.
- A detector can make high-frequency activity measurable without preserving frequency information.
- Defining electrical interfaces early reduces integration risk.
- Raw data logging is essential for validating signal processing.

### Next controlled action

Complete the hardware inventory and select the preliminary components for the first controlled ESP32 ADC experiment.

## Session 003 — Hardware Inventory and Architecture Review

**Project version:** v0.2 approved at system-architecture level

### Objective

Identify the hardware already available and determine whether the proposed system architecture can be developed using existing equipment.

### Work completed

- Inspected the available ESP32 development board.
- Recorded available prototyping and measurement equipment.
- Identified available display, diode, resistor and capacitor components where possible.
- Added initial architecture constraints.

### Testing

Only basic visual inspection and previously known operating status were recorded.

No RF detector circuit was constructed and no unverified component was connected to the ESP32.

### Results

The hardware inventory was updated using verified component markings where available.

Unidentified components remain recorded as unknown rather than being assigned assumed specifications.

### Lessons learned

- A component's package appearance is not sufficient evidence of its electrical characteristics.
- Knowing the exact development-board version is important because ESP32 pin capabilities differ between variants.
- Hardware selection must account for both electrical function and final-system integration.

### Next controlled action

Review the inventory, confirm the available measurement equipment and approve the v0.2 system architecture before beginning ESP32 bring-up and ADC characterisation.

## Session 004 — ESP32 Bring-Up and Serial Verification

**Project version:** v0.3 draft

### Objective

Validate the firmware development environment, USB programming interface, ESP32 execution and serial data path before beginning ADC experiments.

### Implementation

- Configured PlatformIO for the ESP32 DEVKIT V1.
- Created a minimal Arduino-framework firmware application.
- Implemented a timestamped one-second heartbeat.
- Uploaded the firmware to the selected ESP32 board.
- Observed output through the serial monitor.

### Testing

TEST-ESP-001 verified:

- Firmware compilation
- USB upload
- Program execution
- Continuous serial output
- Approximate heartbeat timing
- Reset behaviour
- USB reconnection behaviour

### Results

**Overall result:** PASS

COM6 was used and no anomalies were observed.

### Lessons Learned

- Successful compilation alone does not prove that the hardware executes correctly.
- A heartbeat provides evidence of continuous firmware operation.
- Identifying individual physical boards makes later failures and measurements traceable.
- A known-good serial path will later allow raw ADC measurements to be captured without relying solely on a display.

### Next Controlled Action

Characterise the ESP32 ADC using controlled DC input voltages after TEST-ESP-001 passes.