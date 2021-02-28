// Copyright DBarinov
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include<string>
#include"Employee.h"
#include"Interfaces.h"
class Personal : public Employee, public WorkBaseTime {
 protected:
  unsigned int salary;
 public:
  Personal(const unsigned int nId, const std::string nName, const Position nPos,
           const unsigned int nSalary)
  :Employee(nId, nName, nPos), salary(nSalary) {}
  unsigned int calcBase() override;
  unsigned int calcBonus() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(const unsigned int nId, const std::string nName, const Position nPos,
          const unsigned int nSalary)
  :Personal(nId, nName, nPos, nSalary) {}
  void calc() override;
  void printInfo() override;
};

class Driver : public Personal {
 private:
  static const unsigned int bonusToMoney{100};
  unsigned int bonus;
 public:
  Driver(const unsigned int nId, const std::string nName, const Position nPos,
         const unsigned int nSalary,
         const unsigned int nBonus)
  :Personal(nId, nName, nPos, nSalary), bonus(nBonus) {}
  void calc() override;
  unsigned int calcBonus() override;
  void printInfo() override;
};

#endif  // INCLUDE_PERSONAL_H_
