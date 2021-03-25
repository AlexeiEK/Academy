#pragma once

#include <iostream>

using namespace std;


void ShowMenu()
{
	cout << "-------------------------------" << endl;
	cout << "Меню работы:" << endl;
	cout << "1. Добавить студента" << endl;
	cout << "2. Добавить преподавателя" << endl;
	cout << "3. Добавить менеджера" << endl;
	cout << "4. Показать всех студентов" << endl;
	cout << "5. Показать всех преподавателей" << endl;
	cout << "6. Показать всех менеджеров" << endl;
	cout << endl;
	cout << "0. Выход" << endl;
	cout << "-------------------------------" << endl;
	cout << "Введите номер: ";
}