// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 08.02.2021.
//

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 protected:
  virtual int calc_base(int salary, int wt) = 0;
  virtual int calc_bonus() = 0;
  virtual ~WorkBaseTime() = default;
};

class ProjectBudget {
 protected:
  virtual int calc_budget_part(float part, int budget) = 0;
  virtual int calc_pro_additions() = 0;
  virtual ~ProjectBudget() = default;;
};

class Heading {
 protected:
  virtual int calc_heads() = 0;
  virtual ~Heading() = default;
};

#endif  // INCLUDE_INTERFACES_H_
