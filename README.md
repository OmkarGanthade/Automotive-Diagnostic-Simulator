# Automotive-Diagnostic-Simulator
A C++ automotive diagnostic simulator demonstrating OOP, CAN message abstraction, and basic UDS services. Features ECU data access (VIN, software part number, serial number), session control (0x10), Read Data By Identifier (0x22), DTC management, session-based security, input validation, and a modular multi-file design.


## Overview
A C++ based Automotive Diagnostic Simulator implementing
basic UDS services over simulated CAN messages.

## Features
- Read VIN (F190)
- Read Software Part Number (F187)
- Read ECU Serial Number (F188)
- Diagnostic Session Control (0x10)
- DTC Management
- Session-based Access Control

## Project Structure
main.cpp
ECU.h / ECU.cpp
CANMessage.h / CANMessage.cpp
DTC.h / DTC.cpp
utility.h

## Sample Requests
22 F1 90 -> VIN
22 F1 87 -> SW Part Number
22 F1 88 -> ECU Serial Number
10 01 -> Default Session
10 03 -> Extended Session

## Concepts Used
- OOP
- STL Vector
- Header Guards
- Operator Overloading
- CAN Abstraction
- UDS Service Processing
