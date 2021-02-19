#pragma once
#include <string>

#include "Employee.h"
#include "Interfaces.h"
class Staff : public Employee, public WorkBaseTime {
 protected:
  uint32_t salary;

 public:
  uint32_t calcBase(uint32_t salary, uint32_t wtime) override;
  Staff(const uint32_t& id, const std::string& firstname,
        const std::string& surname)
      : Employee(id, firstname, surname) {}
  uint32_t calcBonus() override;
  void printInfo() override;
};

class Driver : public Staff {
 public:
  uint32_t calcBonus() override;
  Driver(const uint32_t& id, const std::string& firstname,
         const std::string& surname)
      : Staff(id, firstname, surname) {}
  void calc() override;
};

class Janitor : public Staff {
 public:
  Janitor(const uint32_t& id, const std::string& firstname,
          const std::string& surname)
      : Staff(id, firstname, surname) {}
  void calc() override;
};
