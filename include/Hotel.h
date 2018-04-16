#include <iostream>
#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include "Room.h"
#include <utility>
#include "Charge.h"

using namespace std;

class Hotel
{
    public:
        Hotel();
        sortHotelInformation(vector<string> hotelInformation);
        sortActInformation(vector<string> actInformation);
        virtual ~Hotel();
        int returnTest();
    private:
        string _hotelName;
        string _streetAddress;
        string _city;
        string _state;
        string _zip;
        string _voiceNumber;
        string _faxNumber;
        int _numberOfFloors;
        int _roomsPerFloor;
        int _maxOccupancyPerRoom;
        int _peakRoomRate;
        int _offPeakRoomRate;
        string _peakStart;
        string _peakEnd;
        string _taxRate;
        vector<string> _amenityList;

        int _totalRooms;//this is how i save families to rooms
        int _occupiedRooms;
        map<string, Room*> _rooms;
        vector<Charge*> _unregisteredCharges;

};

#endif // HOTEL_H
