#include "Trip.h"
#include <iomanip>

Trip::Trip()
{
    //ctor
}

Trip::~Trip()
{
    //dtor
}

void Trip::input(void)
{
    cout << "Enter train trip number > ";
    cin >> numb;
    cout << "Arrival city > ";
    cin >> city;
    cout << "Departure time > ";
    cin >> h >> m;
    cout << "Travel time > ";
    cin >> time;
    cout << "Number of tickets > ";
    cin >> tick;
}

void Trip::output(void)
{
    cout << setw(4) << numb << setw(13) << left << city << h << ":" << setw(8) << m << setw(8) << time << setw(8) << tick << endl;
}

int Trip::getH(void)
{
    return h;
}

int Trip::getM(void)
{
    return m;
}

int Trip::getNumb(void)
{
    return numb;
}
