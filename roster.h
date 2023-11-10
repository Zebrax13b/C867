#pragma once
#include <iostream>
#include "student.h"
#include <vector>

class ROSTER
{
private:
	int lastIndex = -1;
	const std::string studentData;
	const static int numStudents = 5;

public:
	STUDENT* classRoster[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	void parse(std::string row);
	void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, std::string age, int studentDays1, int studentDays2, int studentDays3, DEGREEPROGRAM degreeProgram);
	void remove(std::string studentId);
	void printall();
	void printAverageDaysInCourse(std::string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DEGREEPROGRAM degreeProgram);

	ROSTER();

	~ROSTER();
};