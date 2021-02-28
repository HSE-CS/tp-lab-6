#pragma once
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public IHeading {
 private:
  std::vector<Project*> projects;

 public:
  ProjectManager(int id, std::string name, std::string position, std::vector<Project*> project)
      : Employee(id, name, position) {
    projects = project;
  }
  virtual int calcHeads() override;
  virtual void calc() override;
  virtual void printInfo() override;

};


class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  SeniorManager(int id, std::string name, std::string position, std::vector<Project*>projects) : ProjectManager(id,name,position, projects){
    this->projects = projects;
  }
  virtual void printInfo() override;
  virtual void calc() override;
};
