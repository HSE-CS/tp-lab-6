// Copyright 2021 Krayushkina

#pragma once
#define PERSONAL_H
#ifdef PERSONAL_H
#include <string>
#include "Employee.h"
#include "Interfaces.h"
class Personal : public Employee, public WorkBaseTime {
public:
	Personal(std::string name, unsigned int id, float base,
		std::string position);
	float getPaymentbyWorkTime() override;
protected:
	float base1;
	std::string base;
	std::string position;
};
class Cleaner : public Personal {
public:
	Cleaner(std::string name, unsigned int id, float base,
		std::string position);
	float getPayment() override;
};
class Driver : public Personal {
public:
	Driver(std::string name, unsigned int id, float base,
		std::string position, float koef);
	float getPayment() override;
private:
	float koef;
};
#endif // PERSONAL_H