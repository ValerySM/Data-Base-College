//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#pragma once
#define _CRT_SECURE_NO_WARNINGS
class Course
{
private:


public:
	Course();
	Course(char* name, char* lecturer, int grade);
	Course(Course& course);
	~Course();
    int grade;
    char* name;
    char* lecturer;
	int getGrade() const;
	Course& operator= (const Course& course);//Overloaded assignment operator
};

