#include <iostream>
#ifndef ROOM_H
#define ROOM_H
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "Charge.h"

using namespace std;


class Room
{
    public:
        string returnFamilySize();
        Room(string name, string familySize, string date);
        addCharge(string name, string description, string amount, string date);
        printBill(string date);
        string returnDate();
        vector<Charge*> returnCharges();
        virtual ~Room();
    private:
        bool _hasCharges;
        string _name;
        string _familySize;
        string _date;
        vector<Charge*> _charges;
};

#endif // ROOM_H
