// Copyright 2021 VadMack

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum POSITION {
  DRIVER,
  CLEANER,
  PROGRAMMER,
  TESTER,
  TEAMLEADER,
  PROJECTMANAGER,
  SENIORMANAGER
};

class Employee {
 protected:
  std::string id;
  std::string name;
  POSITION position;
  int workTime;
  int payment;
 public:
  virtual void calc() = 0;
  virtual void printInfo() = 0;
  const std::string &GetId() const;
  void SetId(const std::string &id);
  const std::string &GetName() const;
  void SetName(const std::string &name);
  POSITION GetPosition() const;
  void SetPosition(POSITION position);
  int GetWorkTime() const;
  void SetWorkTime(int work_time);
  int GetPayment() const;
  void SetPayment(int payment);

};

#endif // INCLUDE_EMPLOYEE_H_