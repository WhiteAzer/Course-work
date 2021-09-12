#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <Trip.h>


class Schedule
{
    public:
        Schedule();
        ~Schedule();
        int push();
        int pop();
        int view();
        void resize(int);
        void task();
        void save();
        void load();
        void increase();
        int r_view();
    private:
        Trip *arr;
        int count;
};

#endif // SCHEDULE_H
