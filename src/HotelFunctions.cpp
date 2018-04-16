#include "HotelFunctions.h"

using namespace std;

string HotelFunctions::checkIn(string line)
{



}

int HotelFunctions::charge(string line)
{
    line.erase(0, 7);
    if(line[0] == ' '){
        line.erase(0);
    }
}

int HotelFunctions::report(string line)
{
    line.erase(0, 7);
    if(line[0] == ' '){
        line.erase(0);
    }
}

int HotelFunctions::checkOut(string line)
{
    line.erase(0, 10);
    if(line[0] == ' '){
        line.erase(0);
    }
}

int HotelFunctions::bill(string line)
{
    line.erase(0, 5);
    if(line[0] == ' '){
        line.erase(0);
    }
}

HotelFunctions::HotelFunctions()
{
    //ctor
}

HotelFunctions::~HotelFunctions()
{
    //dtor
}
