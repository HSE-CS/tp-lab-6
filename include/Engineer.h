#ifndef TP_LAB_6_ENGINEER_H
#define TP_LAB_6_ENGINEER_H

#include "Interfaces.h"
#include "Personal.h"
#include "Manager.h"

class Engineer : public ProjectBudget, public Personal
{
protected:
    Project project;
public:
    Engineer(unsigned int id, std::string name, unsigned int salary);
    unsigned int calcBudgetPart(float part) override = 0;
    void calc() override;
    unsigned int calcProAdditions() override = 0;
    unsigned int calcBonus() override = 0;
    void printInfo() override = 0;
};

class Programmer : public Engineer
{
public:
    Programmer(unsigned int id, std::string name, unsigned int salary, Project project);
    Programmer(unsigned int id, std::string name, unsigned int salary);
    unsigned int calcBudgetPart(float part) override;
    unsigned int calcProAdditions() override;
    unsigned int calcBonus() override;
    void printInfo() override;
};

class Tester : public Engineer
{
public:
    Tester(unsigned int id, std::string name, unsigned int salary, Project project);
    unsigned int calcBudgetPart(float part) override;
    unsigned int calcProAdditions() override;
    unsigned int calcBonus() override;
    void printInfo() override;
    Tester(unsigned int id, std::string name, unsigned int salary);
};

class TeamLeader : public Programmer, public Heading
{
public:
    TeamLeader(unsigned int id, std::string name, unsigned int salary, Project project);
    TeamLeader(unsigned int id, std::string name, unsigned int salary);
    unsigned int calcHeads() override;
    unsigned int calcBudgetPart(float part) override;
    unsigned int calcProAdditions() override;
    unsigned int calcBonus() override;
    void calc() override;
    void printInfo() override;
};

#endif //TP_LAB_6_ENGINEER_H
