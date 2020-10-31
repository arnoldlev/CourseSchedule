// Arnold Lev
// Joseph Kahale
// Emil Hovsepians
// CSIS 137 - Online
// Midterm Project (STEM Group)

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include "Time.h"

Time::Time(int hour, int minute) {
    setTime(hour, minute);
}

Time& Time::setTime(int hour, int minute) {
    setHour(hour);
    setMinute(minute);
    return *this;
}

Time& Time::setHour(int h) {
    hour = (h >= 0 && h < 24) ? h : -1;   // For input validation 
    return *this;
}

Time& Time::setMinute(int m) {
    minute = (m >= 0 && m <= 59) ? m : -1;   // For input validation 
    return *this;
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

void Time::convert(const string& type) {
    if (type == "PM" && hour >= 1 && hour <= 11) { 
        setHour(getHour() + 12);
    } else if (type == "AM" && hour == 12) {
        setHour(0);
    }
}

// Input Validation Function
bool Time::isInvalid() const {
    return hour == -1 || minute == -1;
}

double Time::operator-(const Time& time2) const {
    double decimal;
    if (time == 0) {
        decimal = abs(24 - time2.hour);
    } else if (time2.hour == 0) {
        decimal = abs(hour - 24);
    } else {
        decimal = abs(hour - time2.hour);
    }
    decimal += (double) abs((((double) minute - time2.minute) / 60.0));
    return ceil(decimal * 100.0) / 100.0;
}

istream& operator>>(istream& in, Time& time) {
    int hour, minute;
    string type;
    in >> setfill('0') >> setw(2) >> hour;
    cin.ignore();
    in >> setfill('0') >> setw(2) >> minute;
    cin.ignore(1);
    getline(in, type);

    if (type == "AM" || type == "PM" || type == "am" || type == "pm") {
        time.setHour(hour).setMinute(minute);
        time.convert(type);
    } else {
        time.setTime(-1, -1); // For input validation 
    }
    return in;
}

ostream& operator<<(ostream& out, const Time& time) {
    cout << ((time.getHour() == 0 || time.getHour() == 12) ? 12 : time.getHour() % 12) << ":"
        << setfill('0') << setw(2) << time.getMinute() << " "
        << setw(2) << (time.getHour() < 12 ? "AM" : "PM");
    return out;
}