//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
class Student1:public Student
{
private:
	
protected:

	int ageStudy;

	float get_Average() const;
public:
    Course* studentCourse;
    int courseCount;
	
	Student1( char* name, long id,  int ageStudy);
	Student1(Student1& student1);
	~Student1();
	bool is_Excellent() const;
	void print() const;

};

