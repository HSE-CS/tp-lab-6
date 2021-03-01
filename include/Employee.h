// Copyright 2021 Tatsenko Ilya
#pragma once
#include <string>

class Employee {
 private:
  int id;
  std::string name;
  std::string position;
  int worktime;
  double payment;

 public:
  Employee(int id, std::string name, std::string position, int worktime)
      : id(id), name(name), position(position), worktime(worktime) {}
  Employee(int id, std::string name, std::string position)
      : id(id), name(name), position(position) {}
  void setWorkTime(int x);
  virtual void calc() = 0;
  virtual void printInfo() = 0;

  void setId(int x);
  // void setWorkTime(int x);
  void setName(std::string x);
  void setPosition(std::string x);
  void setPayment(double x);

  int getId();
  double getWorkTime();
  std::string getName();
  std::string getPosition();
  double getPayment();
};

