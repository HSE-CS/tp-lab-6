#ifndef PERSONAL_H
#define PERSONAL_H

#include <iostream>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
protected:
	unsigned int salary;
public:
	Personal(unsigned int id, std::string name, Position position, unsigned int salary);

	unsigned int calcBase(unsigned int salary, unsigned int wtime);

	unsigned int calcBonus();

	void printInfo();
};

class Driver : public Personal {
public:
	Driver(unsigned int id, std::string name, Position position, unsigned int salary);
	void calc();
};

class Cleaner : public Personal {
public:
	Cleaner(unsigned int id, std::string name, Position position, unsigned int salary);
	void calc();
};

#endif