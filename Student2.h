//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
class Student2:public Student
{
private:
	
	
public:
	
	Student2( char* name, long id, char* thesis, char* supervisor);
	Student2(Student2& student);
	~Student2();
	bool is_Excellent() const;
	void print() const;
	char* supervisor;
	char* thesis;
};

