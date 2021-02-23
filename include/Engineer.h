// Copyright 2021 Smirnov Grigory
#include "Personal.h"

struct Project {
  int id;
  int budget;
};

class Engineer : public ProjectBudget, public Personal {
 private:
  Project& project;

 public:
  Project& getProject();
  virtual int calcBudgetPart(float part, int budget);
  virtual void calc();
};

class Programmer : public Engineer {
public:
  virtual int calcProAdditions();
};

class Tester : public Engineer {
 private:
  int errorsFound = 0;
 public:
  void incErrorsFound();
  int getErrorsFound();
  virtual int calcProAdditions();
};

class TeamLeader : public Programmer, public Heading {
 private:
   int subordinates = 0;
 public:
  int getSubbordinates();
  virtual int calcHeads();
  virtual void calc();
};
