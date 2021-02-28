//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include "Factory.h"

// File structure
//
// Engineer: {ID} {FISRT_NAME} {SECOND_NAME}
// {POSITION_NUM} {WORKTIME} {SALARY} {PROJECT_NUM}
//
// Manager: {ID} {FISRT_NAME} {SECOND_NAME}
// {POSITION_NUM} {PROJECT_NUM}
//
// SeniorManager: {ID} {FISRT_NAME} {SECOND_NAME}
// {POSITION_NUM}
// {PROJECT_NUM1} {PROJECT_NUM2} ... {PROJECT_NUMN}
//
// Driver: {ID} {FISRT_NAME} {SECOND_NAME}
// {POSITION_NUM} {WORKTIME} {SALARY}
//
// Cleaner {ID} {FISRT_NAME} {SECOND_NAME}
// {POSITION_NUM} {WORKTIME} {SALARY}

Factory::Factory(std::string employeesFileName,
               std::string projectsFileName) {
  this->employeesFileName = employeesFileName;
  this->projectsFileName = projectsFileName;
}

void Factory::readStaff() {
  std::ifstream infileE(employeesFileName);
  std::ifstream infileP(projectsFileName);

  // read projects
  int newProjectId;
  unsigned newBudget, newMembersNum;
  
  while (infileP >> newProjectId >> newBudget >> newMembersNum) {
    Project* newProject = new Project(newProjectId, newBudget);
    newProject->setMembersNum(newMembersNum);
    projects.push_back(newProject);
  }
  
  // read employees
  int newId, newPositionNum;
  std::string newFirstName, newSecondName;
  while (infileE >> newId >> newFirstName >> newSecondName >> newPositionNum) {
    std::string fullName = newFirstName + " " + newSecondName;

    if (newPositionNum >= 0 && newPositionNum <= 2){
      // Programmer, Tester, TeamLeader
      unsigned newWorktime, newSalary, newProjectNum;
      infileE >> newWorktime >> newSalary >> newProjectNum;

      if (newPositionNum == 0){
        // * Programmer *
        Programmer* newProgrammer =
        new Programmer(newId, fullName, newWorktime,
                       newSalary, projects[newProjectNum]);
        newProgrammer->setAheadCounter(rand() % 5);
        employees.push_back(newProgrammer);
      } else if (newPositionNum == 1) {
        // * Tester *
        Tester* newTester =
        new Tester(newId, fullName, newWorktime,
                   newSalary, projects[newProjectNum]);
        newTester->setBugsCounter(rand() % 10);
        employees.push_back(newTester);
      } else {
        // * TeamLeader *
        TeamLeader* newLead =
        new TeamLeader(newId, fullName, newWorktime,
                       newSalary, projects[newProjectNum]);
        newLead->setProjectPart(0.1);
        employees.push_back(newLead);
      }
    } else if (newPositionNum == 3) {
      // * Project Manager *
      unsigned newProjectNum;
      infileE >> newProjectNum;
      ProjectManager* newManager =
      new ProjectManager(newId, fullName, projects[newProjectNum]);
      employees.push_back(newManager);
    } else if (newPositionNum == 4) {
      // * Senior Project Manager *
      std::string projectsIds;
      getline(infileE, projectsIds);
      std::stringstream ss(projectsIds);

      std::vector<Project*> newProjects;
      int newProjectId;
      while (ss >> newProjectId){
        newProjects.push_back(projects[newProjectId]);
      }
      SeniorManager* newSenior =
      new SeniorManager(newId, fullName, newProjects);
      employees.push_back(newSenior);
    } else if (newPositionNum == 5) {
      // * Cleaner *
      unsigned newWorktime, newSalary;
      infileE >> newWorktime >> newSalary;
      Cleaner* newCleaner =
      new Cleaner(newId, fullName, newWorktime, newSalary);
      employees.push_back(newCleaner);
    } else if (newPositionNum == 6) {
      // * Driver *
      unsigned newWorktime, newSalary;
      infileE >> newWorktime >> newSalary;
      Driver* newDriver =
      new Driver(newId, fullName, newWorktime, newSalary);
      newDriver->setNightHours(rand() % 5);
      employees.push_back(newDriver);
    }
  }
}

void Factory::calcAll() {
  for (Employee* e : employees) {
    e->calc();
  }
}

void Factory::printStaffInfo() {
  for (Employee* e : employees) {
    e->printInfo();
  }
}

Employee* Factory::getEmployee(unsigned index) {
  return employees[index];
}

Project* Factory::getProject(unsigned index) {
  return projects[index];
}

unsigned Factory::getProjectsSize() const {
  return projects.size();
}
unsigned Factory::getEmployeesSize() const {
  return employees.size();
}
