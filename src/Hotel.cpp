#include <iostream>
#include "Hotel.h"
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <map>


using namespace std;

Hotel::Hotel()
{
    //ctor
}

/*
This method takes the vector file filled with hotelinformation and sorts it into its respective member data
*/
int Hotel::sortHotelInformation(vector<string> hotelInformation)
{
    _hotelName = hotelInformation[0];
    _streetAddress = hotelInformation[1];
    _city = hotelInformation[2];
    _state = hotelInformation[3];
    _zip = hotelInformation[4];
    _voiceNumber = hotelInformation[5];
    _faxNumber = hotelInformation[6];
    if(!(istringstream(hotelInformation[7])>>_numberOfFloors))_numberOfFloors=0;
    if(!(istringstream(hotelInformation[8])>>_roomsPerFloor))_roomsPerFloor=0;
    if(!(istringstream(hotelInformation[9])>>_maxOccupancyPerRoom))_maxOccupancyPerRoom=0;
    if(!(istringstream(hotelInformation[10])>>_peakRoomRate))_peakRoomRate=0;
    if(!(istringstream(hotelInformation[11])>>_offPeakRoomRate))_offPeakRoomRate=0;
    _peakStart = hotelInformation[12];
    _peakEnd = hotelInformation[13];
    _taxRate = hotelInformation[14];
    int loopLimit = hotelInformation.size()-15;
    for(int i = 0; i < loopLimit; i++){ //this loop iterates through the rest of vector file to fill up amenities list
        int n = 15 + i;
        _amenityList.push_back(hotelInformation[n]);
    }

    _totalRooms = _numberOfFloors *_roomsPerFloor;
    _occupiedRooms = 0;     //no names have been read in yet



    return 0;
}

int Hotel::sortActInformation(vector<string> actInformation)
{
    int loopLimit = actInformation.size()-1;
    for(int i = 0; i < loopLimit; i++){ //this massive ugly for loop sorts through the act information and performs whatever it asks line by line
        string line = actInformation[i];
        if(line[6] == 'I') //this is a check_in
            {
                cout<<"checking in"<<endl;

                line.erase(0, 9);

                if(line.at(0) == ' '){
                    line.erase(0, 1);
                }

                vector<string> words; //parses given line from act file and pushes it onto this vector

                istringstream s(line);
                string token;

                while(getline(s, token, ',')){ //string parsing
                    if(token[0] == ' '){
                        token.erase(0, 1);
                    }
                    words.push_back(token);
                }

                string name = words[0];
                string familySize = words[1];
                string date = words[2];

                if(_occupiedRooms < _totalRooms){ //instantiates room and assigns family to it
                    Room *room= new Room(name, familySize, date);
                    _rooms[name] = room;
                    _occupiedRooms++;
                }
            }
            else if(line[2] == 'A') //this is a charge
            {
                cout<<"adding a charge"<<endl;

                line.erase(0, 7); //removing front of act string
                if(line.at(0) == ' '){
                    line.erase(0, 1);
                }

                vector<string> words;

                istringstream s(line);
                string token;
                while(getline(s, token, ',')){
                    if(token[0] == ' '){
                        token.erase(0, 1);
                    }
                    words.push_back(token);
                }

                string name = words[0];
                string description = words[1];
                string amount = words[2];
                string date = words[3];

                if(_rooms[name]){
                    _rooms[name]->addCharge(name, description, amount, date);
                }else{
                    Charge *charge = new Charge(name, description, amount, date);
                    cout<<"unregistered guest alert amount:" + charge->returnStringAmount() <<endl;
                    _unregisteredCharges.push_back(charge); //adds unregistered guest charge to vector
                }

            }
            else if(line.at(0) == 'R') //this is a report
            {
                cout<<"writing a report"<<endl;

                line.erase(0, 7);
                if(line.at(0) == ' '){
                    line.erase(0, 1);
                }
                string reportDate = line;

                ofstream outputFile;
                string fileName = _hotelName + reportDate + "REPORT" +".rprt"; //creates .rprt file
                outputFile.open(fileName.c_str());

                outputFile << _hotelName + ", guests:" << endl;


                for(map<string, Room*>::iterator it=_rooms.begin(); it!=_rooms.end(); ++it){ //iterates through map to print occupants

                        Room *room = it->second;
                        string theJawn = room->returnFamilySize();
                        cout << "Name: " + it->first + " Size: " + theJawn << endl;
                        outputFile << "Name: " + it->first + " Size: " + theJawn << endl;

                        it++;

                }

                outputFile<<"Unregistered guest charges: "<<endl;

                for(int i = 0; i<=_unregisteredCharges.size()-1; i++){
                    cout<<"Date: " + _unregisteredCharges[i]->returnDate() + " Name: " + _unregisteredCharges[i]->returnName() + " Description: " + _unregisteredCharges[i]->returnDescription() + " Amount: " + _unregisteredCharges[i]->returnStringAmount()<<endl;
                    outputFile << "Date: " + _unregisteredCharges[i]->returnDate() + " Name: " + _unregisteredCharges[i]->returnName() + " Description: " + _unregisteredCharges[i]->returnDescription() + " Amount: " + _unregisteredCharges[i]->returnStringAmount()<< endl;
                }

                outputFile.close();
            }
            else if(line[6] == 'O') //this is a check_out
            {


                line.erase(0, 10);
                if(line.at(0) == ' '){
                    line.erase(0, 1);
                }

                vector<string> words;

                istringstream s(line);
                string token;
                while(getline(s, token, ',')){
                    if(token[0] == ' '){
                        token.erase(0, 1);
                    }
                    words.push_back(token);
                }

                string name = words[0];
                string date = words[1];

                cout<<"writing a check_out for name: " + name<<endl;
                if(_rooms[name]){
                    ofstream outputFile;
                    string fileName = name + date  +".bill";
                    outputFile.open(fileName.c_str());

                    outputFile<< "Hotel name: " + _hotelName<<endl;
                    outputFile<< "Street Address: " + _streetAddress<<endl;
                    outputFile<< "City: " + _city<<endl;
                    outputFile<< "State: " + _state<<endl;
                    outputFile<< "Zip: " + _zip<<endl;
                    outputFile<< "Guest name: " + name<<endl;
                    outputFile<< "Check in date: " + _rooms[name]->returnDate()<<endl;
                    outputFile<< "Check out date: " + date<<endl;
                    _rooms[name]->printBill(date);
                    cout<<"erasing guest name"<<endl;
                    _rooms.erase(name);
                    --_occupiedRooms;
                }
            }

            else if(line[0] == 'B') //this is a bill
            {
                cout<<"writing a bill"<<endl;
                line.erase(0, 5);
                if(line[0] == ' '){
                    line.erase(0);
                }
                vector<string> words;

                istringstream s(line);
                string token;

                while(getline(s, token, ',')){
                    if(token[0] == ' '){
                        token.erase(0);
                    }
                    words.push_back(token);
                }

                string name = words[0];
                string date = words[2];

                if(_rooms[name]){
                    _rooms[name]->printBill(date);
                }
            }
            else{
                cout<<"'Hotel.act' file syntax incorrect, or something went wrong. :("<<endl;
            }
        }
        return 0;
}



int Hotel::returnTest()
{
    return _totalRooms;
}

Hotel::~Hotel()
{
    //dtor
}
