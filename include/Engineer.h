// Copyright NikDemoShow 2021
#ifndef ENGINEER_H_
#define ENGINEER_H_
#include"Personal.h"
#include"Interfaces.h"
class Engineer : public Personal, public ProjectBudget {
 protected:
  Project* project;
  double part;

 public:
  Engineer(const unsigned int nId, const std::string nName, const Position nPos,
           const unsigned int nSalary, const double nPart, Project* pr)
      : Personal(nId, nName, nPos, nSalary), part(nPart), project(pr){};
  virtual unsigned int calcBudgetPart(const double part,
                                      const unsigned int budget) override;
  virtual unsigned int calcProAdditions() override = 0;
  virtual void calc();
  virtual void printInfo() override;
};

class Programmer : public Engineer {
 protected:
  static const unsigned int proAddToMoney{1000};
  unsigned int proAdd;
 public:
  Programmer(const unsigned int nId, const std::string nName,
             const Position nPos, const unsigned int nSalary,
             const double nPart, const unsigned int nProAdd, Project* pr)
      : Engineer(nId, nName, nPos, nSalary, nPart, pr), proAdd(nProAdd){};
  virtual unsigned int calcProAdditions() override;
};

class TeamLeader : public Programmer, public Heading {
 private:
  unsigned int subord;
  static const unsigned int headsToMoney{2500};
 public:
  TeamLeader(const unsigned int nId, const std::string nName,
             const Position nPos, const unsigned int nSalary,
             const double nPart, const unsigned int nProAdd,
             const unsigned int nSubord, Project* pr)
      : Programmer(nId, nName, nPos, nSalary, nPart, nProAdd, pr),
        subord(nSubord){};
  virtual void calc() override;
  virtual unsigned int calcHeads() override;
};

class Tester : public Engineer {
 private:
  static const unsigned int findErrorToMoney{700};
  unsigned int findError;

 public:
  Tester(const unsigned int nId, const std::string nName,
             const Position nPos, const unsigned int nSalary,
             const double nPart, const unsigned int nFindError, Project* pr)
      : Engineer(nId, nName, nPos, nSalary, nPart, pr), findError(nFindError){};
  virtual unsigned int calcProAdditions() override;
};

#endif // ENGINEER_H_
