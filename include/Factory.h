// Copyright 2021 MalininDmitry

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include <vector>
#include "Employee.h"


class Project{
 public:
    int id;
    int budget;

    int GetId() const;

    void SetId(int id);

    int GetBudget() const;

    void SetBudget(int budget);
};

class StaffFactory {
 public:
    static std::vector<Employee*> makeStaff();
};
#endif  // INCLUDE_FACTORY_H_

