// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum Position {
    PROG,
    PRMA,
    SEMA,
    TELE,
    TEST,
    DRIV,
    CLEA,
    ENGI
};

class Employee {
protected:
    std::string id;
    std::string name;
    Position position;
    int workTime;
    int payment;
public:
    void setId(std::string id);

    void setName(std::string name);

    void setPosition(Position position);

    void setWorkTime(int workTime);

    void setPayment(int payment);

    std::string getId();

    std::string getName();

    Position getPosition();

    int getWorkTime();

    int getPayment();

    virtual void calc() = 0;

    virtual void printInfo() = 0;
};

#endif //INCLUDE_EMPLOYEE_H_
