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
    //TODO Написать реализацию по выводу информации о преподавателях
}


//TODO Написать реализацию по выводу информации о менеджерах

void InputStudent(vector<Student>& students)
{ //TODO Упростить функцию
    Student temp;
    char temp_sex, temp_faculty;
    cout << "Ввод данных о студенте" << endl;
    cout << "Введите имя - "; cin >> temp.personal_info.name;
    cout << "Введите возраст - "; cin >> temp.personal_info.age;
    cout << "Введите пол: M - мужской, F - женский "; cin >> temp_sex;
    if (temp_sex == 'M') {
        temp.personal_info.sex = Sex::Male;
    } else if (temp_sex == 'F') {
        temp.personal_info.sex = Sex::Female;
    } else {
        temp.personal_info.sex = Sex::Unknown;
    }
    cout << "Введите рейтинг - "; cin >> temp.rating;
    cout << "Введите факультет: S - РПО, D - КГиД ";
    cin >> temp_faculty;
    if (temp_faculty == 'S') {
        temp.faculty = Faculty::SoftDev;
    } else if (temp_faculty == 'D') {
        temp.faculty = Faculty::Design;
    } //TODO Продумать значение по умолчанию или обработку неправильного ввода
    students.push_back(temp);
}

//TODO Написать реализацию по вводу информации о преподавателях

//TODO Написать реализацию по вводу информации о менеджерах