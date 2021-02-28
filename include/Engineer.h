#pragma once
#include"Interfaces.h"
#include"Personal.h"

class Engineer : public IProjectBudjet, public Personal {
 protected:
  Project* project;
  float part;

 public:
  Engineer(int id, std::string name, std::string position, int worktime, int salary, Project *
           project, float part)
      : project(project),
        part(part),
        Personal(id, name, position, worktime, salary) {}
  int virtual calcBudjetPart(float part, int budjet) override;
  int virtual calcProAdditions() override;
  void calc() override;

  float getPart();
};


class Tester : public Engineer {
 private:
  int k;
 public:
  Tester(int id, std::string name, std::string position, int worktime, int salary, Project* project, float part, int k)
      : k(k), Engineer(id, name, position, worktime, salary, project, part) {}
  virtual int calcProAdditions() override;
};


class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, std::string position, int worktime, int salary,
             Project* project, float part)
      : Engineer(id, name, position, worktime, salary, project, part) {}
  virtual int calcProAdditions() override;
};


class TeamLeader : public Programmer, public IHeading {
 public:
  TeamLeader(int id, std::string name, std::string position, int worktime, int salary,
             Project* project, float part)
      : Programmer(id, name, position, worktime, salary, project, part) {}
  virtual int calcHeads() override;
  virtual void calc() override;
 };
