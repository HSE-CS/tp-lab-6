//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_TESTER_H_
#define INCLUDE_TESTER_H_

#include "Engineer.h"

class Tester : public Engineer {
 public:
    Tester(unsigned, const std::string&);
    unsigned calcProAdditions() override;
    void calc() override;
};

#endif  //  INCLUDE_TESTER_H_
