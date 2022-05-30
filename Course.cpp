//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#include "Course.h"
#include <string.h>
#include <iostream>
using namespace std;

Course::Course()
{
	this->name = new char[5];
	this->lecturer = new char[5];
	strcpy(this->name, "none");
	strcpy(this->lecturer, "none");
	this->grade = 0;
}
 
Course::Course(char* name, char* lecturer, int grade)
{
	this->name = new char[strlen(name) +1];
	this->lecturer = new char[strlen(lecturer) + 1];
	strcpy(this->name, name);
	strcpy(this->lecturer, lecturer);
	this->grade = grade;

}

Course::Course(Course& course)
{
	this->name = new char[strlen(course.name) + 1];
	this->lecturer = new char[strlen(course.lecturer) + 1];
	strcpy(this->name, course.name);
	strcpy(this->lecturer, course. lecturer);
	this->grade = course.grade;
}

Course::~Course()
{
	delete this->name;
	delete this->lecturer;
}

int Course::getGrade() const
{
	return grade;
}

Course& Course::operator=(const Course& course)//Overloaded assignment operator
{
	this->name = new char[strlen(course.name) + 1];
	this->lecturer = new char[strlen(course.lecturer) + 1];
	strcpy(this->name, course.name);
	strcpy(this->lecturer, course.lecturer);
	this->grade = course.grade;
	return *this;
}
