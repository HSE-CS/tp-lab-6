// Copyright 2021 TimurZaytsev
//

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <utility>

class Employee {
 private:
  int id{0};
  int worktime{0};
  int payment{0};
  std::string name;
  std::string pos;

 public:
  Employee(int id, std::string name, std::string pos);

  void setId(int id);
  void setTimeWork(int worktime);
  void setPayment(int payment);
  void setName(std::string name);
  void setPos(std::string pos);

  int getId();
  int getWorkTime();
  int getPayment();
  const std::string& getName();
  const std::string& getPos();

  virtual void calc() = 0;
  virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
