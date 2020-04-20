#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student
{
public:
	static const int numberofdaysArraySize = 3;

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numofDays[numberofdaysArraySize];
	string degreeprogram;
	DegreeProgram degreeProgram;

public:
	//intialize
	Student();
	//function with parameter
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numofDays[], DegreeProgram degreeProgram);


	//getters
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetNumofDays();
	string GetDegreeProgram();

	//setters

	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int Age);
	void SetNumOfDays(int numofDays[]);
	void SetDegreeProgram();



	// print functions
	void print();



};