// Copyright 2021 Краюшкина Екатерина

#pragma once

#include "Employee.h"
#include "Project.h"

class Manager : public Employee, public Project
{
public:
	Manager(int id_, string name_, int worktime_);
	int project_payment_calculate();
	virtual int calculate_working_time_payment() override;
	void calculate();
};