// Copyright 2021
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <string>
#include "Employee.h"
#include "WorkBaseTime.h"

class Personal : public Employee, WorkBaseTime {
 private:
    double salary;
 public:
    Personal(int id, std::string name,
        std::string position, double salary)
        : Employee(id, name, position) {
        this->salary = salary;
    }
    double getSalary();
    void setSalary(double salary);
    double calcBase(int wtime) override;
    void printInfo() override;
};
#endif  // INCLUDE_PERSONAL_H_
