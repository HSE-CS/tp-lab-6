// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <utility>

class Employee {
 private:
  int id;
  std::string name;
  std::string position;
  int worktime;
  int payment;

 public:
  Employee(int id,
           std::string name,
           std::string position,
           int payment)
      : id(id),
        name(std::move(name)),
        position(std::move(position)),
        payment(payment) {}

  void setWorktime(int w) {
    Employee::worktime = w;
  }

  void setPayment(int p) {
    Employee::payment = p;
  }

  int getWorktime() {
    return worktime;
  }

  int getPayment() {
    return payment;
  }

  int getId() {
    return id;
  }

  std::string &getName() {
    return name;
  }

  std::string &getPosition() {
    return position;
  }

  virtual int getSalary() = 0;

  virtual int calc() = 0;

  virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
