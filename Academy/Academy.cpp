﻿#include <iostream>
#include <vector>

#include <clocale>

#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

#include "menu.h"
#include "cli.h"

int main()
{
	system("chcp 65001");

	vector<Student> students;
	vector<Teacher> teachers;
	vector<Manager> managers;

	bool exit = false;
	char select;
	do {
		ShowMenu();
		//cout << "Введите номер: ";
		cin >> select;

		switch (select) {
		case '1':  // 1. Добавить студента
			InputStudent(students);
			break;
		case '2': // 2. Добавить преподавателя
			InputTeacher(teachers);
			break;
		case '3': // 3. Добавить менеджера
			InputManager(managers);
			break;
		case '4': // 4. Показать всех студентов
			ShowStudents(students);
			break;
		case '5': // 5. Показать всех преподавателей
			ShowTeachers(teachers);
			break;
		case '6': // 6. Показать всех менеджеров
			ShowManagers(managers);
			break;
		case '0': // 0. Выход
			exit = true;
			break;
		default:
			void Caution();
			break;
		}
	} while (!exit);
	setlocale(LC_ALL, "rus");
	cout << "До свидания..." << endl;

	return 0;
}
