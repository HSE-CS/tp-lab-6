// Copyright 2021 Kris


#ifndef ENGINEER_INCLUDE_H_
#define ENGINER_INCLUDE_H_
#include "Employee.h"
#include "Personal.h"
#include "Interfaces.h"

class Engineer: public Personal {
 private:
    Project project;
 public:
    Engineer(int _id, std::string _name, std::string _pos, 
        int _payment, Project currentProject);
    Project getProject();
    int calcBudgetPart(double part, int budget);
    int calcProAdditions();
    int calc();
};

class Programmer: public Engineer {
 public:
     Programmer(int _id, std::string _name, std::string _pos,
         int _payment, Project currentProject);
     int calcProAdditions();
};

class Tester: public Engineer {
 public:
     Tester(int _id, std::string _name, std::string _pos,
         int _payment, Project currentProject);
     int calcProAdditions();
};

class TeamLeader: public Programmer {
 public:
     TeamLeader(int _id, std::string _name, std::string _pos,
         int _payment, Project currentProject);
     int calcHeads();
     int calc();
};

#endif // !ENGINEER_INCLUDE_H_
