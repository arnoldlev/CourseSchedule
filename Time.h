// Arnold Lev
// Joseph Kahale
// Emil Hovsepians
// CSIS 137 - Online
// Midterm Project (STEM Group)

#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time {

    friend ostream& operator<<(ostream&, const Time&);
    friend istream& operator>>(istream&, Time&);

    private:
        int hour;  
        int minute; 
        void convert(const string&);
    public:
        Time(int = 0, int = 0);

        Time& setTime(int, int);
        Time& setHour(int);
        Time& setMinute(int);

        int getHour() const;
        int getMinute() const;

        double operator-(const Time&) const;

        bool isInvalid() const;
};

#endif
