// Copyright 2021 asma
#pragma once
#ifndef PROJECT_H_
#define PROJECT_H_

class Project {
 public:
    Project(int, int, int);
    int GetBudget() const;
    int id;
    int budget;
    int senior_id;
};

#endif  // PROJECT_H_
