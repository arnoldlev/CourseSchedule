// Arnold Lev
// Joseph Kahale
// Emil Hovsepians
// CSIS 137 - Online
// Midterm Project (STEM Group)

#ifndef SEMESTER_H
#define SEMESTER_H
#include <string>
#include "Date.h"
#include <iostream>
using namespace std;

class Semester {

	friend istream& operator>>(istream&, Semester&);
	friend ostream& operator<<(ostream&, const Semester&);

	private:
		 string semesterName;
		 Date start;
		 Date end;
	public:
		Semester(const string& = "N/A", const Date& = Date(), const Date& = Date());

		const string& getSemesterName() const;
		Date getStartDate() const;
		Date getEndDate() const;

		Semester& setSemesterName(const string&);
		Semester& setStartDate(const Date&);
		Semester& setEndDate(const Date&);
};


#endif