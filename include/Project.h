// Copyright 2021
#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_
#include <string>

class Project {

private:
    int id;
    double budget;
    int members;
    int programmers;
    std::string name;
public:
    Project(int id, int budget, std::string name) {
        this->id = id;
        this->budget = budget;
        members = 0;
        programmers = 0;
        this->name = name;
    }
    void AddMember();
    void AddProgrammer();
    int getMember();
    int getBudget();
    int getProgrammers();
    int getId();
    std::string getName();
};
#endif  // !INCLUDE_PROJECT_H_
