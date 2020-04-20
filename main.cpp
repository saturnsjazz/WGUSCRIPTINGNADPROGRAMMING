#include<iostream>
#include "roster.h"

using namespace std;

int main() {

	const int  numberofStudents = 5;
	const string studentData[numberofStudents] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Austin,Kuhlman,akuhlm3@wgu.edu,30,30,40,50,SOFTWARE" };

	cout << "Scripting and Programming - Applications C867" << endl;
	cout << "Programming language: C++" << endl;
	cout << "Student ID: #001122281" << endl;
	cout << "Austin Kuhlman" << endl << endl << endl;
	


	Roster* classRoster = new Roster(numberofStudents);

	for (int i = 0; i < numberofStudents; i++)
	{
		classRoster->parseThanAdd(studentData[i]);
	}

	cout << "Printing Class Roster..." << endl << endl;

	classRoster->printall();

	cout << "Printing by Degree program..." << endl << endl;

	classRoster->printByDegreeProgram(SECURITY);

	classRoster->printAverageDaysInCourse("A5");

	classRoster->remove("A3");
	classRoster->printall();
	classRoster->remove("A3");
	classRoster->printInvalidEmails();

	return 0;
}