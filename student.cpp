#include<iostream>
#include "student.h"

using namespace std;


//intialize
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = age;
	for (int i = 0; i < numberofdaysArraySize; i++) {
		this->numofDays[i] = 0;
	}
	this->degreeprogram;
}



Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numofDays[], DegreeProgram Degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numberofdaysArraySize; i++) {
		this->numofDays[i] = numofDays[i];
	}
	this->degreeprogram = degreeprogram;
}
//getters
string Student::GetStudentID()
{
	return studentID;
}

string Student::GetFirstName()
{
	return firstName;
}

string Student::GetLastName()
{
	return lastName;
}

string Student::GetEmailAddress()
{
	return emailAddress;
}

int Student::GetAge()
{
	return age;
}

int* Student::GetNumofDays()
{
	for (int i = 0; i < numberofdaysArraySize; i++) {
		numofDays[i] = numofDays[i];
	}
	return numofDays;

}
string Student::GetDegreeProgram()
{
	return degreeprogram;
}
//setters
void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
}
void Student::SetFirstName(string firstName)
{
	this->firstName = firstName;
}
void Student::SetLastName(string lastName)
{
	this->lastName = lastName;
}
void Student::SetEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}
void Student::SetAge(int Age)
{
	this->age = age;
}
void Student::SetNumOfDays(int numofDays[])
{
	for (int i = 0; i < numberofdaysArraySize; i++) {
		this->numofDays[i] = numofDays[i];
	}
}
void Student::SetDegreeProgram()
{
	this->degreeprogram;
}
//print function
void Student::print()
{
	cout << studentID << "\t" <<  "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age << "\t" << "daysInCourse: {" << numofDays[0] << ", " << numofDays[1] << ", " << numofDays[2] << " } " << "Degree Program: " << degreeprogram << endl;
}
