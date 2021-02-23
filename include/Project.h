// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_
#include <string>
class Project {
 private:
  int id;
  std::string title;
  double budget;
  int numOfWorkers;
  bool success;
 public:
  Project(int id, std::string title, double budget, int numOfWorkers) {
    this->id = id;
    this->title = title;
    this->budget = budget;
    this->numOfWorkers = numOfWorkers;
    this->success = false;
  }
  double getBudget() const {
    return this->budget;
  }
  int getWorkers()const{
    return this->numOfWorkers;
  }
  std::string getTitle()const {
    return this->title;
  }
  bool getState()const {
    return this->success;
  }
  void setSuccess() {
    this->success = true;
  }
};

#endif  // INCLUDE_PROJECT_H_


