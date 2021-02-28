// Copyright 2021
#ifndef INCLUDE_CLEANER_H_
#define INCLUDE_CLEANER_H_
#include <string>
#include "Personal.h"

class Cleaner : public Personal {
 public:
    Cleaner(int id, std::string name,
        std::string position,  double salary)
        : Personal(id, name, position, salary)
    {};
    void calc() override;
    double calcBonus() override;
};
#endif  // INCLUDE_CLEANER_H_
