// Copyright 2021 Tatsenko Alexey
#pragma once
#include "Interfaces.h"
#include "Personal.h"

class Engineer : public ProjectBudjet, public Personal {
 protected:
  Project* project;
  float part;

 public:
  Engineer(int id, std::string fi, Position position, int salary_per_hour,
           Project* project, float part);
  int calc_budjet_part(float part, int budjet) override;
  int calc_pro_additions() override;
  void calc() override;

  float get_part();
};

class Tester : public Engineer {
 private:
  int number_find_errors;

 public:
  Tester(int id, std::string fi, Position position, int salary_per_hour,
         Project* project, float part, int number_find_errors);
  int calc_pro_additions() override;
};

class Programmer : public Engineer {
 public:
  Programmer(int id, std::string fi, Position position, int salary_per_hour,
             Project* project, float part);
  int calc_pro_additions() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, std::string fi, Position position, int salary_per_hour,
             Project* project, float part);
  int calc_heads() override;
  void calc() override;
};
