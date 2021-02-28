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
    switch (std::stoi(pos)) {
      case 0:Cleaner q0(id, name, Position(cleaner), 0, 0);
        buff2.push_back(q0);
        break;
      case 1:Driver q1(id, name, Position(driver), 0, 0);
        buff2.push_back(q1);
        break;
      case 2:Tester q2(id, name, Position(tester), 0, nullptr, 0);
        buff2.push_back(q2);
        break;
      case 3:Programmer q3(id, name, Position(programmer), 0, nullptr, 0);
        buff2.push_back(q3);
        break;
      case 4:TeamLeader q4(id, name, Position(team_Leader), 0, nullptr, 0);
        buff2.push_back(q4);
        break;
      case 5:SeniorManager q5(id, name, Position(senior_Manager), 0, 0, nullptr);
        buff2.push_back(q5);
        break;
      case 6:ProjectManager q6(id, name, Position(project_Manager), 0, 0, nullptr);
        buff2.push_back(q6);
        break;
      default:return;
    }
  }
  in2.close();
}

Project::Project(std::string id, int budget) {
  this->id = id;
  this->budget = budget;
}
