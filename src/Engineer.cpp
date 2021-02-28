// Copyright 2021 Краюшкина Екатерина

#include "Engineer.h"

Engineer::Engineer(int id_, string name_, int worktime_, int base_) : Employee(id_, name_, worktime_)
{
	base = base_;
	proj = {};
}

int Engineer::calculate_working_time_payment()
{
	return worktime * base;
}

int Engineer::project_payment_calculate()
{
	return 0;
}

void Engineer::calculate()
{
	payment = calculate_working_time_payment() + project_payment_calculate();
}