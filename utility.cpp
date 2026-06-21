#include<iostream>
#include<limits>
#include"utility.h"


ECU airbagECU;
CAN VINRequest(0x7E0, {0x22, 0xF1, 0x90});
CAN SWRequest(0x7E0, {0x22, 0xF1, 0x87});
CAN DefaultSessionRequest(0x7E0, {0x10, 0x1});
CAN ExtendedSessionRequest(0x7E0, {0x10, 0x3});
CAN SerialNumber(0x7E0, {0x22, 0xF1, 0x88});

void DIDSelection()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Supported DIDs: \n"
              << "VIN - F190\n" << "Software Part Number - F187\n"  << "ECU Serial Number - F188\n"
              << "0: Back to Main Menu\n";
    std::cout << "Enter DID base on above choices\n";

    std::string input;
    
    do
    {
        std::cout << "Enter DID: ";
        std::getline(std::cin, input);
    if((input == "F190") || (input == "F1 90"))
    {
        airbagECU.processRequest(VINRequest);
        std::cout << "===============================" << std::endl;
        
    }
    else if ((input == "F187") || (input == "F1 87"))
    {
        airbagECU.processRequest(SWRequest);
        std::cout << "===============================" << std::endl;
        
    }
    else if((input == "F188") || (input == "F1 88"))
    {
        airbagECU.processRequest(SerialNumber);
        std::cout << "===============================" << std::endl;
        
    }
    else
    {
        if(input == "0")
        {
            std::cout << "Redirecting to Main menu...\n";
            std::cout << "====================================";
        }
        else
            std::cout << "Invalid DID\n" << "Re-enter your choice\n";
            std::cout << "===============================" << std::endl;
    }
}while(input != "0");
    
}