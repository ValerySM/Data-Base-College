//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "Student0.h"
#include "Student1.h"
#include "Student2.h"
#include "Course.h"
#include <string.h>
#include <iostream>
#include <typeinfo>

using namespace std;

class College {
protected:
    Student **collegeStudent;
    int numberStudents;
    bool expendStudentArray();//Helper function for array enlargement

public:
    College();
    ~College();
    bool addStudent();
    bool addGrade();
    void printAll();
    void printExellent();
    void findTypes(Student** stArr, int len ,int& type0, int& type1, int& type2);
    int supervisor();
    void menu();
    


};

