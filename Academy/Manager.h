#pragma once

#include "Person.h"

enum Position { Director, Sales };

string PositionToString(Position position)
{
	switch (position) {
	case Director:
		return "Директор";
	case Sales:
		return "Менеджер";
	}
}

class Manager {
public:
	Person personal_info;
	Position position;
	string ToString()
	{
		string output = personal_info.name + ";" + to_string(personal_info.age) + ";"
			+ PositionToString(position);
		return output;
	}
};