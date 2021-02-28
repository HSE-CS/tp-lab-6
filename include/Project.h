// Copyright 2021 Galex
#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_
class Project {
 private:
  int id;
  int budget;
  int numOfWorkers;

 public:
  Project(int id, int budget);
  int getId();
  int getBudget();
  int getNumOfWorkers();
  void setId(int id);
  void setBudget(int budget);
  void setNumOfWorkers(int num);
};
#endif  // INCLUDE_PROJECT_H_
