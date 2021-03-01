// Copyright 2021 Bekina Svetlana
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Personal.h"
#include "Interfaces.h"

class Engineer: public Personal, public ProjectBudget {
 public:
    Engineer();
    explicit Engineer(std::string id, std::string name,
        std::string position, int salary, Project new_project)
        :Personal(id, name, position, salary) {
        project = new_project;
    }
    int calcBugetPart(float, int) override;
    void calc() override;
    int calcProAdditins() override;
    void printInfo() override;

 private:
    Project project;
};

class Programmer: public Engineer {
 public:
    Programmer();
    explicit Programmer(std::string id, std::string name,
        std::string position, int salary, Project project)
        :Engineer(id, name, position, salary, project) {}
    int calcProAdditins() override;
};

class Tester : public Engineer {
 public:
    Tester();
    explicit Tester(std::string id, std::string name,
        std::string position, int salary, Project project)
        :Engineer(id, name, position, salary, project) {}
    int calcProAdditins() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader();
    explicit TeamLeader(std::string id, std::string name,
        std::string position, int salary, Project project)
        :Programmer(id, name, position, salary, project) {}
    int calcProAdditins() override;
    int calcHeads();
};
#endif  // INCLUDE_ENGINEER_H_
