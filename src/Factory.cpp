// Copyright NikDemoShow 2021
#include"Factory.h"

Position getPos(const std::string str) {
  if (str == "Driver") {
    return Position::Driver;
  } else if (str == "Cleaner") {
    return Position::Cleaner;
  } else if (str == "Tester") {
    return Position::Tester;
  } else if (str == "Programmer") {
    return Position::Programmer;
  } else if (str == "TeamLeader") {
    return Position::TeamLeader;
  } else if (str == "ProjectManager") {
    return Position::ProjectManager;
  } else if (str == "SeniorManager") {
    return Position::SeniorManager;
  }
}

std::vector<Employee*> Factory::makeStaff(const std::string dir) {
  std::ifstream file(dir);
  if (file) {
    std::string str;
    while (getline(file, str)) {
      std::stringstream stream(str);
      unsigned int id, salary{0}, bonus{0}, proAdd{0}, subord{0};
      double part{0};
      std::string name, sPos;
      std::vector<Project*> projects;
      stream >> id >> name >> sPos;
      Position pos{getPos(sPos)};
      if (pos != Position::SeniorManager || pos != Position::ProjectManager) {
        stream >> salary;
        if (pos == Position::Driver) {
          stream >> bonus;
        }
      }
      if (pos != Position::Cleaner || pos != Position::Driver) {
        stream >> part;
        if (pos == Position::Programmer || pos == Position::TeamLeader ||
            pos == Position::Tester) {
          stream >> proAdd;
        }
        if (pos == Position::ProjectManager || pos == Position::SeniorManager ||
            pos == Position::TeamLeader) {
          stream >> subord;
        }
        unsigned int pid, budget;
        while (stream >> pid) {
          stream >> budget;
          Project* pr = new Project(pid, budget);
          projects.push_back(pr);
        }
      }
      Employee* emp;
      switch (pos) {
        case Position::Cleaner:
          emp = new Cleaner(id, name, pos, salary);
          break;
        case Position::Driver:
          emp = new Driver(id, name, pos, salary, bonus);
          break;
        case Position::ProjectManager:
          emp = new ProjectManager(id, name, pos, part, subord, projects);
          break;
        case Position::SeniorManager:
          emp = new SeniorManager(id, name, pos, part, subord, projects);
          break;
        case Position::Programmer:
          emp = new Programmer(id, name, pos, salary,
            part, proAdd, projects[0]);
          break;
        case Position::Tester:
          emp = new Tester(id, name, pos, salary,
            part, proAdd, projects[0]);
          break;
        case Position::TeamLeader:
          emp = new TeamLeader(id, name, pos, salary, part, proAdd, subord,
                               projects[0]);
      }
      this->staff.push_back(emp);
    }
  } else {
    std::cout << "Wrong directory" << std::endl;
  }
  return staff;
}
