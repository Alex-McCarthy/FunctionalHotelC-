#include <iostream>
#include "Room.h"
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>



using namespace std;

string Room::returnFamilySize(){
    return _familySize;
}

string Room::returnDate(){
    return _date;
}



int Room::printBill(string date){

    if(_hasCharges){
    ofstream outputFile;
    string fileName = _name + date + "BILL" +".bill";
    outputFile.open(fileName.c_str());

    outputFile << _name + ", purchases:" << endl;

    for(int i = 0; i<_charges.size()-1; i++){
        outputFile << "Description: " + _charges[i]->returnDescription() << endl;
        outputFile << "Date: " + _charges[i]->returnDate() << endl;
        outputFile << "Amount: " + _charges[i]->returnStringAmount() << endl;
        }

    outputFile.close();
    }

    return 0;
}

int Room::addCharge(string name, string description, string amount, string date) //creates a new charge and pushes on vector
{
    Charge *charge = new Charge(name, description, amount, date);
    _charges.push_back(charge);
    _hasCharges = true;
    return 0;
}

Room::Room(string name, string familySize, string date)
{
    _name = name;
    _familySize = familySize;
    _date = date;
    _hasCharges = false;
}

Room::~Room()
{
    //dtor
}
