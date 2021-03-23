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
};