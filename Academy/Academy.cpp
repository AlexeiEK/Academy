#include <iostream>
#include <vector>
#include <string>

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

	string pathMan = "Manager.csv";
	string pathTeach = "Teacher.csv";
	string pathStud = "Student.csv";

	bool exit = false;
	char select;
	do {
		ShowMenu();
		//cout << "Введите номер: ";
		cin >> select;

		switch (select) {
		case '1':   // 1. Добавить студента
		{
			InputStudent(students);
			bool isWrite = WriteStudent(pathStud, students);
			if (isWrite) {
				cout << "1 Данные успешно записались в файл " << pathStud << endl;
			}
			else {
				cerr << "0 Запись в файл " << pathStud << " не удалась" << endl;
			}
			break;
		}
		case '2': // 2. Добавить преподавателя
		{
			InputTeacher(teachers);
			bool isWrite = WriteTeacher(pathTeach, teachers);
			if (isWrite) {
				cout << "1 Данные успешно записались в файл " << pathTeach << endl;
			}
			else {
				cerr << "0 Запись в файл " << pathTeach << " не удалась" << endl;
			}
			break;
		}
		case '3': // 3. Добавить менеджера
		{
			InputManager(managers);
			bool isWrite = WriteManager(pathMan, managers);
			if (isWrite) {
				cout << "1 Данные успешно записались в файл " << pathMan << endl;
			}
			else {
				cerr << "0 Запись в файл " << pathMan << " не удалась" << endl;
			}
			break;
		}
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
