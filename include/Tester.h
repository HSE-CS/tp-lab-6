// Copyright 2021
#ifndef INCLUDE_TESTER_H_
#define INCLUDE_TESTER_H_
#include "Engineer.h"
class Tester : public Engineer {

public:
    Tester(int id, std::string name,
        std::string position, int salary,
        Project* project) :
        Engineer(id, name , position, salary, project) {};
    double calcProAdditions() override;
    void calc() override;
    double calcBonus() override;
};

#endif  // INCLUDE_TESTER_H_
