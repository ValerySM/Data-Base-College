//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#include "Student0.h"
#include <iostream>
using namespace std;



Student0::Student0 (char* name, long id, bool is_short):Student(name,id)
{
	this->is_short = is_short;
}

Student0::Student0(Student0& student0): Student( student0.name, student0.id)
{
	this->is_short = student0.is_short;
}

Student0::~Student0()
{
}

void Student0::print() const
{
	if (is_short == false) {
		cout << name <<" "<< id << " " << "student have long mehina" << endl;
	}
	else {
		cout << name << " " << id << " " << "student have short mehina" << endl;
	}
}
