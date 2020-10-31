// Arnold Lev
// Joseph Kahale
// Emil Hovsepians
// CSIS 137 - Online
// Midterm Project (STEM Group)

#include "Time.h"
#include "Date.h"
#include "Course.h"
#include "Semester.h"
#include "CourseSchedule.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	int maxClasses;

	string courseNum, courseName, courseMeeting;
	int courseUnits;
	Time startTime, endTime;
	Date startDate, endDate;

	char selection;
	string courseID;

	Semester semester;

	cout << "Full Student Name: " << endl;
	getline(cin, name);

	cout << "Semester Information (Name & Dates):" << endl;
	cout << "(EX: Fall 2020-8/31/2020 12/15/2020)" << endl;
	cin >> semester;

	while (semester.getEndDate().isInvalid() || semester.getStartDate().isInvalid()) {
		cout << "Error: You have entered invalid dates! Try again" << endl;
		cin >> semester;
	}

	while (semester.getEndDate() < semester.getStartDate()) {
		cout << "Error: Semester end date cannot be before start date! Try again" << endl;
		cin >> semester;
	}
	cin.ignore();

	cout << "Enter your maximum # of classes: " << endl;
	cin >> maxClasses;
	while (maxClasses < 1) {
		cout << "Error: Please enter a value greater than 0!" << endl;
		cin >> maxClasses;
	}

	CourseSchedule courseSched(name, semester, maxClasses);
	
	do {
		cout << endl << "COURSE ENTRY MENU FOR:\t" << semester << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "1) Enter a new course" << endl;
		cout << "2) Remove a course" << endl;
		cout << "3) Print a Semester Schedule" << endl;
		cout << "q) Quit the program" << endl;

		cin >> selection;
		cin.ignore();

		if (selection == '1') {
			if (courseSched.getNumCourses() == maxClasses) {
				cout << "Error: You have entered the maximum amount of courses!" << endl;
			} else {
				cout << "Course Number: (EX: CSIS 112)" << endl;
				getline(cin, courseNum); 

				cout << "Course Name: (EX: Java)" << endl;
				getline(cin, courseName);

				cout << "Meeting Dates: (EX: MWF)" << endl;
				getline(cin, courseMeeting);

				cout << "# Of Units: (EX: 3)" << endl;
				cin >> courseUnits;
				while (courseUnits < 1){
					cout << "Error: Please enter a value greater than 0!" << endl;
					cin >> courseUnits;
				}

				cin.ignore();

				cout << "Course Start Time: (EX: 3:00 PM)" << endl;
				cin >> startTime;
				while (startTime.isInvalid()) {
					cout << "Error: Please enter a valid time (HH:MM PM/AM)" << endl;
					cin >> startTime;
				}

				cout << "Course End Time: (EX: 3:00 PM)" << endl;
				cin >> endTime;
				while (endTime.isInvalid()) {
					cout << "Error: Please enter a valid time (HH:MM PM/AM)" << endl;
					cin >> endTime;
				}

				cout << "Course Start Date: (EX: 1/1/1990)" << endl;
				cin >> startDate;
				while (startDate.isInvalid()) {
					cout << "Error: Please enter a valid date: (MM/DD/YYYY) " << endl;
					cin >> startDate;
				}

				cout << "Course End Date: (EX: 1/1/1990) " << endl;
				cin >> endDate;
				while (endDate.isInvalid()) {
					cout << "Error: Please enter a valid date: (MM/DD/YYYY) " << endl;
					cin >> endDate;
				}

				Course course(courseNum, courseName, courseMeeting, courseUnits, startDate, endDate, startTime, endTime);
				while (!courseSched.addCourse(course)) {
					cout << "Error: The course you entered is not within the semester dates! Please re-enter the dates" << endl;

					cout << "Course Start Date: (EX: 1/1/1990)" << endl;
					cin >> startDate;
					while (startDate.isInvalid()) {
						cout << "Error: Please enter a valid date: (MM/DD/YYYY) " << endl;
						cin >> startDate;
					}

					cout << "Course End Date: (EX: 1/1/1990) " << endl;
					cin >> endDate;
					while (endDate.isInvalid()) {
						cout << "Error: Please enter a valid date: (MM/DD/YYYY) " << endl;
						cin >> endDate;
					}
					course.setStartDate(startDate).setEndDate(endDate);
				}
			}
		} else if (selection == '2') {

			cout << "Enter the Course Number to remove: (EX: CSIS 112) " << endl;
			getline(cin, courseID);

			while (!courseSched.removeCourse(courseID)) {
				cout << "Error: That is not a valid course in your schedule. Try again" << endl;
				getline(cin, courseID);
			}

			cout << "Successfully deleted course: " << courseID << " from your schedule" << endl;
			
		} else if (selection == '3') {
			cout << endl << courseSched << endl;
		} else if (selection !='q' && selection != 'Q') {
			cout << "ERROR: Please enter a valid input from the menu above." << endl;
		}
	} while (selection != 'q' && selection != 'Q');

	return 0;

}