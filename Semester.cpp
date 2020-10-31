// Arnold Lev
// Joseph Kahale
// Emil Hovsepians
// CSIS 137 - Online
// Midterm Project (STEM Group)

#include "Semester.h"
#include <iostream>
#include <string>
using namespace std;

Semester::Semester(const string& name, const Date& start, const Date& end) {
	setSemesterName(name);
	setStartDate(start);
	setEndDate(end);
}

const string& Semester::getSemesterName() const {
	return semesterName;
}

Date Semester::getStartDate() const {
	return start;
}

Date Semester::getEndDate() const {
	return end;
}

Semester& Semester::setSemesterName(const string& name) {
	if (name.length() > 0) {
		semesterName = name;
	}
	else {
		semesterName = "N/A";
	}
	return *this;
}

Semester& Semester::setStartDate(const Date& start) {
	this->start.setMonth(start.getMonth()).setDay(start.getDay()).setYear(start.getYear());
	return *this;
}

Semester& Semester::setEndDate(const Date& end) {
	this->end.setMonth(end.getMonth()).setDay(end.getDay()).setYear(end.getYear());
	return *this;
}


ostream& operator<<(ostream& out, const Semester& sem) {
	out << sem.semesterName << " (" << sem.start << "-" << sem.end << ")";
	return out;
}

istream& operator>>(istream& in, Semester& sem) {
	getline(in, sem.semesterName, '-');
	in >> sem.start;
	in.ignore();
	in >> sem.end;
	return in;
}