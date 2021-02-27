#pragma once

#include <string>

#include "Interfaces.h"
#include "Staff.h"

const uint32_t TESTER_PRO_ADDITIONS = 15;
const uint32_t PROGRAMMER_PRO_ADDITIONS = 25;
const uint32_t TEAMLEADER_PER_HEAD = 5;

class Engineer : public Staff, public ProjectBudget {
 protected:
  Project project;

 public:
  void calc() override;
  uint32_t calcBudgetPart(float part, uint32_t budget) override;
  uint32_t calcProAdditions() override;
  Engineer(const uint32_t& id, const std::string& firstname,
           const std::string& surname, uint32_t salary, Project project)
      : Staff(id, firstname, surname, salary), project(project) {}
  void printInfo();
};

class Tester : public Engineer {
 public:
  uint32_t calcProAdditions() override;
  Tester(const uint32_t& id, const std::string& firstname,
         const std::string& surname, uint32_t salary, Project project)
      : Engineer(id, firstname, surname, salary, project) {}
};

class Programmer : public Engineer {
 public:
  uint32_t calcProAdditions() override;
  Programmer(const uint32_t& id, const std::string& firstname,
             const std::string& surname, uint32_t salary, Project project)
      : Engineer(id, firstname, surname, salary, project) {}
};

class TeamLeader : public Programmer, public Heading {
 public:
  uint32_t calcHeads() override;
  TeamLeader(const uint32_t& id, const std::string& firstname,
             const std::string& surname, uint32_t salary, Project project)
      : Programmer(id, firstname, surname, salary, project) {}
  void calc() override;
};
