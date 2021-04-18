#pragma once

#include <vector>
#include <fstream>
#include <string>

#include "show.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

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

void ShowManagers(vector<Manager> managers)
{
	for (auto manager : managers) {
		ShowManager(manager);
	}
}

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

bool FileOpen(string path, string message)
{
	ofstream file;
	file.open(path, ios_base::app);
	if (file.is_open())
	{
		file << message << endl;
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

Student InputStudent()
{
	Student temp;
	cout << "Ввод данных о студенте" << endl;
	cout << "Введите имя - "; cin >> temp.personal_info.name;
	cout << "Введите возраст - "; cin >> temp.personal_info.age;
	temp.personal_info.sex = InputSex();
	cout << "Введите рейтинг - "; cin >> temp.rating;
	temp.faculty = InputFaculty();
	return temp;
}
Teacher InputTeacher()
{
	Teacher temp;
	cout << "Ввод данных о преподавателе" << endl;
	cout << "Введите имя - "; cin >> temp.personal_info.name;
	cout << "Введите возраст - "; cin >> temp.personal_info.age;
	temp.personal_info.sex = InputSex();
	temp.subject = InputSubject();
	return temp;
}
 Manager InputManager()
{
	Manager temp;
	cout << "Ввод данных о сотруднике" << endl;
	cout << "Введите имя - "; cin >> temp.personal_info.name;
	cout << "Введите возраст - "; cin >> temp.personal_info.age;
	temp.personal_info.sex = InputSex();
	temp.position = InputPosition();
	return temp;
}
bool WriteToFileStudent(string path)
{
	string message = InputStudent().ToString();
	FileOpen(path, message);
}
bool WriteToFileTeacher(string path)
{
	string message = InputTeacher().ToString();
	FileOpen(path, message);
}
bool WriteToFileManager(string path)
{
	string message = InputManager().ToString();
	FileOpen(path, message);
}

void ReadFromFileStudent(string path, vector<Student>& students)
{
	ifstream input;
	input.open(path);
	if (input.is_open()) {
		while (!input.eof()) {
			string line;
			getline(input, line);
			Student student(line, ';');
			students.push_back(student);
		}
	}
	else {
		cerr << "Error file!" << endl;
	}
	input.close();
}
void ReadFromFileTeacher(string path, vector<Teacher>& teachers)
{
	ifstream input;
	input.open(path);
	if (input.is_open()) {
		while (!input.eof()) {
			string line;
			getline(input, line);
			Teacher teacher(line, ';');
			teachers.push_back(teacher);
		}
	}
	else {
		cerr << "Error file!" << endl;
	}
	input.close();
}
void ReadFromFileManager(string path, vector<Manager>& managers)
{
	ifstream input;
	input.open(path);
	if (input.is_open()) {
		while (!input.eof()) {
			string line;
			getline(input, line);
			Manager manager(line, ';');
			managers.push_back(manager);
		}
	}
	else {
		cerr << "Error file!" << endl;
	}
	input.close();
}

bool WriteStudent(string path, vector<Student>& students)
{
	for (auto item : students)
	{

		/*string message = item.personal_info.name + ";" + to_string(item.personal_info.age) + ";"
			+ to_string(item.rating) + ";" + SexToString(item.personal_info.sex) + ";" + FacultyToString(item.faculty);*/
		string message = item.ToString();
		FileOpen(path, message);
	}
}
bool WriteTeacher(string path, vector<Teacher>& teachers)
{
	for (auto item : teachers)
	{

		/*string message = item.personal_info.name + ";" + to_string(item.personal_info.age) + ";"
			+ SubjectToString(item.subject);*/
		string message = item.ToString();
		FileOpen(path, message);
	}
}
bool WriteManager(string path, vector<Manager>& managers)
{
	for (auto item : managers)
	{

		/*string message = item.personal_info.name + ";" + to_string(item.personal_info.age) + ";"
			+ PositionToString(item.position);*/
		string message = item.ToString();
		FileOpen(path, message);
	}
}