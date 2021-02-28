// Copyright 2021 Краюшкина Екатерина

#include "Project.h"

Project::Project()
{
}

Project::Project(string name_, int budget_)
{
	name = name_;
	budget = budget_;
}

int Project::Quantity_Of_All()
{
	return Quantity_Programmers + Quantity_Testers + Quantity_TeamLeaders + Quantity_Managers;
}

string Project::get_name_()
{
	return name;
}

int Project::get_budget_()
{
	return budget;
}