#ifndef HOTELFUNCTIONS_H
#define HOTELFUNCTIONS_H
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;


class HotelFunctions
{
    public:
        HotelFunctions();
        string checkIn(string line);
        int report(string line);
        int bill(string line);
        string checkOut(string line);
        string charge(string line);
        virtual ~HotelFunctions();
    private:

};

#endif // HOTELFUNCTIONS_H
