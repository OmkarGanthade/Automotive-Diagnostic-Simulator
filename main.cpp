// #include<iostream>
// #include<vector>
#include<limits>
// #include "DTC.h"
// #include "ECU.h"
// #include "CANMessage.h"
#include "utility.h"



int main()
{
    int choice{};
    std::vector <DTC> dtcs;

    dtcs.push_back(DTC("B1001", "Airbag Squib Fault"));
    dtcs.push_back(DTC("B1002", "Crash Sensor Fault"));
    std::cout << "========================================\n"
              << "    Automotive Diagnostic Simulator\n"
              << "========================================\n";
    while(choice!=7)
    {
        std::cout << "Select your choice from below\n";
        std::cout << "1. Read VIN\n" << "2. Read SW Part Number\n" << "3. Read DTCs\n" << "4. Read DIDs\n" 
                  << "5. Default Session\n" << "6. Extended Session\n"  << "7. Exit\n";
        std::cout << "Enter Choice: ";
        if(!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input\n";
            continue;
        }
        switch (choice)
        {
            case 1:
                std::cout << "===============================" << std::endl;
                airbagECU.display_VIN();
                std::cout << "===============================" << std::endl;
                break;
    
            case 2:
                std::cout << "===============================" << std::endl;
                airbagECU.display_SWpartNum(); 
                std::cout << "===============================" << std::endl;
                break; 
            
            case 3:
                std::cout << "===============================" << std::endl;
                std::cout << "code" << "    " << "Description" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                display_DTC(dtcs);
                std::cout << "===============================" << std::endl;
                break;

            case 4:
                DIDSelection();
                
                break;

            case 5:
                std::cout << "===============================" << std::endl;
                airbagECU.processRequest(DefaultSessionRequest);
                std::cout << "===============================" << std::endl;
                break;
            
            case 6:
                std::cout << "===============================" << std::endl;
                airbagECU.processRequest(ExtendedSessionRequest);
                std::cout << "===============================" << std::endl;
                break;

            case 7:
                std::cout << "===============================" << std::endl;
                std::cout << "Exiting.....\n";
                std::cout << "===============================" << std::endl;
                break;

            default:
                std::cout << "===============================" << std::endl;
                std::cout << "Invalid Choice\nRe-enter the choice\n";
                std::cout << "===============================" << std::endl;
                break;
        }
    }

      

}