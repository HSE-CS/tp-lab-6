// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

class Employee {
 public:
  explicit Employee(int id, std::string name, std::string position,
    int workTime, int payment);
  void setWorkTime(int workTime);
  virtual int calc() = 0;
  virtual void printInfo() = 0;
  int getId() const;
  std::string getName() const;
  std::string getPosition() const;
  int getWorkTime() const;
  int getPayment() const;
 private:
  int id;
  std::string name;
  std::string position;
  int workTime;
  int payment;
};
#endif  //  INCLUDE_EMPLOYEE_H_
