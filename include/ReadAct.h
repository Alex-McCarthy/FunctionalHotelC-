#include <iostream>
#ifndef READACT_H
#define READACT_H
#include <vector>

using namespace std;


class ReadAct
{
    public:
        ReadAct();
        virtual ~ReadAct();
        vector<string> returnActInformation();
    private:
        vector<string> _actInformation;
};

#endif // READACT_H
