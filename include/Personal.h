//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 protected:
    unsigned salaryPerHour;
 public:
    Personal(unsigned id, const std::string& name);
    unsigned getSalaryPerHour();
    unsigned calcBase(unsigned salary, unsigned workTime) override;
    void calc() override;
    void setSalaryPerHour(int);
};

class Driver : public Personal{
 private:
    int additionalHours;
 public:
    Driver(unsigned id, std::string name);
    void calc() override;
    unsigned calcBonus() override;
};

class Cleaner: public Personal {
 public:
    Cleaner(unsigned id, std::string name);
};


#endif  //  INCLUDE_PERSONAL_H_
