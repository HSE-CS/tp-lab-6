// Copyright 2021
#ifndef INCLUDE_TEAMLEADER_H_
#define INCLUDE_TEAMLEADER_H_
#include <string>
#include "Programmer.h"
#include "Heading.h"

class TeamLeader : public Programmer, Heading {
 public:
    TeamLeader(int id, std::string name,
        std::string position, int salary, Project* project)
        : Programmer(id, name, position, salary, project) {}
    int calcHeads() override;
    void calc() override;
    void printInfo() override;
};
#endif  // INCLUDE_TEAMLEADER_H_
