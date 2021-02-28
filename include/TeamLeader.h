//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_TEAMLEADER_H_
#define INCLUDE_TEAMLEADER_H_

#include "Programmer.h"
#include "Interfaces.h"
#include <string>
#include <cstring>

class TeamLeader : public Programmer, public Heading {
 public:
  int amountPeople;
  TeamLeader(int id, std::string name, std::string position, int salary,
             Project* project, float part, bool Deadline, int people);
  void calc() override;
  void printinfo() override;
  int calcHeads() override;
};

#endif  // INCLUDE_TEAMLEADER_H_

