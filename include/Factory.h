// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"
#include "Manager.h"


class Staff {
    friend class Employee;
    friend class Project;

 private:
    std::vector<Employee*> staff;
    std::vector<Project*> projects;

 public:
    Staff() {}
    void makeStaff(std::ifstream file);
    void printStaff();
    void addTimeToAll(int time);
    void calcAll();
    void addMember(Employee* newmember);
    int staffNumber();
    int projectsNumber();
    int returnPayment(std::string ID);
    Employee* findMember(std::string ID);
    Project* findProject(std::string name);
};

#endif   // INCLUDE_FACTORY_H_
