// Copyright 2021 soda
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Interfaces.h"

class Project {
 private:
    size_t id;
    size_t budget;
    std::string name;
    std::vector<Employee*>* employees;
    size_t part;

 public:
    Project(size_t id, size_t budget, std::string name);
    void hireWorker(Employee*);
    size_t getId();
    size_t getBudget();
    std::string getName();
    size_t getNumWorker();
    void setPart();
    size_t getPart();
};

#endif  // INCLUDE_FACTORY_H_
