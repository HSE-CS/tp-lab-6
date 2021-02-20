//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_EMPLOYEE_H
#define TP_LAB_6_EMPLOYEE_H


#include <string>

enum Position {
    Programmer,
    Tester,
    ProjectManager,
    SeniorManager,
    Driver,
    Cleaner
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
    virtual void printInfo()=0;
};


#endif //TP_LAB_6_EMPLOYEE_H
