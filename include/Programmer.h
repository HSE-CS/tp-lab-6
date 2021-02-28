//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_PROGRAMMER_H_
#define INCLUDE_PROGRAMMER_H_

#include "Engineer.h"
#include <string>

class Programmer : public Engineer {
 public:
    Programmer(unsigned, const std::string&);
    unsigned calcProAdditions() override;
    void calc() override;
    void printInfo() override;
};

#endif  //  INCLUDE_PROGRAMMER_H_
