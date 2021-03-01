// Copyright 2021 Bekina Svetlana
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"


class Personal: public Employee, public WorkBaseTime {
 public:
    explicit Personal();
    explicit Personal(std::string id, std::string name, std::string position, int new_salary)
        :Employee(id, name, position) {
        salary = new_salary;
    };
    int calcBase(int, int) override;
    int getSalary();
    void printInfo() override;
    int calcBonus() override;

 private:
    int salary = 0;
};

class Driver: public Personal {
 public:
    explicit Driver();
    explicit Driver(std::string id, std::string name, std::string position, int salary)
        :Personal(id, name, position, salary) {};
    int calcBonus() override;
    void calc() override;
};

class Cleaner: public Personal {
 public:
    explicit Cleaner();
    explicit Cleaner(std::string id, std::string name, std::string position, int salary)
        :Personal(id, name, position, salary) {};
    void calc() override;
};
#endif  // INCLUDE_PERSONAL_H_
