// Copyright 2021 GN
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum position {
    TESTER,
    PROGRAMMER,
    TEAMLEADER,
    PROJECTMANAGER,
    SENIORMANAGER,
    CLEANER,
    DRIVER
};

class Employee {
 private:
    int id;
    std::string name;
    int worktime = 0;
    int payment = 0;

 protected:
    position spec;

 public:
    explicit Employee(int id_, std::string name_) {
        id = id_;
        name = name_;
    }
    int getWorkTime();
    std::string getName();
    void setWorkTime(int worktime_);
    void setPayment(int payment_);
    int getID();
    int getPayment();
    position getPos();
    virtual void calc() = 0;
    virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
