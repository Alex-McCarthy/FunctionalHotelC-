#include <iostream>
#ifndef CHARGE_H
#define CHARGE_H
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Charge
{
    public:
        string returnDescription();
        string returnStringAmount();
        double returnDoubleAmount();
        string returnDate();
        string returnName();
        Charge(string name, string description, string amount, string date);
        virtual ~Charge();
    private:
        string _name;
        string _description;
        double _amount;
        string _date;
};

#endif // CHARGE_H
