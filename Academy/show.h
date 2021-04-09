#pragma once

#include <iostream>

#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;

void Caution()
{
	cout << "Вы ввели не тот номер. Введите номер от 0 до 6!" << endl;
}

void ShowRecording(string path)
{
	cout << "Данные успешно записались в файл " << path << endl;
}
void ShowNoRecording(string path)
{
	cerr << "Запись в файл " << path << " не удалась" << endl;
}

void ShowStudent(Student student)
{
	cout << "=== Информация о студенте ===" << endl;
	cout << student.personal_info.ToString();
	cout << "Рейтинг: " << student.rating << endl;
	cout << "Факультет: " << FacultyToString(student.faculty) << endl;
	cout << "-----------------------------" << endl;
}
void ShowTeacher(Teacher teacher)
{
	cout << "=== Информация о преподавателе ===" << endl;
	cout << teacher.personal_info.ToString();
	cout << "Специализация: " << SubjectToString(teacher.subject) << endl;
	cout << "-----------------------------" << endl;
}
void ShowManager(Manager manager)
{
	cout << "=== Информация о сотруднике ===" << endl;
	cout << manager.personal_info.ToString();
	cout << "Должность: " << PositionToString(manager.position) << endl;
	cout << "-----------------------------" << endl;
}