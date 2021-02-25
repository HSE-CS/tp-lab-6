#include "Employee.h"

Employee::Employee(unsigned int id, std::string name, Position position) {
	this->id = id;
	this->name = name;
	this->position = position;
}

void Employee::setWorkTime(unsigned int wtime) {
	this->worktime = wtime;
}


std::string Employee::getName() {
	return this->name;
}

Position Employee::getPosition() {
	return this->position;
}

unsigned int Employee::getWorktime() {
	return this->worktime;
}
unsigned int Employee::getPayment() {
	return this->payment;
}
