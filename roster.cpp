#include <iostream>
#include "roster.h"
#include <sstream>

ROSTER::ROSTER()
{

}
void ROSTER::parse(std::string studentData)
{
	std::vector<std::string> result;
	std::stringstream input(studentData);
	while (input.good())
	{
		std::string token;
		std::getline(input, token, ',');
		result.push_back(token);
	}

	DEGREEPROGRAM degreeProgram = DEGREEPROGRAM::SECURITY;
	if (studentData.back() == 'K') degreeProgram = DEGREEPROGRAM::NETWORK;
	if (studentData.back() == 'E') degreeProgram = DEGREEPROGRAM::SOFTWARE;
	add(result.at(0), result.at(1), result.at(2), result.at(3), result.at(4), stoi(result.at(5)), stoi(result.at(6)), stoi(result.at(7)), degreeProgram);
}

void ROSTER::remove(std::string studentId)
{
	bool result = false;
	for (int i = 0; i <= ROSTER::lastIndex; i++)
	{
		std::string id = ROSTER::classRoster[i]->get_studentId();
		if (id == studentId)
		{
			classRoster[i]->STUDENT::STUDENT();
			result = true;
		}
		if ((i == lastIndex and id != studentId) and result == false)
		{
			std::cout << "ERROR: Student ID Not Found." << std::endl << std::endl;
		}
	}
}

void ROSTER::add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, std::string age, int studentDays1, int studentDays2, int studentDays3, DEGREEPROGRAM degreeProgram)
{
	int daysToComplete[3] = { studentDays1, studentDays2, studentDays3 };
	classRoster[++lastIndex] = new STUDENT(studentId, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
}

void ROSTER::printall()
{
	for (int i = 0; i <= ROSTER::lastIndex; i++)
	{
		ROSTER::classRoster[i]->print_data();
	}
	std::cout << std::endl;
}
void ROSTER::printByDegreeProgram(DEGREEPROGRAM degreeProgram)
{
	for(int i = 0; i <= ROSTER::lastIndex; i++)
		if (ROSTER::classRoster[i]->get_degreeProgram() == degreeProgram)
		{
			classRoster[i]->print_data();
		}
	std::cout << std::endl;
}

void ROSTER::printInvalidEmails()
{
	for (int i = 0; i <= ROSTER::lastIndex; i++)
	{
		std::string id = ROSTER::classRoster[i]->get_emailAddress();
		if ((id.find('.') == std::string::npos and id.find('@') == std::string::npos) or id.find(' ') != std::string::npos)
		{
			std::cout << id << " is an invalid email." << std::endl;
			std::cout << std::endl;
		}
	}
}

void ROSTER::printAverageDaysInCourse(std::string studentId)
{
	for (int i = 0; i <= ROSTER::lastIndex; i++)
	{
		if (classRoster[i]->get_studentId() == studentId)
		{
			std::cout << "Student ID: " << studentId << '\t' << "Average Days In Courses: ";
			std::cout << (classRoster[i]->get_daysToComplete()[0] 
				+ classRoster[i]->get_daysToComplete()[1] 
				+ classRoster[i]->get_daysToComplete()[2]) / 3.0 << std::endl;
		}
	}
}

ROSTER::~ROSTER()
{

}

