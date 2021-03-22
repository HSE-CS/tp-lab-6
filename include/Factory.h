// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include "Manager.h"
#include <vector>
class Factory{
 public:
    std::vector<Employee*> createWorkers();
    std::vector<Project> createProjects();
};
#endif  // INCLUDE_FACTORY_H_
