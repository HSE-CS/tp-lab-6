// Copyright 2021
#ifndef INCLUDE_PROGRAMMER_H_
#define INCLUDE_PROGRAMMER_H_
#include <string>
#include "Engineer.h"

class Programmer : public Engineer {
 public:
    Programmer(int id, std::string name,
        std::string position, double salary, Project* project)
        : Engineer(id, name, position, salary, project) {}
    double calcBonus() override;
    double calcProAdditions() override;
    void calc() override;
};
#endif  // INCLUDE_PROGRAMMER_H_
