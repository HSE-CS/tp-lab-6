// Copyright 2021 Ziganshin Nikita

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum Position {
    driver, cleaner, projectManager,
    seniorManager, programmer, tester, teamLeader
};

class Employee {
 protected:
    unsigned int payment = 0;
    unsigned int id;
    std::string name;
    Position position;
    unsigned int workTime = 0;

 public:
    void setWorkTime(unsigned int workTime);

    unsigned int getPayment() const;

    unsigned int getId() const;

    void setId(unsigned int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    Position getPosition() const;

    void setPosition(Position position);

    unsigned int getWorkTime() const;

    virtual void calc() = 0;

    virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
