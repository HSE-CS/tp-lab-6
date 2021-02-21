// Copyright 2021 soda
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <vector>
#include <string>
#include "Interfaces.h"


class Personal : public Employee {
 private:
    size_t salary;

 public:
    void setSalary(size_t salary);
    size_t calcBase();
    size_t getSalary();
};

class Driver : public Personal {
 public:
     Driver(size_t id, std::string name, size_t worktime,
         size_t position, size_t salary);
     size_t calcBonus();
     size_t calc();
     void printInfo();
};

class Cleaner : public Personal {
 public:
     Cleaner(size_t id, std::string name, size_t worktime,
         size_t position, size_t salary);
     size_t calc();
     void printInfo();
};

class Security: public Personal {
 private:
    size_t killed_enemies;

 public:
    Security(size_t id, std::string name, size_t worktime,
        size_t position, size_t salary, size_t killed_enemies);
    size_t calc();
    size_t calcBonus();
    size_t getKilled();
    void printInfo();
};

#endif  // INCLUDE_PERSONAL_H_
