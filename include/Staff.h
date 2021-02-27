// Copyright 2021 Rogov Andrey
#pragma once
#include <string>

#include "Employee.h"
#include "Interfaces.h"

const uint32_t BONUS = 10;
class Staff : public Employee, public WorkBaseTime {
 protected:
  uint32_t salary;
 
 public:
  uint32_t calcBase(uint32_t salary, uint32_t wtime) override;
  Staff(const uint32_t& id, const std::string& firstname,
  const std::string& surname, uint32_t salary)
  : Employee(id, firstname, surname), salary(salary) {}
  uint32_t calcBonus() override;
  void printInfo();
};

class Driver : public Staff {
 public:
  uint32_t calcBonus() override;
  Driver(const uint32_t& id, const std::string& firstname,
  const std::string& surname, uint32_t salary)
  : Staff(id, firstname, surname, salary) {}
  void calc() override;
};

class Janitor : public Staff {
 public:
  Janitor(const uint32_t& id, const std::string& firstname,
  const std::string& surname, uint32_t salary)
  : Staff(id, firstname, surname, salary) {}
  void calc() override;
};
