// Copyright 2021 by mila
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>

// - **Pesonal** - работник по найму
// с оплатой за фактически отработанное время.
// Имеет ставку за час.

#include "Employee.h"
#include "Interfaces.h"


/*
- **Pesonal** - работник по найму
с оплатой за фактически отработанное время.
Имеет ставку за час.
*/

class Personal : public Employee, publc WorkBaseTime {
 private:
    int salary = 0;
 public:
    Personal(int id, std::string name, pos post, int salary)
          : Employee(id, name, post, salary) {}
    int calcBase(int salary. int wtime) override;
    void calc() override;
    void printInfo() override;
}

/*
- **Cleaner** - уборщица.
Получает зарплату на основе отработанного времени.
*/

class Cleaner : public Personal {
 public:
    Cleaner(int id, std::string name, pos post, int salary)
            : Personal(id, name, post, salary) {}
    int calcBonus() override;
}



/*
- **Driver** - водитель.
Получает зарплату на основе
отработанного времени + надбавку за ночные часы.
*/

class Driver : public Personal {
 public:
    Driver(int id, std::string name, pos post, int salary)
        : Personal(id, name, post, salary) {}
  int calcBonus() override;
}


#endif  // INCLUDE_PERSONAL_H_
