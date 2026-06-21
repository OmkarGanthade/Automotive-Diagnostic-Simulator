#include "DTC.h"

DTC::DTC(std::string code, std::string Description)
    :code{code}, Description{Description}
{

}

std::ostream &operator << (std::ostream &os, const DTC &dtc)
{
    os << dtc.code << "    " << dtc.Description;
    return os;
}

void display_DTC(const std::vector<DTC> &dtcs)
{
    for(const auto &dtc:dtcs)
    {
        std::cout << dtc << std::endl;
    }
}