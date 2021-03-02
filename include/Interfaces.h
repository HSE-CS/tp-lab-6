// Copyright 2021 Shirokov Alexander
#pragma once

#include <utility>
#include <string>

class WorkBaseTime {
 public:
  virtual int calcBase(int salaryPerHour, int workTime) = 0;
  virtual int calcBonus() = 0;
};

class ProjectBudget {
 public:
  virtual int calcBudgetPart(float part, int budget) = 0;
  virtual int calcProAdditions() = 0;
};

class Heading {
 public:
  virtual int calcHeads() = 0;
};

class Project {
 private:
  int budget;
  std::string title;

 public:
  Project(int budget, std::string title)
  : budget{ budget }, title{ std::move(title) } {}
  int getBudget() { return budget; }
  const std::string& getTitle() { return title; }
};
