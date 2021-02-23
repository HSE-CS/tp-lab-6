// Copyright 2021 Smirnov Grigory
#include "../include/Employee.h"

Employee::Employee(int id, std::string name) {
	this->id = id;
	//this->pos = pos;
	this->name = std::move(name);
}

void Employee::setWorkTime(int numbOfHours) {
	worktime = numbOfHours;
}

void Employee::setPayment(int money) {
	payment = money;
}

int Employee::getWorkTime() {
	return worktime;
}

std::string Employee::getName() {
	return name;
}

int Employee::getId() {
	return id;
}

int Employee::getPayment() {
	return payment;
}
