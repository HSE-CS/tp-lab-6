// Copyright 2020 Uskova

#include "Factory.h"

#include <iostream>
#include <string>

#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"

std::vector<Employee*> readWorkers(std::string file_name, Project* project) {
  std::ifstream file;
  file.open(file_name);
  if (!file.is_open()) {
    std::cerr << "Error of opening the file!" << std::endl;
    exit(-1);
  }
  std::vector<Employee*> workers;
  Employee* current;
  std::string fio, str_id, str_pos, str_worktime, str_salary, str_coef, str;
  int id = 0, worktime = 0, salary = 0, coef = 0;
  Position pos;
  while (!file.eof()) {
    getline(file, str_id, ';');
    id = stoi(str_id);
    getline(file, fio, ';');
    getline(file, str_pos, ';');
    if (stoi(str_pos) == 0 || stoi(str_pos) == 1 || stoi(str_pos) == 2 ||
        stoi(str_pos) == 5 || stoi(str_pos) == 6) {
      getline(file, str_worktime, ';');
      worktime = stoi(str_worktime);
      getline(file, str_salary, ';');
      salary = stoi(str_salary);
      if (stoi(str_pos) == 0 || stoi(str_pos) == 1 || stoi(str_pos) == 5) {
        getline(file, str_coef, ';');
        coef = stoi(str_coef);
      }
      getline(file, str);
    } else {
      getline(file, str);
    }
    switch (stoi(str_pos)) {
      case 0:
        pos = Position::Tester;
        current = new Tester(id, fio, pos, worktime, salary, coef, project);
        break;
      case 1:
        pos = Position::Programmer;
        current = new Programmer(id, fio, pos, worktime, salary, coef, project);
        break;
      case 2:
        pos = Position::TeamLeader;
        current = new TeamLeader(id, fio, pos, worktime, salary, project);
        break;
      case 3:
        pos = Position::SeniorManager;
        current = new SeniorManager(id, fio, pos, project);
        break;
      case 4:
        pos = Position::ProjectManager;
        current = new ProjectManager(id, fio, pos, project);
        break;
      case 5:
        pos = Position::Driver;
        current = new Driver(id, fio, pos, worktime, salary, coef);
        break;
      case 6:
        pos = Position::Cleaner;
        current = new Cleaner(id, fio, pos, worktime, salary);
        break;
    }
    workers.push_back(current);
  }
  return workers;
}

Employee* apdate(Employee* data, Project* project) {
  Employee* current  = nullptr;
  Tester* t0 = static_cast<Tester*>(data);
  Programmer* t1 = static_cast<Programmer*>(data);
  TeamLeader* t2 = static_cast<TeamLeader*>(data);
  switch (data->getPosition()) {
    case Position::Tester:
      current = new Tester(data->getId(), data->getName(), data->getPosition(),
                           data->getWorktime(), t0->getSalary(), t0->getCoef(),
                           project);
      break;
    case Position::Programmer: {
      current = new Programmer(data->getId(), data->getName(),
                               data->getPosition(), data->getWorktime(),
                               t1->getSalary(), t1->getCoef(), project);
      break;
    }
    case Position::TeamLeader: {
      current =
          new TeamLeader(data->getId(), data->getName(), data->getPosition(),
                         data->getWorktime(), t2->getSalary(), project);
      break;
    }
    case Position::SeniorManager: {
      current = new SeniorManager(data->getId(), data->getName(),
                                  data->getPosition(), project);
      break;
    }
    case Position::ProjectManager: {
      current = new ProjectManager(data->getId(), data->getName(),
                                   data->getPosition(), project);
      break;
    }
  }
  return current;
}
