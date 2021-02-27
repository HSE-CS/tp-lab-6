#pragma once
#include <string>

enum Position {};

class Employee {
 protected:
  size_t id;
  std::string name;
  uint32_t worktime;
  uint32_t payment;

 public:
  void setWorkTime(size_t time) { worktime = time; }
  virtual void calc() = 0;
  virtual void printInfo();
  Employee(const uint32_t& id, const std::string& firstname,
           const std::string& surname);
};
