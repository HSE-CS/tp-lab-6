// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

/**
 * @description расчет оплаты исходя из руководства (количество подчиненных)
 */
class IHeading {
 public:
  virtual int calcHeads() = 0;
};

/**
 * @description расчет оплаты исходя из участия в проекте
 * (бюджет проекта делится пропорционально персональному вкладу)
 */
class IProjectBudget {
 public:
  // расчет выплат из бюджета проекта
  virtual int calcBudgetPart(float part, int budget) = 0;
  // расчет бонусных выплат
  virtual int calcProAdditions() = 0;
};

/**
 * @description расчет оплаты исходя из отработанного времени
 */
class IWorkBaseTime {
 public:
  // метод расчета зарплаты исходя из оклада (за час) и отработанных часов
  virtual int calcBase(int salary, int wtime) = 0;
  // дополнительные выплаты
  virtual int calcBonus() = 0;
};

#endif // INCLUDE_INTERFACES_H_
