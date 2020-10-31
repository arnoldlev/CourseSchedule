// Arnold Lev
// Joseph Kahale
// Emil Hovsepians
// CSIS 137 - Online
// Midterm Project (STEM Group)

#include "CourseSchedule.h"
#include "Course.h"
#include <iostream>
using namespace std;

CourseSchedule::CourseSchedule(const string& studentName, const Semester& term, int maxCourse) {
	setStudentName(studentName);
	maxSize = maxCourse;
	numCourses = 0;
	courses = new Course[maxCourse];
	semester.setSemesterName(term.getSemesterName()).setStartDate(term.getStartDate()).setEndDate(term.getEndDate());
}

CourseSchedule::~CourseSchedule() {
	delete[] courses;
}

bool CourseSchedule::checkDates(const Semester& sem, const Date& start, const Date& end) {
	if (start >= sem.getStartDate() && start < sem.getEndDate() && end <= sem.getEndDate() && end > sem.getStartDate()) {
		return true;
	}
	return false;
}

bool CourseSchedule::addCourse(const Course& course) {
	if (checkDates(semester, course.getStartDate(), course.getEndDate())) {
		courses[numCourses] = course;
		numCourses++;
		return true;
	}
	return false;
}

bool CourseSchedule::removeCourse(const string& courseID) {
	int index = -1;
	for (int i = 0; i < numCourses; i++) {
		if (courses[i].getCourseNumber() == courseID) {
			index = i;
		 }
	}
	if (index != -1) {
		int lastCourse = numCourses - 1;
		courses[index] = courses[lastCourse];
		numCourses--;
		return true;
	} else {
		return false;
	}
}

const string& CourseSchedule::getStudentName() const {
	return studentName;
}

Semester CourseSchedule::getSemester() const {
	return semester;
}

int CourseSchedule::getNumCourses() const {
	return numCourses;
}

CourseSchedule& CourseSchedule::setStudentName(const string& name) {
	if (name.length() > 0) {
		studentName = name;
	} else {
		studentName = "N/A";
	}
	return *this;
}

ostream& operator<<(ostream& out, const CourseSchedule& sched) {
	out << "CLASS SCHEDULE\n-----------------------" << endl;
	out << "Name: " << sched.studentName << endl;
	out << "Semester: " << sched.semester << endl;
	out << "Number of Classes: " << sched.numCourses << endl;
	out << "-----------------------------------------" << endl;
	for(int i = 0; i < sched.numCourses; i++){
		out << sched.courses[i];
		out << endl;
	}
	return out;
}