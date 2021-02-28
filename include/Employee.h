// Copyright 2021 Краюшкина Екатерина

#pragma once

#include "Project.h"

class Employee
{
protected:
	int id;
	string name;
	int worktime;
	vector<Project*> proj;
	int payment;

public:
	Employee(int id_, string name_, int worktime_);
	int get_id();
	string get_name();
	void set_worktime(int worktime_);
	int get_payment();
	virtual void set_project(Project* proj_);
	virtual void del_last_project(Project* proj_);
	virtual int calculate_working_time_payment() = 0;
	virtual vector<Project*> get_project();
	virtual void calculate() = 0;
	void set_id(int id_);
};