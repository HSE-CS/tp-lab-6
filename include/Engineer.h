// Copyright 2021 soda
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <vector>
#include <string>
#include "Interfaces.h"


class Engineer : public Employee {
private:
    Project* project{};
    size_t salary;
public:
    void setSalary(size_t salary);
    size_t calcBase();
    size_t getSalary();
    void setProject(Project*);
    size_t calcBugetPart();
    std::string getProjectName();
    Project* getProj();
};

class Programmer : public Engineer {
public:
    Programmer();
    Programmer(size_t id, std::string name, size_t worktime,
        size_t position, Project* proj, size_t salary);
    size_t calcProAdittions();
    size_t calc();
    void printInfo();
};

class Tester : public Engineer {
public:
    Tester(size_t id, std::string name, size_t worktime,
        size_t position, Project* proj, size_t salary);
    size_t calcProAdittions();
    size_t calc();
    void printInfo();
};

class TeamLeader : public Programmer {
public:
    TeamLeader(size_t id, std::string name, size_t worktime,
        size_t position, Project* proj, size_t salary);
    size_t calc();
    size_t calcProAdittions();
    size_t calcHeads();
    void printInfo();
};
#endif  // INCLUDE_ENGINEER_H_
