// Copyright 2021 Shirokov Alexander
#pragma once

#include <string>

enum Position {
  ENGINEER,
  PROGRAMMER,
  TESTER,
  TEAM_LEADER, 
  PROJECT_MANAGER,
  SENIOR_MANAGER,
  DRIVER,
  CLEANER
};

class Employee {
protected:
 int id;
 std::string name;
 Position position;
 int workTime;
 int payment;

public:
 Employee(int id, std::string name, Position position);

 int getId();
 const std::string& getName();
 Position getPosition();
 int getWorkTime();
 int getPayment();

 void setId(int id);
 void setName(std::string name);
 void setPos(Position position);
 void setWorkTime(int workTime);
 void setPayment(int payment);

 virtual void calc() = 0;
 virtual void printInfo() = 0;
};