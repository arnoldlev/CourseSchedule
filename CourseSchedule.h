// Arnold Lev
// Joseph Kahale
// Emil Hovsepians
// CSIS 137 - Online
// Midterm Project (STEM Group)


#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H

#include "Semester.h"
#include "Course.h"
#include<iostream>
#include<string>
using namespace std;

class CourseSchedule {

	friend ostream& operator<<(ostream&, const CourseSchedule&);

	private:
		string studentName;
		Semester semester;
		Course* courses;
		int maxSize;
		int numCourses;
		bool checkDates(const Semester&, const Date&, const Date&);
	public:
		CourseSchedule(const string&, const Semester&, int);
		~CourseSchedule();

		const CourseSchedule& operator=(const CourseSchedule&) = delete;
		CourseSchedule(const CourseSchedule&) = delete;

		bool addCourse(const Course&);
		bool removeCourse(const string&);
		
		const string& getStudentName() const;
		Semester getSemester() const;
		int getNumCourses() const;

		CourseSchedule& setStudentName(const string&);

};


#endif