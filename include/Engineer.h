#pragma once

#include "Employee.h"
#include "Project.h"

class Engineer : public Employee, public Project
{
protected:
	int base;
	
public:
	Engineer(int id_, string name_, int worktime_, int base_);
	virtual int calculate_working_time_payment();
	int project_payment_calculate();
	void calculate();
};