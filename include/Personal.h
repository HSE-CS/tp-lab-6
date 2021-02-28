
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

//- **Pesonal** - работник по найму
//с оплатой за фактически отработанное время.
//Имеет ставку за час.

#include "Employee.h"
#include "Interfaces.h"


/*
- **Pesonal** - работник по найму
с оплатой за фактически отработанное время.
Имеет ставку за час.
*/

class Personal : public Employee {
private:
  int salary = 0;
public:
  int calcBase() override;
}

/*
- **Cleaner** - уборщица.
Получает зарплату на основе отработанного времени.
*/

class Cleaner : public Personal {
public:
  int calcBonus() override;
  void calc() override;

}



/*
- **Driver** - водитель.
Получает зарплату на основе
отработанного времени + надбавку за ночные часы.
*/

class Driver : public Personal {
public:
  int calcBonus() override;
  void calc() override;
}


#endif // INCLUDE_PERSONAL_H_
