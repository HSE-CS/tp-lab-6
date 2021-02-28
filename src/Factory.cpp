// Copyright 2020 S. BOR

#include "Factory.h"
#include <vector>
#include <sstream>
#include <fstream>

std::vector<Employee *> Factory::fileRead(std::string fileName) {
  std::fstream file(fileName);
  std::vector <Employee *> empls;
  if (file.is_open()) {
    int id, position, salary;
    std::string name, sname;
    while (!file.eof()) {
      file >> id >> name >> sname >> position >> salary;
      if (position == 0) {
        Cleaner *empC = new Cleaner;
        empC->id = id;
        empC->name = name + " " + sname;
        empC->setSalary(salary);
        empC->position = CLEANER;
        empls.push_back(empC);
      } else if (position == 1) {
        Driver *empD = new Driver;
        empD->id = id;
        empD->name = name + " " + sname;
        empD->setSalary(salary);
        empD->position = DRIVER;
        empls.push_back(empD);
      } else if (position == 2) {
        Tester *empT = new Tester;
        empT->id = id;
        empT->name = name + " " + sname;
        empT->setSalary(salary);
        empT->position = TESTER;
        empls.push_back(empT);
      } else if (position == 3) {
        Programmer *empP = new Programmer;
        empP->id = id;
        empP->name = name + " " + sname;
        empP->setSalary(salary);
        empP->position = PROGRAMMER;
        empls.push_back(empP);
      } else if (position == 4) {
        TeamLeader *empTL = new TeamLeader;
        empTL->id = id;
        empTL->name = name + " " + sname;
        empTL->setSalary(salary);
        empTL->position = TEAMLEADER;
        empls.push_back(empTL);
      } else if (position == 5) {
        ProjectManager *empPM = new ProjectManager;
        empPM->id = id;
        empPM->name = name + " " + sname;
        empPM->position = PROJECTMANAGER;
        empls.push_back(empPM);
      } else if (position == 6) {
        SeniorManager *empSM = new SeniorManager;
        empSM->id = id;
        empSM->name = name + " " + sname;
        empSM->position = SENIORMANAGER;
        empls.push_back(empSM);
      }
    }
  }
  empls.pop_back();
  return empls;
}
