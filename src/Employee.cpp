#include "Employee.h"

Employee::Employee(unsigned int id, std::string name, Position position) {
	this->id = id;
	this->name = name;
	this->position = position;
}

void Employee::setWorkTime(unsigned int wtime) {
	this->worktime = wtime;
}