// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
class Personal : public Employee, public IWorkBaseTime {
 protected:
	int salary;
 public:
	Personal(int id, std::string name, int salary);
	int getSalary() {
		return this->salary;
	}
	int calcBase(int salary, int wtime) override;
};

class Driver : public Personal {
 public:
	Driver(int id, std::string name, int salary);
	int calcBonus() override;
	void calc() override;
	void printInfo() override;
};

class Cleaner : public Personal {
 public:
	Cleaner(int id, std::string name, int salary);
	void calc() override;
	void printInfo() override;
	int calcBonus() override {
		return 0;
	}
};

#endif  INCLUDE_PERSONAL_H_
