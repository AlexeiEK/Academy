#include <iostream>
#include <vector>
#include <string>
#pragma warning(default:4716)

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

	string pathMan = "D:\\Programming\\source\\repos\\Academy\\Academy\\Manager.csv";
	string pathTeach = R"(D:\Programming\source\repos\Academy\Academy\Teacher.csv)";
	string pathStud = "D:\\Programming\\source\\repos\\Academy\\Academy\\Student.csv";

	bool exit = false;
	char select;
	do {
		ShowMenu();
		cin >> select;

		switch (select) {
		case '1':   // 1. Добавить студента
		{
			bool isWrite = WriteToFileStudent(pathStud);;
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
			bool isWrite = WriteToFileTeacher(pathTeach);
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
			bool isWrite = WriteToFileManager(pathMan);
			if (isWrite) {
				ShowRecording(pathMan);
			}
			else {
				ShowNoRecording(pathMan);
			}
			break;
		}
		case '4': // 4. Показать всех студентов
			ReadFromFileStudent(pathStud, students);
			ShowStudents(students);
			break;
		case '5': // 5. Показать всех преподавателей
			ReadFromFileTeacher(pathTeach, teachers);
			ShowTeachers(teachers);
			break;
		case '6': // 6. Показать всех менеджеров
			ReadFromFileManager(pathMan, managers);
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
