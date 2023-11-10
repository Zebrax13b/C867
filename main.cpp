#include <iostream>
#include "student.h"
#include "roster.h"

int main()
{


	std::cout << "WGU C867 - Scripting and Programming: Applications" << std::endl;
	std::cout << "Programming Language: C++" << std::endl;
	std::cout << "Student ID - 003745326" << std::endl;
	std::cout << "Name - Nathaniel Coulter" << std::endl;
	std::cout << std::endl;

	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Nathaniel,Coulter,ncoult3@wgu.edu,27,35,40,55,SOFTWARE" };

	ROSTER classRoster;
	for (int i = 0; i < 5; i++)
	{
		classRoster.parse(studentData[i]);
	}
	
	classRoster.printall();
	
	classRoster.printInvalidEmails();
	
	for (int i = 0; i < 5; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRoster[i]->get_studentId());
	}
	
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printall();
	classRoster.remove("A3");

};
