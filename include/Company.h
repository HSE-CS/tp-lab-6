// Copyright 2021 soda
#ifndef INCLUDE_COMPANY_H_
#define INCLUDE_COMPANY_H_

#include "Interfaces.h"

class Company {
 private:
    std::vector<Employee*>* all_employee;
    std::vector<Project*>* all_projects;

 public:
    Company();
    void create_all_projects();
    void create_all_employee();
    Project* getProject(size_t);
    Employee* getEmployee(size_t);
    size_t getEmployeeNum();
    size_t getProjectNum();
    void set_all_payment();
    uint64_t avarage_payment();
    void print_all_info();
};

#endif  // INCLUDE_COMPANY_H_
