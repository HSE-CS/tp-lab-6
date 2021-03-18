// Copyright 2021 Stifeev Nikita

#include "Personal.h"
#include <iostream>

Personal::Personal(int id, std::string name, int salary) :
	Employee(id, name) {
	this->salary = salary;
}

int Personal::calcBase(int salary, int wtime) {
	return salary * wtime;
}

Driver::Driver(int id, std::string name, int salary) :
	Personal(id, name, salary) {
	this->position = DRIVER;
}

int Driver::calcBonus() {
	return 1500;
}

void Driver::calc() {
	this->payment = calcBase(this->salary, this->worktime) + calcBonus();
}

void Driver::printInfo() {
	std::cout << "#" << this->id << ". " << posToString(this->position) 
		<< " " << this->name << " [personal staff]" << std::endl;
	std::cout << "З/п: " << this->salary << "; отработано (ч): " 
		<< this->worktime << ". Заработано: " << this->payment 
		<< std::endl << std::endl;
}

Cleaner::Cleaner(int id, std::string name, int salary) :
	Personal(id, name, salary) {
	this->position = CLEANER;
}

void Cleaner::calc() {
	this->payment = calcBase(this->salary, this->worktime);
}

void Cleaner::printInfo() {
	std::cout << "#" << this->id << ". " << posToString(this->position) 
		<< " " << this->name << " [personal staff]" << std::endl;
	std::cout << "З/п: " << this->salary << "; отработано (ч): " 
		<< this->worktime << ". Заработано: " 
		<< this->payment << std::endl << std::endl;
}
