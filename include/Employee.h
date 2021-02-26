//  Copyright Baklanov 2021
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <iostream>
#include <string>

class Employee {
 protected:
    int id;
    std::string position;
    std::string name;
    int worktime;
    int payment;

 public:
    Employee(int id_, std::string position_,
        std::string name_,
        int worktime_,
        int payment_) :
        id(id_), position(position_),
        name(name_), worktime(worktime_),
        payment(payment_) {}
    std::string getPosition() {
        return position;
    }
    int getId() {
        return id;
    }
    std::string getName() {
        return name;
    }
    int getPayment() {
        return payment;
    }
    void setWorkTime(int worktime);
    virtual void calc() = 0;
    virtual void printinfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_