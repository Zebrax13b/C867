#pragma once
#include <string>
#include "degree.h"
#include <iostream>

class STUDENT
{
public:
	const static int daysToCompleteSize = 3;
private:
	//definitions of class student
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string age;
	int daysToComplete[daysToCompleteSize];
	DEGREEPROGRAM degreeProgram;

public:
	//getters declarations
	std::string get_studentId();
	std::string get_firstName();
	std::string get_lastName();
	std::string get_emailAddress();
	std::string get_age();
	const int* get_daysToComplete();
	DEGREEPROGRAM get_degreeProgram();
	

	
	//setters declarations
	void set_studentId(std::string studentId);
	void set_firstName(std::string firstName);
	void set_lastName(std::string lastName);
	void set_emailAddress(std::string emailAddress);
	void set_age(std::string age);
	void set_daysToComplete(const int daysToComplete[]);
	void set_degreeProgram(DEGREEPROGRAM degreeProgram);


	std::string string_degreeProgram(DEGREEPROGRAM degreeProgram);
	

	void print_data();

	//constructor
	STUDENT(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, std::string age, int* daysToComplete, DEGREEPROGRAM degreeProgram
	);

	//universal constructor
	STUDENT();

	//destructor
	~STUDENT();
};