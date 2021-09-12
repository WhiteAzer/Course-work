#include "Schedule.h"
#include <iomanip>

Schedule::Schedule()
{
    arr = NULL;
    count = 0;
}

Schedule::~Schedule()
{
    if (arr)
    delete [] arr;
}

int Schedule::push()
{
    int n;
    if (!arr)
    {
        count = 1;
        arr = new Trip[count];
        arr[0].input();
    }
    else
    {
        resize(++count);
        do {
            cout << "Enter item number " ;
            cin >> n;
        } while (n > count);
        n--;
        for (int i = count - 2; i >= n; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[n].input();
        return count;
    }
}

int Schedule::pop()
{
    int n;
    if (count <= 0)
        return 0;
    if ((count--) > 0)
    {
        do {
            cout << "Enter item number " ;
            cin >> n;
        } while (n > count + 1);
        n--;
        for (int i = n; i < count + 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        resize(count);
    }
    else
        delete [] arr;
}

int Schedule::view()
{
    if (count == 0)
    {
        cout << "Array is empty" << endl;
    }
    else
    {
        cout << left << setw(4) << "N" << setw(13) << "City" << setw(11) <<  "Departure"  << setw(8) << "Time" << setw(8) << "Tickets" << endl;
        for (int i = 0; i<count; i++)
        arr[i].output();
    }
}

void Schedule::resize(int b)
{
    if (arr)
    {
        Trip *newarr = new Trip[b];
        for (int i = 0; i<count && i<b; i++)
        {
            newarr[i] = arr[i];
        }
        delete [] arr;
        arr = newarr;
    }
    else
        arr = new Trip[b];
}

void Schedule::task()
{
    if (count == 0)
    {
        cout << "Array is empty" << endl;
        return;
    }
    int h1, m1, h2, m2, sum1, sum2, sum3;
    cout << "Enter minimal time " << endl;
    cin >> h1 >> m1;
    sum1 = h1 * 60 + m1;
    cout << "Enter maximum time " << endl;
    cin >> h2 >> m2;
    sum2 = h2 * 60 + m2;
    for (int i = 0; i < count; i++)
    {
        sum3 = arr[i].getH() * 60 + arr[i].getM();
        if ((sum3 >= sum1) && (sum3 <= sum2))
            arr[i].output();
    }
}

void Schedule::save()
{
    ofstream out("output.bin", ios::binary);
    for (int i=0; i<count; i++)
    {
        out.write((char*)&arr[i],sizeof(Trip));
    }
}

void Schedule::load()
{
    ifstream in("output.bin", ios::binary);
    in.seekg (0, ios::end);
    count = in.tellg() / sizeof(Trip);
    in.seekg (0, ios::beg);
    resize(count);
    for (int i=0; i<count; i++)
    {
        in.read((char*)&arr[i],sizeof(Trip));
    }
}

void Schedule::increase()
{
    Trip x;
    for (int i=0; i<count; i++)
    {
        for (int j=0; j<count; j++)
        {
            if (arr[i].getNumb() < arr[j].getNumb())
            {
                x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
    }
}

int Schedule::r_view()
{
    if (count == 0)
    {
        cout << "Array is empty" << endl;
        return -1;
    }
    else
    {
        cout << left << setw(4) << "N" << setw(13) << "City" << setw(11) <<  "Departure"  << setw(8) << "Time" << setw(8) << "Tickets" << endl;
        for (int i = count - 1; i >= 0; i--)
        arr[i].output();
    }
}

