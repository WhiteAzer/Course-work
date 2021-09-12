#include <iostream>
#include <Trip.h>
#include <Schedule.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
    Schedule my;
    char menu;
    do{
        system ("CLS");
        cout << "1. Load" << endl;
        cout << "2. Save" << endl;
        cout << "3. Add" << endl;
        cout << "4. Delete" << endl;
        cout << "5. View" << endl;
        cout << "6. Task" << endl;
        cout << "7. Increase" << endl;
        cout << "8. Reverse view" << endl;
        cout << "9. Exit" << endl;
        menu = getch();
        switch (menu)
        {
            case '1':
                my.load();
                system("PAUSE");
                break;
            case '2':
                my.save();
                system("PAUSE");
                break;
            case '3':
                my.push();
                system("PAUSE");
                break;
            case '4': my.pop();
                system("PAUSE");
                break;
            case '5':
                my.view();
                system("PAUSE");
                break;
            case '6':
                my.task();
                system("PAUSE");
                break;
            case '7':
                my.increase();
                system("PAUSE");
                break;
            case '8':
                my.r_view();
                system("PAUSE");
                break;
        }
    }
    while (menu!='9');

    return 0;
}
