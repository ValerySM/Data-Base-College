//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#include "Student.h"
#include <string.h>
#include <iostream>
using namespace std;



Student::Student( char* name, long id)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->id = id;
}

Student::Student(Student& student)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, student.name);
	this->id = student.id;
}

Student::~Student()
{
	delete this->name;
}

long Student::getId()
{
	return id;
}


void Student::print() const
{
}





bool Student::is_Excellent() const
{
	return false;
}
