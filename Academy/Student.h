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

	Student() {}
	Student(Person _personal_info, double rating, Faculty _faculty)
	{
		personal_info = _personal_info;
		this->rating = rating;
		faculty = _faculty;
	}
	Student(string student, char delimiter)
	{
		// student = "имя;возраст;пол;рейтинг;факультет"

		int pos = student.find(delimiter);
		string name = student.substr(0, pos);
		student = student.substr(pos + 1); // student = "возраст;пол;рейтинг;факультет";

		pos = student.find(delimiter);
		string age = student.substr(0, pos);
		student = student.substr(pos + 1); // student = "пол;рейтинг;факультет";

		pos = student.find(delimiter);
		string sex = student.substr(0, pos);
		student = student.substr(pos + 1); // student = "рейтинг;факультет";

		pos = student.find(delimiter);
		string _rating = student.substr(0, pos);
		string _faculty = student.substr(pos + 1);

		personal_info.name = name;
		personal_info.age = stoi(age);
		if (sex == "мужской")
		{
			personal_info.sex = Male;
		}else
		{
			personal_info.sex = Female;
		}
		rating = stod(_rating);
		if (_faculty == "РПО")
		{
			faculty = SoftDev;
		}
		else
		{
			faculty == Design;
		}
	}
	string ToString()
	{
		string output = personal_info.name + ";" + to_string(personal_info.age) + ";"
			+ SexToString(personal_info.sex) + ";" + to_string(rating) + ";" + FacultyToString(faculty);
		return output;
	}
};