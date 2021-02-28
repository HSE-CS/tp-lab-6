// Copyright 2021 Краюшкина Екатерина

#pragma once

#include "TeamLeader.h"
#include "SeniorManager.h"
#include "Driver.h"
#include "Cleaner.h"

class Information {
public:
	string position;
	int id;
	string name;
	int worktime;
	int base;
};

Cleaner* make_cleaner(int id_, string name_, int worktime_, int base_);
Driver* make_driver(int id_, string name_, int worktime_, int base_);
Programmer* make_programmer(int id_, string name_, int worktime_, int base_);
Tester* make_tester(int id_, string name_, int worktime_, int base_);
TeamLeader* make_team_leader(int id_, string name_, int worktime_, int base_);
Manager* make_manager(int id_, string name_, int worktime_);
ProjectManager* make_project_manager(int id_, string name_, int worktime_);
SeniorManager* make_senior_manager(int id_, string name_, int worktime_);