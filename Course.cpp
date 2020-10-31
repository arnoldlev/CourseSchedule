// Arnold Lev
// Joseph Kahale
// Emil Hovsepians
// CSIS 137 - Online
// Midterm Project (STEM Group)

#include "Course.h"
#include <iomanip>
#include <iostream>
using namespace std;

Course::Course(const string& ID, const string& name, const string& date, double units, const Date& startDate, const Date& endDate, const Time& start, const Time& end) {
	setCourseNumber(ID);
	setCourseName(name);
	setMeetingDay(date);
	setUnits(units);
	setStartDate(startDate);
	setEndDate(endDate);
	setStartTime(start);
	setEndTime(end);
}

Course::~Course() {
	cout << "This course is being deleted" << endl;
}

Course& Course::setCourseNumber(const string& num) {
	if (num.length() > 0) {
		courseNumber = num;
	} else {
		courseNumber = "N/A";
	}
	return *this;
}

Course& Course::setCourseName(const string& name) {
	if (name.length() > 0) {
		courseName = name;
	} else {
		courseName = "N/A";
	}
	return *this;
}


Course& Course::setMeetingDay(const string& day) {
	if (day.length() > 0) {
		meetingDays = day;
	} else {
		meetingDays = "N/A";
	}
	return *this;
}

Course& Course::setUnits(double unit) {
	if (unit > 0) {
		units = unit;
	} else {
		units = 0.0;
	}
	return *this;
}

Course& Course::setStartDate(const Date& start) {
	startDate.setMonth(start.getMonth()).setDay(start.getDay()).setYear(start.getYear());
	return *this;
}

Course& Course::setEndDate(const Date& end) {
	endDate.setMonth(end.getMonth()).setDay(end.getDay()).setYear(end.getYear());
	return *this;
}

Course& Course::setStartTime(const Time& start) {
	startTime.setTime(start.getHour(), start.getMinute());
	return *this;
}

Course& Course::setEndTime(const Time& end) {
	endTime.setTime(end.getHour(), end.getMinute());
	return *this;
}

const string& Course::getCourseNumber() const {
	return courseNumber;
}

const string& Course::getCourseName() const {
	return courseName;
}

const string& Course::getMeetingDays() const {
	return meetingDays;
}

double Course::getUnits() const {
	return units;
}

Date Course::getStartDate() const {
	return startDate;
}

Date Course::getEndDate() const {
	return endDate;
}

Time Course::getStartTime() const {
	return startTime;
}

Time Course::getEndTime() const {
	return endTime;
}

double Course::calcDailyDuration() const {
	return endTime - startTime;
}

ostream& operator<<(ostream& out, const Course& course) {
	out << "Course Info: \t" << course.courseNumber << " -- " << course.courseName << endl;
	out << "# of Units: \t" << fixed << setfill(' ') << setprecision(2) << course.units << endl;
	out << "Course Dates: \t" << course.startDate << " - " << course.endDate << endl;
	out << "Meeting Days: \t" << course.meetingDays << endl;
	out << "Meeting Time: \t" << course.startTime << " - " << course.endTime << endl;
	out << "Daily Duration: " << course.calcDailyDuration() << " hours" << endl; 
	return out;
}