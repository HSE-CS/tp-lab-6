#pragma once

#include "Interfaces.h"
#include "Staff.h"

class Engineer : public Staff, public ProjectBudget {
 protected:
  Project* project;

 public:
  void calc() override;
  uint32_t calcBudgetPart(float part, uint32_t budget) override;
  uint32_t calcProAdditions() override;
  Engineer(const uint32_t& id, const std::string& firstname,
           const std::string& surname)
      : Staff(id, firstname, surname) {}
  void printInfo() override;
};

class Tester : public Engineer {
 public:
  uint32_t calcProAdditions() override;
  Tester(const uint32_t& id, const std::string& firstname,
         const std::string& surname)
      : Engineer(id, firstname, surname) {}
};

class Programmer : public Engineer {
 public:
  uint32_t calcProAdditions() override;
  Programmer(const uint32_t& id, const std::string& firstname,
             const std::string& surname)
      : Engineer(id, firstname, surname) {}
};

class TeamLeader : public Programmer, public Heading {
 public:
  uint32_t calcHeads() override;
  TeamLeader(const uint32_t& id, const std::string& firstname,
             const std::string& surname)
      : Programmer(id, firstname, surname) {}
  void calc() override;
};
