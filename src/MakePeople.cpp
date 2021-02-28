// Copyright 2021 Краюшкина Екатерина

#include "MakePeople.h"


Cleaner* make_cleaner(int id_, string name_, int worktime_, int base_)
{
	Cleaner* cleaner = new Cleaner(id_, name_, worktime_, base_);
	return cleaner;
}

Driver* make_driver(int id_, string name_, int worktime_, int base_)
{
	Driver* driver = new Driver(id_, name_, worktime_, base_);
	return driver;
}

Programmer* make_programmer(int id, string name_, int worktime_, int base_)
{
	Programmer* programmer = new Programmer(id, name_, worktime_, base_);
	return programmer;
}

Tester* make_tester(int id_, string name_, int worktime_, int base_)
{
	Tester* tester = new Tester(id_, name_, worktime_, base_);
	return tester;
}

TeamLeader* make_team_leader(int id_, string name_, int worktime_, int base_)
{
	TeamLeader* team_leader = new TeamLeader(id_, name_, worktime_, base_);
	return team_leader;
}

Manager* make_manager(int id_, string name_, int worktime_)
{
	Manager* manager = new Manager(id_, name_, worktime_);
	return manager;
}

ProjectManager* make_project_manager(int id_, string name_, int worktime_)
{
	ProjectManager* project_manager = new ProjectManager(id_, name_, worktime_);
	return project_manager;
}

SeniorManager* make_senior_manager(int id_, string name_, int worktime_)
{
	SeniorManager* senior_manager = new SeniorManager(id_, name_, worktime_);
	return senior_manager;
}