// Copyright NikDemoShow 2021
#ifndef MANAGER_H_
#define MANAGER_H_
#include<vector>
#include"Employee.h"
#include"Interfaces.h"

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 private:
  std::vector<Project*> projects;
  static const unsigned int headsToMoney{2500};
  unsigned int subord;
  double part;
 public:
  ProjectManager(const unsigned int nId, const std::string nName,
                 const Position nPos, const double nPart, const unsigned int nSubord, std::vector<Project*>& nProjects)
      : Employee(nId, nName, nPos), part(nPart), subord(nSubord), projects(std::move(nProjects)){};
  virtual unsigned int calcBudgetPart(const double part, const unsigned int budget) override;
  virtual unsigned int calcProAdditions() override;
  virtual unsigned int calcHeads() override;
  virtual void calc() override;
  virtual void printInfo() override;
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  SeniorManager(const unsigned int nId, const std::string nName,
                const Position nPos, const double nPart,
                const unsigned int nSubord, std::vector<Project*>& nProjects)
      : ProjectManager(nId, nName, nPos, nPart, nSubord, nProjects){};
};

#endif // MANAGER_H_
