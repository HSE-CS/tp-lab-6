// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"
#include "Manager.h"

class Engineer : public Personal, public IProjectBudget {
   private:
    float partOfTheProject = 0;

   protected:
    Project project = Project(-1, "None");

    int calcBudgetPart(float part, int budget) override;

    int calcProAdditions() override;

   public:
    Engineer(unsigned int id, std::string name, Position position,
             unsigned int salaryPerHour);

    void calc() override;

    const Project &getProject() const;

    const void setProject(Project &project);

    float getPartOfTheProject() const;

    void setPartOfTheProject(float partOfTheProject);

    int calcBonus() override;

    void printInfo() override;
};

class Tester : public Engineer {
   private:
    unsigned int bonus = 0;
   protected:
    int calcProAdditions() override;

   public:
    Tester(unsigned int id, std::string name, Position position,
           unsigned int salaryPerHour);

    void calc() override;

    void setBonus(unsigned int bonus);
};

class Programmer : public Engineer {
   private:
    unsigned int bonus = 0;
   protected:
    int calcProAdditions() override;

   public:
    Programmer(unsigned int id, std::string name, Position position,
               unsigned int salaryPerHour);

    void calc() override;

    void setBonus(unsigned int bonus);
};

class TeamLeader : public Programmer, public IHeading {
   private:
    unsigned int countHeadings = 0;

    int calcHeads() override;

   public:
    TeamLeader(unsigned int id, std::string name, Position position,
               unsigned int salaryPerHour);

    unsigned int getCountHeadings() const;

    void setCountHeadings(unsigned int countHeadings);

    void printInfo() override;

    void calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
