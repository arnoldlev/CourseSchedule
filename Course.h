// Arnold Lev
// Joseph Kahale
// Emil Hovsepians
// CSIS 137 - Online
// Midterm Project (STEM Group)

#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
#include "Time.h"
#include "Date.h"
using namespace std;

class Course {

	friend ostream& operator<<(ostream&, const Course&);

	private:
		string courseNumber;
		string courseName;
		string meetingDays;
		double units;
		Date startDate;
		Date endDate;
		Time startTime;
		Time endTime;
	public:
		Course(const string & = "N/A", const string & = "N/A", const string & = "N/A", double = 0.0, const Date & = Date(), const Date & = Date(),
			 const Time& = Time(), const Time& = Time());
		~Course();

		const string& getCourseNumber() const;
		const string& getCourseName() const;
		const string& getMeetingDays() const;
		double getUnits() const;

		Date getStartDate() const;
		Date getEndDate() const;
		Time getStartTime() const;
		Time getEndTime() const;

		Course& setCourseNumber(const string&);
		Course& setCourseName(const string&);
		Course& setMeetingDay(const string&);
		Course& setUnits(double);

		Course& setStartDate(const Date&);
		Course& setEndDate(const Date&);
		Course& setStartTime(const Time&);
		Course& setEndTime(const Time&);

		double calcDailyDuration() const;

};

#endif