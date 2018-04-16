#include <iostream>
#ifndef READHOTEL_H
#define READHOTEL_H
#include <vector>

using namespace std;

class ReadHotel
{
    public:
        ReadHotel();
        virtual ~ReadHotel();
        vector<string> returnHotelInfo();
    private:
        vector<string> _hotelInformation;
};

#endif // READHOTEL_H
