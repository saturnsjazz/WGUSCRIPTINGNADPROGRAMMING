#include"roster.h"
#include"degree.h"
#include "student.h"
#include<string>
#include<iostream>
#include<regex>




using namespace std;

Roster::Roster()
{
	this->maxsize = 0;
	this->index = -1;
	this->classRosterArray = nullptr;
}
//sets the max size for the roster
Roster::Roster(int maxsize)
{
	this->maxsize = maxsize;
	this->index = -1;
	this->classRosterArray = new Student * [maxsize];
}
//deconstructor
Roster::~Roster()
{
	for (int i = 0; i <= index; i++) {
		delete this->classRosterArray[i];
	}
}
//add method to add once parsed to array
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysinCourse3, DegreeProgram degreeProgram)
{
	index++;
	int courseDaysArray[3] = { daysInCourse1,daysInCourse2,daysinCourse3 };
	classRosterArray[index] = new Student (studentID, firstName, lastName, emailAddress, age, courseDaysArray, degreeProgram);
}

//parse each student to add to classRosterArray
void Roster::parseThanAdd(string row)
{
	//DegreeProgram;
	//read studentID
	int rightHandSide = row.find(",");
	string studentIDTemp = row.substr(0, rightHandSide);

	//firstName
	int leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	string firstNameTemp = row.substr(leftHandSide, rightHandSide - leftHandSide);

	//lastname
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	string lastNameTemp = row.substr(leftHandSide, rightHandSide - leftHandSide);
	//read emailAddress
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	string emailAddressTemp = row.substr(leftHandSide, rightHandSide - leftHandSide);

	//read age
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	int ageTemp = std::stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));  // converts string to interger 
	//int ageTemp = 0;

	//read course days 1 value
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	int courseDays1Temp = std::stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));  // // converts string to interger 
	
	

	//read course days 2 value
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	int courseDays2Temp = std::stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));  // // converts string to interger 
	
	//read course days 3 value
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	int courseDays3Temp = std::stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));  // // converts string to interger 

	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	string degreeProgramTemp = row.substr(leftHandSide, rightHandSide - leftHandSide);

	if (degreeProgramTemp == "SECURTIY") {
		degreeProgram = SECURITY;
	}
	if (degreeProgramTemp == "NETWORK") {
		degreeProgram = NETWORK;
	}
	if (degreeProgramTemp == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}

	add(studentIDTemp, firstNameTemp, lastNameTemp, emailAddressTemp, ageTemp, courseDays1Temp, courseDays2Temp, courseDays3Temp, degreeProgramTemp);

}
//print all in array 
void Roster::printall()
{
	for (int i = 0; i <= index; i++) {
		(this->classRosterArray)[i]->print();
	}
}
//remove student by student if
void Roster::remove(string studentID)
{
	
	for (int i = 0; i < -index; i++) {
		if (this->classRosterArray[i]->GetStudentID() == studentID)
		{
			
			delete this->classRosterArray[i];
			this->classRosterArray[i]->print();
			
		}
		else
		{
			cout << "A student with this " << studentID << " was not found" << endl;
		}
	}

}
//print average days in cource by user id
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= index; i++)
	{
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			int* days = classRosterArray[i]->GetNumofDays();
			cout << "Average number of course days " << studentID << " is " << (days[0] + days[1] + days[2] / 3) << endl;
		}
	}
}
bool Roster::emailCheck(string email)
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}
// print invalid email using regex
void Roster::printInvalidEmails()
{
	for (int i = 0; i <= index; i++) {
		string emailcheck = (this->classRosterArray)[i]->GetEmailAddress();
		bool validemail = emailCheck(emailcheck);
		if (validemail) {
			//cout << validemail << " is not valid email." << endl;
		}
		else
		{
			this->classRosterArray[i]->print();
			cout << " is not valid" << endl;
		}
	}
}
// use switch statement to print by enum type
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	switch (degreeProgram)
	{

	case SECURITY:


		for (int i = 0; i <= index; i++) {

			(this->classRosterArray[i]->GetDegreeProgram()) = "SECURTIY";
			(this->classRosterArray[i])->print();
		}
		break;
	case NETWORK:
		for (int i = 0; i <= index; i++) {
			(this->classRosterArray[i]->GetDegreeProgram()) = "NETWORK";
			(this->classRosterArray[i])->print();

		}
		break;
	case SOFTWARE:
		for (int i = 0; i <= index; i++) {
			(this->classRosterArray[i]->GetDegreeProgram()) = "SOFTWARE";
			(this->classRosterArray[i])->print();

		}
		break;
	default:
		break;
	}

}



