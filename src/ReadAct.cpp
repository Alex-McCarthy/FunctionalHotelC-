#include <iostream>
#include "ReadAct.h"
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>


//reads act pushes onto a vector and returns it to the main
ReadAct::ReadAct()
{
    cout<<"reading act"<<endl;
    string commandFileName = "hotel.act";
    int lineCount = 0;

    string line;
    ifstream commandFile(commandFileName.c_str());
    if (commandFile.is_open())
    {
        while (getline(commandFile,line))
        {
            _actInformation.push_back(line);
            lineCount++;
        }
        commandFile.close();
    }
}

vector<string> ReadAct::returnActInformation()
{
    return _actInformation;
}

ReadAct::~ReadAct()
{
    //dtor
}
