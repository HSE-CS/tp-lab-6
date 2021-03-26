// Copyright 2021 Krayushkina
#pragma once

#define EMPLOYEE_H
#ifdef EMPLOYEE_H
#include <string>

class Employee {
 public:
	Employee(std::string name, int id);
	virtual float getPayment() = 0;
	unsigned int getId() const;
	unsigned int getWorkTime() const;
	std::string getName() const;
	void setWorkTime(unsigned int);
 protected:
	int id;
	std::string name;
	int worktime;
	float payment = 0;
};
#endif // EMPLOYEE