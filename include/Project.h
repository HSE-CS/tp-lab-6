#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Project
{
private:
	string name;
	int budget;

public:
	Project();
	Project(string name_, int budget_);
	int Quantity_TeamLeaders = 0;
	int Quantity_Managers = 0;
	int Quantity_Programmers = 0;
	int Quantity_Testers = 0;

	int Sal_Per_TeamLeader = 0;
	int Sal_Per_Manager = 0;
	int Sal_Per_ProjectManager = 0;
	int Sal_Per_Programmer = 0;
	int Sal_Per_Tester = 0;
	
	int Quantity_Of_All();
	string get_name_();
	int get_budget_();
};