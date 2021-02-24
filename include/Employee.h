// Copyright NikDemoShow 2021
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include<string>
#include<iostream>
#include<iomanip>
enum class Position {
  Driver,
  Cleaner,
  Programmer,
  Tester,
  TeamLeader,
  ProjectManager,
  SeniorManager
};

class Employee {
 protected:
  unsigned int id;
  std::string name;
  Position position;
  unsigned int worktime;
  unsigned int payment;
  
 public:
  Employee(const unsigned int nId, const std::string nName, const Position nPos)
      : id(nId), name(nName), position(nPos), worktime(0), payment(0){};
  void setWorkTime();
  virtual void calc() = 0;
  virtual void printInfo();
  unsigned int getWorkTime() const;
  unsigned int getPayment() const;
  std::string getName() const; 
  Position getPos() const;
  friend class Factory;
};

class Project {
 private:
  unsigned int id;
  unsigned int budget;

 public:
  Project() : id(0), budget(0){};
  Project(const unsigned int nId, const unsigned int nBudget)
      : id(nId), budget(nBudget){};
  unsigned int getId() const;
  unsigned int getBudget() const;
};

#endif // EMPLOYEE_H_
