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
	string ToString()
	{
		string output = personal_info.name + ";" + to_string(personal_info.age) + ";" + SexToString(personal_info.sex) +
			";" + SubjectToString(subject);
		return output;
	}
};