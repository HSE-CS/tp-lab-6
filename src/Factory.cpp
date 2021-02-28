// Copyright 2021 Kuznetsov Mikhail

#include "Factory.h"


std::vector<Employee *> StaffFactory::makeStaff(std::string _projectsFile,
                                                std::string _employeesFile) {
  std::ifstream fproj(_projectsFile);
  std::vector <Project*> companyProjects;
  std::string input;
  while (getline(fproj, input)) {
    unsigned int pos = input.find(':');
    unsigned int id = std::stoi(input.substr(0, pos));
    input = input.substr(pos + 1, input.size() - pos - 1);
    unsigned int budget = std::stoi(input);
    Project* project = new Project(id, budget);
    companyProjects.push_back(project);
  }
  fproj.close();
  std::ifstream femp(_employeesFile);
  std::vector <Employee*> staff;
  while (getline(femp, input)) {
    unsigned int pos = input.find(':');
    unsigned int id = std::stoi(input.substr(0, pos));
    input = input.substr(pos + 1, input.size() - pos - 1);
    pos = input.find(':');
    std::string name = input.substr(0, pos);
    input = input.substr(pos + 1, input.size() - pos - 1);
    pos = input.find(':');
    std::string stringPosition = input.substr(0, pos);
    input = input.substr(pos + 1, input.size() - pos - 1);
    POSITION position = positionByString(stringPosition);
    pos = input.find(':');
    unsigned int salary;
    Project* project;
    std::vector <Project*> projects;
    if (position == PROGRAMMER || position == TESTER ||
        position == TEAMLEADER || position == DRIVER || position == CLEANER) {
      salary = std::stoi(input.substr(0, pos));
      input = input.substr(pos + 1, input.size() - pos - 1);
      pos = input.find(':');
    }

    if (position == PROGRAMMER || position == TESTER ||
        position == TEAMLEADER) {
      unsigned int projectId = std::stoi(input.substr(0, pos));
      for (auto p : companyProjects) {
        if (projectId == p->id) {
          project = p;
        }
      }
    } else if (position == PROJECTMANAGER || position == SENIORMANAGER) {
      while (pos != std::string::npos) {
        unsigned int projectId = std::stoi(input.substr(0, pos));
        for (auto p : companyProjects) {
          if (projectId == p->id) {
            projects.push_back(p);
          }
        }
        input = input.substr(pos + 1, input.size() - pos - 1);
        pos = input.find(':');
      }
    }
    if (position == SENIORMANAGER) {
      SeniorManager* employee = new SeniorManager(id, name,
                                                  position, projects);
      staff.push_back(employee);
    } else if (position == PROJECTMANAGER) {
      ProjectManager* employee = new ProjectManager(id, name,
                                                    position, projects);
      staff.push_back(employee);
    } else if (position == TEAMLEADER) {
      TeamLeader* employee = new TeamLeader(id, name,
                                            position, salary, project);
      staff.push_back(employee);
    } else if (position == PROGRAMMER) {
      Programmer* employee = new Programmer(id, name,
                                            position, salary, project);
      staff.push_back(employee);
      project->programmers++;
    } else if (position == TESTER) {
      Tester* employee = new Tester(id, name,
                                    position, salary, project);
      staff.push_back(employee);
      project->testers++;
    } else if (position == DRIVER) {
      Driver* employee = new Driver(id, name,
                                    position, salary);
      staff.push_back(employee);
    } else if (position == CLEANER) {
      Cleaner* employee = new Cleaner(id, name,
                                      position, salary);
      staff.push_back(employee);
    }
  }
  femp.close();
  return staff;
}
