// Copyright 2021 Tatsenko Alexey
#pragma once
#include <string>

enum Position {
  DRIVER,
  CLEANER,
  ENGINEER,
  TESTER,
  PROGRAMMER,
  TEAM_LEADER,
  PROJECT_MANAGER,
  SENIOR_MANAGER,
};

class Employee {
 private:
  int id;
  std::string fi;
  Position position;
  int worktime;
  int payment;
  int avarage_time = 8;

 public:
  Employee(int id, std::string fi, Position position);
  void set_id(int x);
  void set_name(std::string x);
  void set_position(Position x);
  void set_work_time(int x);
  void set_payment(double x);

  int get_id();
  int get_work_time();
  std::string get_name();
  Position get_position();
  int get_payment();
  int get_avatage_time();

  virtual void calc() = 0;
  virtual void print_info() = 0;
};

