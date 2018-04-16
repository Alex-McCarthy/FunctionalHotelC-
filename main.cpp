#include <iostream>
#include <string>
#include "string.h"
#include "Hotel.h"
#include "ReadHotel.h"
#include "ReadAct.h"

#include <vector>


using namespace std;

int main()
{
    ReadHotel *readHotel = new ReadHotel(); //this block of code reads the hotel file, puts it in a vector, creates a hotel and sorts data
    vector<string> hotelInformation = readHotel->returnHotelInfo();
    Hotel *hotel = new Hotel();
    hotel->sortHotelInformation(hotelInformation);

    ReadAct *readAct = new ReadAct(); //this block reads act file and executes its functions

    vector<string> actInformation = readAct->returnActInformation();
    hotel->sortActInformation(actInformation);

    cout<<hotel->returnTest()<<endl;
    return 0;
}
