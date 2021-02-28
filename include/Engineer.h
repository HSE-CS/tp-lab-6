// Copyright 2021 Sozinov Kirill

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"
#include <vector>

//class Project;

//class Engineer;

class Project {
    friend class Engineer;
    friend class ProjectManager;
private:
    int id;
    int budget;
    int team_size;

public:
    Project(int _id, int _budget, int _team_size) :
        id(_id), budget(_budget), team_size(_team_size) {}
    int getTeamSize();
    int getBudget();
    int getId();
};

class Engineer : public Personal, public ProjectBudget {
protected:
    Project project;
public:
    Engineer(int _id, std::string _name, std::string _position, int
        _salary, Project _pr);
    float calcBudgetPart(float part, int budget) override;
    void printInfo() override;
};

class Programmer : public Engineer {
 public:
    int calcProAdditions() override;
    Programmer(int _id, std::string _name, std::string _position, int
        _salary, Project _pr);
    void calc() override;
};

class Tester : public Engineer {
public:
    int calcProAdditions() override;
    Tester(int _id, std::string _name, std::string _position, int
        _salary, Project _pr);
    void calc() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
     TeamLeader(int _id, std::string _name, std::string _position, int
         _salary, Project _pr);
     int calcHeads() override;
     void calc() override;
     void printInfo() override;
};
#endif  // INCLUDE_ENGINEER_H_
