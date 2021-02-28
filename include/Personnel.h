// Copyright 2021 Краюшкина Екатерина

#pragma once

#include "Employee.h"

class Personnel : public Employee
{
protected:
	int base;
public:
	Personnel(int id_, string name_, int worktime_, int base_);
	int calculate_working_time_payment() override;
	void calculate();
	int get_base();
	void set_base(int base_);
};