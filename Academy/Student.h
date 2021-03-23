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
};