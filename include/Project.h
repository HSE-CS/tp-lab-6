// Copyright 2021 Kasyanov
#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_

class Project {
  public:
    Project(int, int, int);
    int GetBudget() const;
    int id;
    int budget;
    int senior_id;
};

#endif  // INCLUDE_PROJECT_H_
