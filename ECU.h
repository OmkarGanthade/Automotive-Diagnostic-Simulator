#ifndef ECU_H
#define ECU_H
#include<iostream>
#include"CANMessage.h"



class ECU
{
    private:
        std::string VIN;
        std::string SWPartNum;
        std::string CurrentState;
        std::string SerialNumber;

    public:
        ECU();
        void display_VIN() const;
        void display_SWpartNum() const;
        void processRequest(const CAN &request);
        virtual ~ECU() = default;
};


#endif
