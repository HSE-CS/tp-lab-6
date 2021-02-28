//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_TEAMLEADER_H_
#define INCLUDE_TEAMLEADER_H_

#include "Programmer.h"
#include <string>

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(unsigned id, const std::string& name);
    unsigned calcHeads() override;
    void calc() override;
    void printInfo() override;
};

#endif  //  INCLUDE_TEAMLEADER_H_
