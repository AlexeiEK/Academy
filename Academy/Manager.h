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
};