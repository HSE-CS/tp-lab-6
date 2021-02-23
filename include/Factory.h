//// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Project {
public:
    int id;
    std::string name;
    int budget;
    Project(int id, std::string name, int budget) {
        this->id = id;
        this->name = name;
        this->budget = budget;
    }
};

#endif  // INCLUDE_FACTORY_H_
