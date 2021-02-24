// Copyright NikDemoShow 2021
#ifndef PERSONAL_H_
#define PERSONAL_H_
#include"Employee.h"
#include"Interfaces.h"
class Personal : public Employee {
 protected:
  unsigned int salary;

 public:
  Personal(const unsigned int nId, const std::string nName, const Position nPos,
           const unsigned int nSalary)
      : Employee(nId, nName, nPos), salary(nSalary){};
  virtual unsigned int calcBase();
};

class Cleaner : public Personal {
 public:
  Cleaner(const unsigned int nId, const std::string nName, const Position nPos,
          const unsigned int nSalary)
      : Personal(nId, nName, nPos, nSalary){};
  virtual void calc() override;
  virtual void printInfo() override;
};

class Driver : public Personal {
 private:
  static const unsigned int bonusToMoney{100};
  unsigned int bonus;

 public:
  Driver(const unsigned int nId, const std::string nName, const Position nPos,
         const unsigned int nSalary,
         const unsigned int nBonus)
      : Personal(nId, nName, nPos, nSalary), bonus(nBonus){};
  virtual void calc();
  virtual unsigned int calcBonus();
  virtual void printInfo() override;
};

#endif // PERSONAL_H_
