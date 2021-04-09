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
				ShowRecording(pathStud);
			}
			else {
				ShowNoRecording(pathStud);
			}
			break;
		}
		case '2': // 2. Добавить преподавателя
		{
			InputTeacher(teachers);
			bool isWrite = WriteTeacher(pathTeach, teachers);
			if (isWrite) {
				ShowRecording(pathTeach);
			}
			else {
				ShowNoRecording(pathTeach);
			}
			break;
		}
		case '3': // 3. Добавить менеджера
		{
			InputManager(managers);
			bool isWrite = WriteManager(pathMan, managers);
			if (isWrite) {
				ShowRecording(pathMan);
			}
			else {
				ShowNoRecording(pathMan);
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
