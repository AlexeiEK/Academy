#pragma once

#include "Person.h"

enum Subject { Graphics, Development };

string SubjectToString(Subject subject)
{
	switch (subject) {
	case Graphics:
		return "Графика";
	case Development:
		return "Разработка";
	}
}

class Teacher {
public:
	Person personal_info;
	Subject subject;

	Teacher () {}
	Teacher (Person _personal_info, Subject _subject)
	{
		personal_info = _personal_info;
		subject = _subject;
	}
	Teacher (string teacher, char delimiter)
	{
		// teacher = "имя;возраст;пол;специализация"

		int pos = teacher.find(delimiter);
		string name = teacher.substr(0, pos);
		teacher = teacher.substr(pos + 1); // teacher = "возраст;пол;специализация"

		pos = teacher.find(delimiter);
		string age = teacher.substr(0, pos);
		teacher = teacher.substr(pos + 1); //teacher = "пол;специализация"

		pos = teacher.find(delimiter);
		string sex = teacher.substr(0, pos);
		string _subject = teacher.substr(pos + 1);

		personal_info.name = name;
		personal_info.age = stoi(age);
		if (sex == "мужской")
		{
			personal_info.sex = Male;
		}
		else
		{
			personal_info.sex = Female;
		}
		if (_subject == "Графика")
		{
			subject = Graphics;
		}
		else
		{
			subject = Development;
		}
	}
	string ToString()
	{
		string output = personal_info.name + ";" + to_string(personal_info.age) + ";" + SexToString(personal_info.sex) +
			";" + SubjectToString(subject);
		return output;
	}
};