#include "ECU.h"

void ECU::display_VIN() const
{
    std::cout << "VIN: " << VIN << std::endl;
}

void ECU::display_SWpartNum() const
{
    std::cout << "Software Part Number: " << SWPartNum << std::endl;
}

ECU::ECU()
    :VIN{"KAE45DE46DD"}, SWPartNum{"1.0.0"}, CurrentState{"Default"}, SerialNumber{"Serial12345"}
{

}

void ECU::processRequest(const CAN &request)
{
    unsigned char sid;
    std::cout << "Request Received" << std::endl;
    auto data = request.getData();

    if(data.empty())
    {
        std::cout << "Empty Request\n";
        return;
    }
    else
    {
        sid = data[0];
        std::cout << "SID Received : "
              << std::hex
              << static_cast<int>(sid)
              << std::endl;    
    }

    switch(sid)
    {
        case 0x22:
        {
            std::cout
                << "Read Data By Identifier"
                << std::endl;
            if(data.size() < 3)
            {
                std::cout << "Invalid Request\n";
                return;
            }
            
            unsigned char DIDHigh = data[1];
            unsigned char DIDLow  = data[2];
            std::cout << "DID Received: " <<std::hex << std::uppercase << static_cast<int>(DIDHigh) << static_cast<int>(DIDLow) << std::endl;
                
            

            if((DIDHigh == 0xF1) && (DIDLow == 0x90))
            {
                std::cout << "VIN Requested\n";
                std::cout << "VIN: " << VIN << std::endl;
            }
            else if((DIDHigh == 0xF1) && (DIDLow == 0x87))
            {
                std::cout << "Software Part Number Requested\n";
                std::cout << "Software Part Number: " << SWPartNum << std::endl;
            }
            else if((DIDHigh == 0xF1) && (DIDLow == 0x88))
            {
                if(CurrentState == "Default")
                {
                    std::cout << "Access Denied!\n" << "Hint: Change the state to extend\n";
                }
                else
                {
                    std::cout << "ECU Serial Number Requested\n";
                    std::cout << "ECU Serial Number: " << SerialNumber << std::endl;
                }
            }
            else
            {
                std::cout
                << "Unsupported DID"
                << std::endl;
            }
            break;
        }

        case 0x10:
        {
            if(data.size() < 2)
            {
                std::cout << "Invalid Request\n";
                return;
            }
            unsigned char SessionType = data[1];
            
            if(SessionType == 0x1)
            {
                CurrentState = "Default" ;
                std::cout << std::endl;
                std::cout << "Switching to Default session\n";
                std::cout << "Current Session: " << CurrentState << std::endl;
            }
            else if(SessionType == 0x3)
            {
                CurrentState = "Extended";
                std::cout << std::endl;
                std::cout << "Switching to Extended session\n";
            }
            else
            {
                std::cout << "Unsupported session\n";
            }
            break;
        }

        default:
        {
            std::cout
                << "Unsupported Service"
                << std::endl;
            break;
        }
    }
}