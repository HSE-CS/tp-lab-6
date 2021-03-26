// Copyright 2021 by mila
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_


// ### Перечень интерфейсов:

// - **WorkBaseTime** - расчет оплаты
// исходя из отработанного времени.

  // - **calcBase** - метод расчета зарплаты
  // исходя из оклада (за час) и отработанных часов

  // - **calcBonus** - дополнительные выплаты

class WorkBaseTime {
 public:
  virtual int calcBase(int salary. int wtime) = 0;
  virtual int calcBonus() = 0;
}

// - **ProjectBudget** - расчет оплаты
// исходя из участия в проекте
// (бюджет проекта делится
//  пропорционально персональному вкладу).

  // - **calcBudgetPart** - расчет выплат
  // из бюджета проекта

  // - **calcProAdditions** - расчет *бонусных* выплат

class ProjectBudget {
 public:
  virtual int calcBudgetPart(float part, int budget) = 0;
  virtual int calcProAdditions() = 0;
}

// - **Heading** - расчет оплаты
// исходя из руководства (количество подчиненных).

class Heading {
 public:
  virtual int calcHeads() = 0;
}

#endif  // INCLUDE_INTERFACES_H_
