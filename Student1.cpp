//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#include "Student1.h"

#include <iostream>
using namespace std;

float Student1::get_Average() const
{
	float result = 0;
	for (int i = 0; i < courseCount; i++) {
		result += studentCourse[i].getGrade();
	}
	return result / courseCount;
}



Student1::Student1( char* name, long id,  int ageStudy) :Student(name, id)
{
	
	this->ageStudy = ageStudy;
	this->courseCount = 0;
	this->studentCourse = NULL;
	
	
	
}

Student1::Student1(Student1& student1):Student(student1.name, student1.id)
{
	this->ageStudy = student1.ageStudy;
	this->courseCount = student1.courseCount;
	this->studentCourse = new Course[courseCount];
	if (!this->studentCourse)
	{
		cout << "Allocation Error!\n";
		exit(1);
	}
	for (int i = 0; i < courseCount; i++) {
		this->studentCourse[i] = student1.studentCourse[i];
	}

}

Student1::~Student1()
{
	delete this->studentCourse;
}

bool Student1::is_Excellent() const
{
	return ageStudy < 3 && get_Average() >= 90 || ageStudy > 2 && get_Average() >= 85;
	

}

void Student1::print() const
{
	cout << name << " " << id << " " << ageStudy << " " ;
	for (int i = 0; i < courseCount; i++) {
		cout << studentCourse[i].name<<" " <<studentCourse[i].grade<< " ";

	}
	cout << endl;
}



