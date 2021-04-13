#pragma once

#include "Person.h"

enum Faculty { SoftDev, Design };

string FacultyToString(Faculty faculty)
{
	switch (faculty) {
	case SoftDev:
		return "РПО";
	case Design:
		return "КГиД";
	}
}

class Student
{
public:
	Person personal_info;
	double rating;
	Faculty faculty;
	string ToString()
	{
		string output = personal_info.name + ";" + to_string(personal_info.age) + ";"
			+ SexToString(personal_info.sex) + ";" + to_string(rating) + ";" + FacultyToString(faculty);
		return output;
	}
};