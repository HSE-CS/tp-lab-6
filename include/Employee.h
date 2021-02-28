/*Cleaner #3
Driver #2
Tester #5
Programmer #10
TeamLeader #2
ProjectManager #9
SeniorManager #4
*/

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <vector>
#include "Interfaces.h"
#include <iostream>

//### Класс Employee

//Этот, наиболее важный класс, должен содержать поля:

/*
- **id** - идентификационный номер.
- **name** - ФИО.
- **worktime** - отработанное время.
- **payment** - заработная плата.
*/

/*
Полю **worktime** присваивается фактически отработанное время
(независимо от должности).
После вызова виртуального метода
**calc** происходит расчет зарплаты
с учетом всех бонусов и полю **payment** присваивается вся сумма.
*/

/*
- **Employee** - работник.
Основной (абстрактный) родительский класс
для всех разновидностей работников.
*/

//Перечень классов:

/*
- **Employee** - работник.
Основной (абстрактный) родительский класс
для всех разновидностей работников.
*/

enum pos {
    Cleaner,
    Driver,
    Tester,
    Programmer,
    TeamLeader,
    ProjectManager,
    SeniorManager,
};

class Employee {
private:
  int id = 0; // идентификационный номер.
  std::vector<char> name; // ФИО.
  pos position; // должность.


public:
    int salary = 0;
    int worktime = 0; // отработанное время.
    int payment = 0; // заработная плата.

  void setWorkTime(int wtime);

  virtual void calc();

  virtual void printInfo();
}

#endif  // INCLUDE_EMPLOYEE_H_
