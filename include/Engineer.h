// Copyright 2021 Krayushkina

#pragma once
#define ENGINEER_H
#ifdef ENGINEER_H
#include <string>
#include "Employee.h"
#include "Interfaces.h"

class Engineer : public Employee, public WorkBaseTime, public ProjectBudget {
 public:
    Engineer(std::string name, unsigned int id,
        float base, std::string position,
        std::string project, float contribution);
    float getPaymentbyWorkTime() override;
    float getPaymentbyProject() override;
 protected:
    float base;
    float contribution;
    std::string position;
    std::string project;
};
class Tester : public Engineer {
 public:
    Tester(std::string name, unsigned int id, float base, std::string position,
        std::string project, float contribution);
    float getPayment() override;
};
class Programmer : public Engineer {
 public:
    Programmer(std::string name, unsigned int id,
        float base, std::string position,
        std::string project, float contribution);
    float getPayment() override;
}

class TeamLeader : public Programmer, public Heading {
 protected:
    unsigned int subordinates;
 public:
    TeamLeader(std::string name, unsigned int id, float base,
        std::string position,
        std::string project, float contribution,
        unsigned int subordinates);
    float getPaymentbyHeading() override;
    float getPayment() override;
};
#endif  // ENGINEER_H
