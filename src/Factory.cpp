// Copyright 2021 Pavlova D.

#include "Factory.h"

/* data in the file with employees:
 * id
 * name
 * position
 * salary
 * project
 * part
 */

/* data in the file with projects:
 * id
 * name
 * budget
 */

Employee* MakeWorker(int id, std::string &name, std::string &_pos, int salary, int project, float part, std::vector<Project*> projects) {
  if (_pos == "PROJECT_MANAGER" ) {
    Position pos = Position(PROJECT_MANAGER);
    std::vector<Project*> my;
    my.push_back(projects[project-1]);

    return new ProjectManager{id, name, pos, my, part, salary};
  }
  else if (_pos == "SENIOR_MANAGER") {
    Position pos = Position(SENIOR_MANAGER);

    return new SeniorManager{id, name, pos, projects, part, salary};
  }

  else if (_pos == "TEAM_LEADER" ) {
    Position pos = Position(TEAM_LEADER);
    projects[project-1]->team+=1;

    return new TeamLeader(id, name, pos, salary, projects[project-1], part);
  }

  else if (_pos == "PROGRAMMER" ) {
    Position pos = Position(PROGRAMMER);
    projects[project-1]->team+=1;

    return new Programmer(id, name, pos, salary, projects[project-1], part);
  }

  else if (_pos == "TESTER" ) {
    Position pos = Position(TESTER);

    return new Tester(id, name, pos, salary, projects[project-1], part);
  }

  else if (_pos == "CLEANER" ) {
    Position pos = Position(CLEANER);

    return new Cleaner(id, name, pos, salary);
  }

  else if (_pos == "DRIVER" ) {
    Position pos = Position(DRIVER);

    return new Driver(id, name, pos, salary);
  }

  return nullptr;
}

std::vector<Employee *> StaffFactory::makeStaff() {
  std::ifstream data("../../include/data/datafile.txt");
  int id = 0;
  std::string tmp;
  std::string tmppos;
  std::string name;
  Position pos;
  int salary = 0;
  int projid = 0;
  float part = 0;

  std::ifstream data2("../../include/data/projects.txt");
  std::vector<Project*> projects;
  int prid = 0;
  std::string prname;
  int budget = 0;

  if (data2.is_open()) {
    while (!data2.eof()) {
      getline(data2, tmp);
      if (!tmp.empty()) {
        prid = atoi(tmp.c_str());
        getline(data2, prname);
        getline(data2, tmp);
        budget = atoi(tmp.c_str());

        projects.push_back(new Project{prid, prname, budget});
      }
    }
  }

  std::vector<Employee*> staff;

  if (data.is_open()) {
    while (!data.eof()) {
      getline(data, tmp);
      if (!tmp.empty()) {
        id = atoi(tmp.c_str());
        getline(data, name);
        getline(data, tmppos);
        getline(data, tmp);
        salary = atoi(tmp.c_str());
        getline(data, tmp);
        projid = atoi(tmp.c_str());
        getline(data, tmp);
        part = atoi(tmp.c_str());

        staff.push_back(MakeWorker(id, name, tmppos, salary, projid, part, projects));
      }
    }
  }

  return staff;
}
