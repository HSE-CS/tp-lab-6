// Copyright 2021 Vadukk
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <string>

enum class Position {
    DRIVER,
    CLEANER,
    PROGRAMMER,
    TESTER,
    TEAMLEADER,
    PROJECTMANAGER,
    SENIORMANAGER
};

class Employee {
 protected:
    int id;
    std::string name;
    std::string position;
    int worktime;
    int payment;
 public:
    Employee(int id, std::string name,
        std::string position, int worktime, int payment);
    int getId();
    std::string getName();
    std::string getPosition();
    void setWorkTime(size_t wtime);
    int getWorkTime();
    int getPayment();
    virtual int calc() = 0;
    virtual void printInfo() = 0;
};
#endif  // INCLUDE_EMPLOYEE_H_