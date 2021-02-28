// Copyright 2021 mkhorosh
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime{
  virtual int calcBase(int salary, int work_time)=0;
  virtual int calcBonus()=0;
};

class Heading{
  virtual int calcHeads()=0;
};

class projectBudget{
  virtual int calcBudgetPart(float part, int budget)=0;
  virtual int calcProAdditions()=0;
};

#endif  // INCLUDE_INTERFACES_H_
