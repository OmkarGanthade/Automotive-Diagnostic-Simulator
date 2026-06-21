#ifndef CANMESSAGE_H
#define CANMESSAGE_H
#include<iostream>
#include<vector>

class CAN
{
    private:
        int ID;
        std::vector <unsigned char> data;

    public:
        CAN(int ID, std::vector<unsigned char> data);
        void displaymsg() const;
        const std::vector<unsigned char>& getData() const;
        virtual ~CAN() = default;

};

#endif