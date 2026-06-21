#ifndef UTILITY_H
#define UTILITY_H

#include<iostream>
#include<vector>
#include "DTC.h"
#include "ECU.h"
#include "CANMessage.h"

extern ECU airbagECU;
extern CAN VINRequest;
extern CAN SWRequest;
extern CAN DefaultSessionRequest;
extern CAN ExtendedSessionRequest;
extern CAN SerialNumber;


void DIDSelection();



#endif