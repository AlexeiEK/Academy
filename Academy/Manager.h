#pragma once

#include "Person.h"

enum Position { Director, Sales };

string PositionToString(Position position)
{
    switch (position) {
    case Director:
        return "��������";
    case Sales:
        return "��������";
    }
}

class Manager {
public:
	Person personal_info;
	Position position;
};