#pragma once
#include<string>
#include<iostream>
#include "student.h"


using namespace std;
class Roster
{
private:

	
	//sets the index
	int index;

	//sets number of array size in the roster.
	int maxsize;


	//array of pointers
	Student** classRosterArray;

	DegreeProgram degreeProgram = SOFTWARE;
	//student data table

public:


	//intialize roster
	Roster();

	//function that creates the roster and sets the number that are in the array
	Roster(int maxsize);
	~Roster();

	
	// add method to add parse data to the array
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysinCourse3, DegreeProgram degreeProgram);

	//Parse the array before it is added
	void parseThanAdd(string row);

	 

	//print all function
	void printall();

	//removes the student from the roster by student ID
	void remove(string studentID);

	//prints students average day in the course
	void printAverageDaysInCourse(string studentID);

	//uses regex to verify email address https://www.codespeedy.com/program-to-validate-email-id-using-regex-in-cpp/

	bool emailCheck(string email);

	//prints invalid email entry. 
	void printInvalidEmails();

	//prints by degree type
	void printByDegreeProgram(DegreeProgram degreeProgram);


	
};

