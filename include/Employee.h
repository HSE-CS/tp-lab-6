//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <cstring>

class Employee {
 protected:
  int m_id;
  std::string m_name;
  std::string m_position;
  int m_worktime{0};
  int m_payment{0};

 public:
  Employee(int id, std::string name, std::string position);
  int getWorkTime() const;
  int getPayment() const;
  void setWorkTime();
  std::string getPosition();
  virtual void calc() = 0;
  virtual void printinfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_

