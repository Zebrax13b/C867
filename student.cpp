#include <iostream>
#include "student.h"


//getters definitions
std::string STUDENT::get_studentId()
{
	return this->studentId;
}

std::string STUDENT::get_firstName()
{
	return this->firstName;
}

std::string STUDENT::get_lastName()
{
	return this->lastName;
}

std::string STUDENT::get_emailAddress()
{
	return this->emailAddress;
}

std::string STUDENT::get_age()
{
	return this->age;
}

const int* STUDENT::get_daysToComplete()
{
	return this->daysToComplete;
}


DEGREEPROGRAM STUDENT::get_degreeProgram()
{
	return this->degreeProgram;
}



//setters definition
void STUDENT::set_studentId(std::string studentId)
{
	this->studentId = studentId;
}

void STUDENT::set_firstName(std::string firstName)
{
	this->firstName = firstName;
}

void STUDENT::set_lastName(std::string lastName)
{
	this->lastName = lastName;
}

void STUDENT::set_emailAddress(std::string emailAddress)
{
	this->emailAddress = emailAddress;
}

void STUDENT::set_age(std::string age)
{
	this->age = age;
}

void STUDENT::set_daysToComplete(const int daysToComplete[])
{
	for (int i = 0; i < daysToCompleteSize; i++)
	{
		this->daysToComplete[i] = daysToComplete[i];
	}
}
void STUDENT::set_degreeProgram(DEGREEPROGRAM degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

std::string STUDENT::string_degreeProgram(DEGREEPROGRAM degreeProgram)
{
	std::string string_degreeProgram;
	switch (degreeProgram) {
	case 0:
		string_degreeProgram = "Security";
		return string_degreeProgram;
		break;
	case 1:
		string_degreeProgram = "Network";
		return string_degreeProgram;
		break;
	case 2:
		string_degreeProgram = "Software";
		return string_degreeProgram;
		break;
	}
}

void STUDENT::print_data()
{
	std::cout << get_studentId();
	std::cout << '\t';
	std::cout << "First Name: " << get_firstName();
	std::cout << '\t';
	std::cout << "Last Name: " << get_lastName();
	std::cout << '\t';
	std::cout << "Email Address: " << get_emailAddress();
	std::cout << '\t';
	std::cout << "Age: " << get_age();
	std::cout << '\t';
	std::cout << "Days In Course: { ";
	std::cout << get_daysToComplete()[0] << ", ";
	std::cout << get_daysToComplete()[1] << ", ";
	std::cout << get_daysToComplete()[2] << " ";
	std::cout << "}";
	std::cout << '\t';
	std::cout << "Degree Program: " << string_degreeProgram(degreeProgram) << std::endl;
}


//constructor definition
STUDENT::STUDENT()
{
	studentId = "No ID";
	firstName = "Default";
	lastName = "Default";
	emailAddress = "Default@Default.com";
	age = "No Age";
	for (int i = 0; i < daysToCompleteSize; i++)
	{
		this->daysToComplete[i] = 0;
	}
	degreeProgram = DEGREEPROGRAM::SECURITY;
}

STUDENT::STUDENT(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, std::string age, int* daysToComplete, DEGREEPROGRAM degreeProgram
)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysToCompleteSize; i++)
	{
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

//deconstructor definition
STUDENT::~STUDENT()
{

}
