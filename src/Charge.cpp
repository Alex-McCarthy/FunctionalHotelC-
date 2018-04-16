#include "Charge.h"


string Charge::returnDescription(){
    return _description;
}

string Charge::returnStringAmount(){
    stringstream ss;
    ss << _amount;
    string stringAmount = ss.str();
    return stringAmount;
}

double Charge::returnDoubleAmount(){
    return _amount;
}

string Charge::returnDate(){
    return _date;
}

string Charge::returnName(){
    return _name;
}

Charge::Charge(string name, string description, string amount, string date) //instantiates a charge
{
    _name = name;
    _description = description;
    stringstream convert(amount);
    convert>>_amount;
    cout<<"this is the amount inside of the charge:";
    cout<<_amount<<endl;
    _date = date;
}

Charge::~Charge()
{
    //dtor
}
