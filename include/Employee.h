//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_EMPLOYEE_H
#define TP_LAB_6_EMPLOYEE_H


#include <string>

enum Position {
    SENIOR_MANAGER,
    PROJECT_MANAGER,
    TEAM_LEADER,
    PROGRAMMER,
    TESTER,
    DRIVER,
    CLEANER
};

class Employee{
protected:
    int id;
    std::string name;
    Position position;
    int workTime;
    int payment;
public:
    Employee(int id, std::string name, Position position);
    void setWorkTime(int workTime);
    virtual void calc()=0;
    void printInfo();
};


#endif //TP_LAB_6_EMPLOYEE_H
