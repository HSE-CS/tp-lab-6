// Copyright 2021 Краюшкина Екатерина

#define _CRT_SECURE_NO_WARNINGS

#include "MakePeople.h"
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#define Work_Time_ 160
#define cleaner_base 100
#define driver_base 170
#define programmer_base 220
#define tester_base 180
#define teamleader_base 300


int id_ = 1;

using namespace std;

vector<string> split(const string& str, char separator)
{
	vector<string> Tokens;
	string Token;
	istringstream TokenStream(str);
	while (getline(TokenStream, Token, separator))
		Tokens.push_back(Token);
	return Tokens;
}


int main()
{
	ifstream file1("Employee.txt");
	vector<Employee*> Workforce = {};
	vector<string> position = {};
	Information InfoOnEmployee;
	int i = 0;
	while (!file1.eof())
	{
		string buf;
		getline(file1, buf, '\n');
		vector<string> data = split(buf, ':');
		
		InfoOnEmployee.id = id_;
		id_++;
		InfoOnEmployee.name = data[0];
		InfoOnEmployee.position = data[1];
		InfoOnEmployee.worktime = Work_Time_;

		if (InfoOnEmployee.position == "Cleaner")
		{
			Workforce.push_back(make_cleaner(id_, InfoOnEmployee.name, InfoOnEmployee.worktime, cleaner_base));
		}
		if (InfoOnEmployee.position == "Driver")
		{
			Workforce.push_back(make_driver(id_, InfoOnEmployee.name, InfoOnEmployee.worktime, driver_base));
		}
		if (InfoOnEmployee.position == "Programmer")
		{
			Workforce.push_back(make_programmer(id_, InfoOnEmployee.name, InfoOnEmployee.worktime, programmer_base));
		}
		if (InfoOnEmployee.position == "Tester")
		{
			Workforce.push_back(make_tester(id_, InfoOnEmployee.name, InfoOnEmployee.worktime, tester_base));
		}
		if (InfoOnEmployee.position == "TeamLeader")
		{
			Workforce.push_back(make_team_leader(id_, InfoOnEmployee.name, InfoOnEmployee.worktime, teamleader_base));
		}
		
		position.push_back(InfoOnEmployee.position);
		i++;
	}
	ifstream file2("Projects.txt");
	vector<Project*> projects = {};
	while (!file2.eof())
	{
		string buf;
		int i = 2;
		getline(file2, buf, '\n');
		vector<string> data = split(buf, ';');	// format: project, budget, title, quantity, percentage on team, next title...

		Project* project = new Project(data[0], stoll(data[1]));		// stoll is for converting string to long long

		while (i < data.size())
		{
			
			if (data[i] == "Programmer")
			{
				project->Quantity_Programmers = stoi(data[++i]);		// stoi is for converting string to int
				project->Sal_Per_Programmer = stoi(data[++i]) / project->Quantity_Programmers;
			}
			if (data[i]  == "Tester")
			{
				project->Quantity_Testers = stoi(data[++i]);
				project->Sal_Per_Tester = stoi(data[++i]) / project->Quantity_Testers;
			}
			if (data[i] == "TeamLeader")
			{
				project->Quantity_TeamLeaders = stoi(data[++i]);
				project->Sal_Per_TeamLeader = stoi(data[++i]) / project->Quantity_TeamLeaders;
			}
			if (data[i] == "Manager")
			{
				project->Quantity_Managers = stoi(data[++i]);
				project->Sal_Per_Manager = stoi(data[++i]) / project->Quantity_Managers;
			}
			if (data[i] == "ProjectManager")
			{
				project->Sal_Per_ProjectManager = stoi(data[++i]);
			}
			i++;
		}
		projects.push_back(project);
	}

	for (int i = 0; i < projects.size(); i++)
	{
		for (int j = 0; j < projects[i]->Quantity_Programmers; j++)	// assembling a team of programmers
		{
			for (int k = 0; k < Workforce.size(); k++)
			{
				if ((position[k] == "Programmer") && ((Workforce[k]->get_project()).empty()))
				{
					Workforce[k]->set_project(projects[i]);
					break;
				}
			}
		}
		for (int j = 0; j < projects[i]->Quantity_Testers; j++)
		{
			for (int k = 0; k < Workforce.size(); k++)
			{
				if ((position[k] == "Tester") && ((Workforce[k]->get_project()).empty()))
				{
					Workforce[k]->set_project(projects[i]);
					break;
				}
			}
		}
		for (int j = 0; j < projects[i]->Quantity_TeamLeaders; j++)
		{
			for (int k = 0; k < Workforce.size(); k++)
			{
				if ((position[k] == "TeamLeader") && ((Workforce[k]->get_project()).empty()))
				{
					Workforce[k]->set_project(projects[i]);
					break;
				}
			}
		}
		for (int j = 0; j < projects[i]->Quantity_Managers; j++)
		{
			for (int k = 0; k < Workforce.size(); k++)
			{
				if ((position[k] == "Manager") && ((Workforce[k]->get_project()).empty()))
				{
					Workforce[k]->set_project(projects[i]);
					break;
				}
			}
		}

		for (int k = 0; k < Workforce.size(); k++)
		{
			if ((position[k] == "ProjectManager") && ((Workforce[k]->get_project()).empty()))
			{
				Workforce[k]->set_project(projects[i]);
				break;
			}
		}

		Workforce[51]->set_project(projects[i]);
	}

// TODO âûâîä äàííûõ ïî ðàáîòíèêàì	-	DONE

	for (int i = 0; i < Workforce.size(); i++)
	{
		if (Workforce[i]->get_payment() == programmer_base)
		{
			cout << Workforce[i]->get_name() << " earns " << Workforce[i]->get_payment() << " and works at " << Workforce[i]->get_project()[0] << endl;
		}
	}

	for (int i = 0; i < Workforce.size(); i++)
	{
		if (Workforce[i]->get_payment() == tester_base)
		{
			cout << Workforce[i]->get_name() << " earns " << Workforce[i]->get_payment() << " and works at " << Workforce[i]->get_project()[0] << endl;
		}
	}

	for (int i = 0; i < Workforce.size(); i++)
	{
		if (Workforce[i]->get_payment() == driver_base)
		{
			cout << Workforce[i]->get_name() << " earns " << Workforce[i]->get_payment() << endl;
		}
	}

	for (int i = 0; i < Workforce.size(); i++)
	{
		if (Workforce[i]->get_payment() == cleaner_base)
		{
			cout << Workforce[i]->get_name() << " earns " << Workforce[i]->get_payment() << endl;
		}
	}

	for (int i = 0; i < Workforce.size(); i++)
	{
		if (Workforce[i]->get_payment() == teamleader_base)
		{
			Workforce[i]->calculate();
			cout << Workforce[i]->get_name() << " earns " << Workforce[i]->get_payment() << " and works at " << Workforce[i]->get_project()[0] << endl;
		}
	}

	for (int i = 0; i < Workforce.size(); i++)
	{
		if (position[i] == "ProjectManager")
		{
			Workforce[i]->calculate();
			cout << Workforce[i]->get_name() << " earns " << Workforce[i]->get_payment() << " and works at " << Workforce[i]->get_project()[0] << endl;
		}
	}


	return 0;
}