#pragma once

#include <vector>

#include "show.h"

using namespace std;

void ShowStudents(vector<Student> students)
{
	for (auto student : students) {
		ShowStudent(student);
	}
}

void ShowTeachers(vector<Teacher> teachers)
{
	for (auto teacher : teachers) {
		ShowTeacher(teacher);
	}
}


//TODO Написать реализацию по выводу информации о менеджерах

Sex InputSex()
{
	char temp;
	cout << "Введите пол: M - мужской, F - женский "; cin >> temp;
	if (temp == 'M' || temp == 'm') {
		return Sex::Male;
	}
	else if (temp == 'F' || temp == 'f') {
		return Sex::Female;
	}
	else {
		return Sex::Unknown;
	}
}

Faculty InputFaculty()
{
	char temp;
	Faculty temp_faculty;
	cout << "Введите факультет: S - РПО, D - КГиД ";
	cin >> temp;
	(temp == 'D' || temp == 'd') ? temp_faculty = Design : temp_faculty = SoftDev;
	return temp_faculty;
}

Subject InputSubject()
{
	char temp;
	Subject temp_subject;
	cout << "Введите специализацию: G - Графика, D - Разработка ";
	cin >> temp;
	(temp == 'G' || temp == 'g') ? temp_subject = Graphics : temp_subject = Development;
	return temp_subject;
}
Position InputPosition()
{
	char temp;
	Position temp_position;
	cout << "Введите должность: D - Директор, S - менеджер ";
	cin >> temp;
	(temp == 'D' || temp == 'd') ? temp_position = Director : temp_position = Sales;
	return temp_position;
}

void InputStudent(vector<Student>& students)
{
	Student temp;
	cout << "Ввод данных о студенте" << endl;
	cout << "Введите имя - "; cin >> temp.personal_info.name;
	cout << "Введите возраст - "; cin >> temp.personal_info.age;
	temp.personal_info.sex = InputSex();
	cout << "Введите рейтинг - "; cin >> temp.rating;
	temp.faculty = InputFaculty();
	students.push_back(temp);
}

void InputTeacher(vector<Teacher>& teachers)
{
	Teacher temp;
	cout << "Ввод данных о преподавателе" << endl;
	cout << "Введите имя - "; cin >> temp.personal_info.name;
	cout << "Введите возраст - "; cin >> temp.personal_info.age;
	temp.personal_info.sex = InputSex();
	temp.subject = InputSubject();
	teachers.push_back(temp);
}

void InputManager(vector<Manager>& managers)
{
	Manager temp;
	cout << "Ввод данных о сотруднике" << endl;
	cout << "Введите имя - "; cin >> temp.personal_info.name;
	cout << "Введите возраст - "; cin >> temp.personal_info.age;
	temp.personal_info.sex = InputSex();
	temp.position = InputPosition();
	managers.push_back(temp);
}