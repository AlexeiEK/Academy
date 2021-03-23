#pragma once

#include <string>

using namespace std;

enum Sex { Male, Female, Unknown };

string SexToString(Sex sex)
{
    switch (sex) {
        case Male:
            return "мужской";
        case Female:
            return "женский";
        case Unknown:
            return "неопределён";
    }
}

class Person {
public:
	string name;
	int age;
	Sex sex;

	string ToString()
    {
	    string temp;
	    temp = "Имя: " + name + "\n";
	    temp += "Возраст: " + to_string(age) + "\n";
	    temp += "Пол: " + SexToString(sex) + "\n";
        return temp;
    }
};
