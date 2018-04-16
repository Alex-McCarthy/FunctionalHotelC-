#include <iostream>
#include "ReadHotel.h"
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

//reads through hotel file and pushes onto vector/sends to main
ReadHotel::ReadHotel()
{
    string commandFileName = "hotel.conf";
    int lineCount = 0;

    string line;
    ifstream commandFile(commandFileName.c_str());
    if (commandFile.is_open())
    {
        while (getline(commandFile,line))
        {
            _hotelInformation.push_back(line);
            lineCount++;
        }
        commandFile.close();
    }
}

vector<string> ReadHotel::returnHotelInfo()
{
    return _hotelInformation;
}

ReadHotel::~ReadHotel()
{
    //dtor
}
