// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include <iostream>
#include "Personal.h"
#include "Interfaces.h"
#include "Manager.h"


class Project;

class Engineer : public Personal, public ProjectBudget {
 protected:
    Project* project;

 public:
    Engineer(unsigned int _id, std::string _name,
           POSITION _position, unsigned int _salary,
           Project* _project);
    unsigned int calcBudgetPart(float _part,
                                unsigned int _budget) override;
    void calc() override;
    void printInfo() override;
    Project* getProject();
};


class Programmer : public Engineer {
 public:
    Programmer(unsigned int _id, std::string _name,
           POSITION _position, unsigned int _salary,
           Project* _project);
    unsigned int calcProAdditions() override;
};

class Tester : public Engineer {
 public:
    Tester(unsigned int _id, std::string _name,
           POSITION _position, unsigned int _salary,
           Project* _project);
    unsigned int calcProAdditions() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(unsigned int _id, std::string _name,
           POSITION _position, unsigned int _salary,
           Project* _project);
    void calc() override;
    unsigned int calcHeads() override;
};


#endif  //  INCLUDE_ENGINEER_H_
