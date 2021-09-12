#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include <fstream>

using namespace std;

class Trip
{
    public:
        Trip();
        ~Trip();
        void input(void);
        void output(void);
        int getH(void);
        int getM(void);
        int getNumb(void);
    private:
        int numb;
        char city[30];
        int h;
        int m;
        int time;
        int tick;
};

#endif // TRIP_H
