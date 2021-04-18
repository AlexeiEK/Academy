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

	Manager() {}
	Manager(Person _personal_info, Position _position)
	{
		personal_info = _personal_info;
		position = _position;
	}
	Manager(string manager, char delimiter)
	{
		// manager = "имя;возраст;пол;должность"

		int pos = manager.find(delimiter);
		string name = manager.substr(0, pos);
		manager = manager.substr(pos + 1); // manager = "возраст;пол;должность"

		pos = manager.find(delimiter);
		string age = manager.substr(0, pos);
		manager = manager.substr(pos + 1); // manager = "пол;должность"

		pos = manager.find(delimiter);
		string sex = manager.substr(0, pos);
		string _position = manager.substr(pos + 1);

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
		if (_position == "Директор")
		{
			position = Director;
		}
		else
		{
			position = Sales;
		}
	}
	string ToString()
	{
		string output = personal_info.name + ";" + to_string(personal_info.age) + ";" + SexToString(personal_info.sex) +
			";" + PositionToString(position);
		return output;
	}
};