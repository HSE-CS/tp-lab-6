// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum Position { DRIVER, CLEANER, PROGRAMMER,
    TESTER, TEAMLEADER, PROJECT_MANAGER, SENIOR_MANAGER };

inline std::string posToString(Position p) {
    switch (p) {
    case PROGRAMMER:      return "Programmer";
    case TESTER:          return "Tester";
    case TEAMLEADER:      return "TeamLeader";
    case PROJECT_MANAGER: return "Project manager";
    case SENIOR_MANAGER:  return "Senior manager";
    case DRIVER:          return "Driver";
    case CLEANER:         return "Cleaner";
    default:              return "[Unknown position]";
    }
}

class Employee {
 protected:
    int id;
    std::string name;
    Position position;
    int worktime;
    int payment;

 public:
    Employee(int id, std::string name);
    void setWorkTime(int time) {
            this->worktime = time;
        }
    int getId() {
        return id;
    }
    std::string getName() {
        return name;
    }
    Position getPosition() {
        return position;
    }
    int getWorkTime() {
        return this->worktime;
    }
    virtual void calc() = 0;
    virtual void printInfo() = 0;
};


#endif  // INCLUDE_EMPLOYEE_H_
