#ifndef DTC_H
#define DTC_H
#include<iostream>
#include<vector>


class DTC
{
    friend std::ostream &operator << (std::ostream &os, const DTC &dtc);
    private:
        std::string code;
        std::string Description;

    public:
        DTC(std::string code, std::string Description);


};

void display_DTC(const std::vector<DTC> &dtcs);



#endif