// Copyright 2021 Arina Simonova

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#pragma once

class IWorkBaseTime {
 public:
  virtual int calcBase(int salary, int wtime) = 0;
  virtual int calcBonus() = 0;
};

class IHeading {
 public:
  virtual int calcHeads() = 0;
};

class IProjectBudget {
 public:
  virtual int CalcBidgetPart(float part, int budget) = 0;
  virtual int calcProAdditions() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
