// Copyright 2021 alexgiving

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

class Employee {
 private:
  size_t id;
  std::string name;
  size_t position;
  size_t worktime;
  size_t payment;

 public:
  void setId(size_t);
  void setName(std::string);
  void setPosition(size_t);
  void setWorkTime(size_t);
  void setPayment(size_t);

  [[nodiscard]] size_t getId() const;
  std::string getName();
  [[nodiscard]] std::string getPosition() const;
  [[nodiscard]] size_t getWorktime() const;
  [[nodiscard]] size_t getPayment() const;
};

#endif // INCLUDE_EMPLOYEE_H_
