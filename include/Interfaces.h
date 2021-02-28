// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_
class Heading {
 public:
  virtual ~Heading() = default;
  virtual int calcHeads() = 0;
};

class WorkBaseTime {
 public:
  virtual ~WorkBaseTime() = default;
  virtual int calcBonus(int bonus) = 0;
  virtual int calcBase(int salaryValue, int workTimeValue) = 0;
};

class ProjectBudget {
 public:
  virtual ~ProjectBudget() = default;;
  virtual int calcBudgetPart() = 0;
  virtual int calcProAdditions(int bonus) = 0;
};

#endif  // INCLUDE_INTERFACES_H_




