#pragma once
#include<string>

using namespace std;

class Student
{
private:
	string id;
	string firstName;
	string lastName;

public:
	Student()
	{
		id = "";
		firstName = "";
		lastName = "";
	}

	Student(string studentID, string first, string last)
	{
		id = studentID;
		firstName = first;
		lastName = last;
	}

	string getFirstName()
	{
		return firstName;
	}

	string getLastName()
	{
		return lastName;
	}

	string getID()
	{
		return id;
	}
};