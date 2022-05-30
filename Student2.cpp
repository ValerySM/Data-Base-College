//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#include "Student2.h"
#include <string.h>
#include <iostream>
using namespace std;


Student2::Student2(char* name, long id, char* thesis, char* supervisor):Student(name,id)
{
	this->thesis = new char[strlen(thesis) + 1];
	this->supervisor = new char[strlen(supervisor) + 1];
	strcpy(this->thesis, thesis);
	strcpy(this->supervisor, supervisor);
}

Student2::Student2(Student2& student2):Student( student2.name, student2.id)
{
	this->thesis = new char[strlen(student2.thesis) + 1];
	this->supervisor = new char[strlen(student2.supervisor) + 1];
	strcpy(this->thesis, student2.thesis);
	strcpy(this->supervisor, student2.supervisor);
}
Student2::~Student2()
{
	delete this->thesis;
	delete this->supervisor;
}
bool Student2::is_Excellent() const
{
	return true;
}

void Student2::print() const
{
	cout << name << " " << id << " " << thesis << " " << supervisor << endl;
}
