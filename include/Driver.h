// Copyright 2021
#ifndef INCLUDE_DRIVER_H_
#define INCLUDE_DRIVER_H_
#include "Personal.h"
#include <string>

class Driver : public Personal {
 public:
    Driver(int id, std::string name,
        std::string position, double salary)
        : Personal(id, name, position, salary) {}
    double calcBonus() override;
    void calc() override;
};
#endif  // INCLUDE_DRIVER_H_
