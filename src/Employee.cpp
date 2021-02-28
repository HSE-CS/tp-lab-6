// Copyright 2021 Краюшкина Екатерина

#include "Employee.h"

Employee::Employee(int id_, string name_, int worktime_)
{
	id = id_;
	name = name_;
	worktime = worktime_;
	payment = 0;
	proj = {};
}

int Employee::get_id()
{
	return id;
}

void Employee::set_id(int id_)
{
	id = id_;
}


string Employee::get_name()
{
	return name;
}

void Employee::set_worktime(int worktime_)
{
	if (worktime_ >= 0)
	{
		worktime = worktime_;
	}
}

int Employee::get_payment()
{
	return payment;
}

void Employee::set_project(Project* proj_)
{
	proj.push_back(proj_);
}

void Employee::del_last_project(Project* proj_)
{
	proj.pop_back();
}

vector<Project*> Employee::get_project()
{
	return proj;
}