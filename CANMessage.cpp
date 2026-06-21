#include"CANMessage.h"


CAN::CAN(int ID, std::vector<unsigned char> data)
    :ID{ID}, data{data}
{

}

void CAN::displaymsg() const
{
    std::cout << "CAN ID: " << "0x" << std::hex << std::uppercase << ID << " " << std::endl;
    std::cout << "Data: " ;
    for(auto msg:data)
    {
        std::cout << std::hex << std::uppercase << "0x" << static_cast<int>(msg) << " ";
    }
    std::cout << std::endl;
}

const std::vector<unsigned char>& CAN::getData() const
{
    return data;
}