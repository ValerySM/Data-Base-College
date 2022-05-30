//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
class Student0 : public Student
{
private:
	bool is_short;
public:
	
	Student0( char* name, long id, bool is_short);
	Student0(Student0& student);
	~Student0();
	void print() const;

};

