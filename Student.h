//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Course.h"
#include <string>
#include <iostream>
class Student
{protected:
	
	long id;
public:
	
	Student(char* name, long id);
	Student(Student& student);
	~Student();
	virtual bool is_Excellent() const;
	long getId();
	virtual void print() const;
	char* name;
	
};

