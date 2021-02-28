// Copyright 2021 mkhorosh

#include "Employee.h"
#include "Factory.h"
#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"
#include "Interfaces.h"
#include <vector>
#include <fstream>

Factory::Factory(std::string filenamestaff, std::string fileproj) {
  this->filestaff = filestaff;
  this->fileproj = fileproj;
}

void Factory::readData() {
  std::string line;
  std::vector<Project> buff;
  std::ifstream in(fileproj);
  while (getline(in, line)) {
    std::string id;
    int ind = line.find(" ");
    id = line.substr(0, ind + 1);
    std::string bud;
    bud = line.substr(ind + 1, line.size() - ind + 1);
    Project pr(id, std::stoi(bud));
    buff.push_back(pr);
  }
  in.close();
  std::string line2;
  std::vector<Employee> buff2;
  std::ifstream in2(filestaff);
  while (getline(in2, line2)) {
    std::string id;
    int ind = line.find(" ");
    id = line.substr(0, ind + 1);
    std::string name;
    name = line.substr(ind + 1, line.size() - ind + 1);
    std::string pos;
    pos = line.substr(ind + 1, line.size() - ind + 1);
    int check = std::stoi(pos);
    if (check == 0) {
      Cleaner q0(id, name, Position(cleaner), 0, 0);
      buff2.push_back(q0);
    } else if (check == 1) {
      Driver q1(id, name, Position(driver), 0, 0);
      buff2.push_back(q1);
    } else if (check == 2) {
      Tester q2(id, name, Position(tester), 0, nullptr, 0);
      buff2.push_back(q2);
    } else if (check == 3) {
      Programmer q3(id, name, Position(programmer), 0, nullptr, 0);
      buff2.push_back(q3);
    } else if (check == 4) {
      TeamLeader q4(id, name, Position(team_Leader), 0, nullptr, 0);
      buff2.push_back(q4);
    } else if (check == 5) {
      SeniorManager q5(id, name, Position(senior_Manager), 0, 0, nullptr);
      buff2.push_back(q5);
    } else if (check == 6) {
      ProjectManager q6(id, name, Position(project_Manager), 0, 0, nullptr);
      buff2.push_back(q6);
    }
  }
  in2.close();
}

Project::Project(std::string id, int budget) {
  this->id = id;
  this->budget = budget;
}
