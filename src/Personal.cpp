//// Copyright 2021 Ozhiganova Polina
#include "Personal.h"

int Personal::calc() {
  int initSal = calcBase(getPayment(), getWorkTime());
  int bonus = calcBonus();
  int sal = initSal + bonus;
  setSalary(sal);
  return sal;
}

int Personal::calcBonus() {
  return 0;
}

int Personal::calcBase(int sl, int wt) {
  return sl * wt;
}

void Personal::printInfo() {
  int pId = getId();
  std::string pName = getName();
  std::string pPosition = getPosition();
  int pWorkTime = getWorkTime();
  int pPayment = getPayment();
  int pSalary = getSalary();
  std::cout << "ID: " << std::to_string(pId) << std::endl;
  std::cout << "NAME: " << pName << std::endl;
  std::cout << "POSITION: " << pPosition << std::endl;
  std::cout << "WORK TIME: " << pWorkTime << std::endl;
  std::cout << "PAYMENT: " + std::to_string(pPayment) << std::endl;
  std::cout << "SALARY: " + std::to_string(pSalary) << "\n\n";
}

/* Driver */
int Driver::calc() {
  int initSal = calcBase(getPayment(), getWorkTime());
  int bonus = calcBonus();
  int sal = initSal + bonus;
  setSalary(sal);
  return sal;
}

int Driver::calcBonus() {
  int wt = getWorkTime();
  int pmnt = getPayment();
  int initialSalary = calcBase(pmnt, wt);
  if (wt > 40) {  //  если работал больше 8 часов в день
    return initialSalary * 25 / 100;  //  + 25% от зп
  } else {
    return 0;
  }
}

int Driver::calcBase(int sl, int wt) {
  return Personal::calcBase(sl, wt);
}

void Driver::printInfo() {
  int dId = getId();
  std::string dName = getName();
  std::string dPosition = getPosition();
  int dWorkTime = getWorkTime();
  int dPayment = getPayment();
  int dSalary = getSalary();
  std::cout << "POSITION:  *** " << dPosition << " ***" << std::endl;
  std::cout << "ID: " << std::to_string(dId) << std::endl;
  std::cout << "NAME: " << dName << std::endl;
  std::cout << "WORK TIME: " << dWorkTime << std::endl;
  std::cout << "PAYMENT: " + std::to_string(dPayment) << std::endl;
  std::cout << "SALARY: " + std::to_string(dSalary) << "\n\n";
}

/* Cleaner */
int Cleaner::calc() {
  int initSal = calcBase(getPayment(), getWorkTime());
  int bonus = calcBonus();
  int sal = initSal + bonus;
  setSalary(sal);
  return sal;
}
int Cleaner::calcBonus() {
  int wt = getWorkTime();
  int pmnt = getPayment();
  int initialSalary = calcBase(pmnt, wt);
  if (wt > 25) {  //  если работал больше 5 часов в день
    return initialSalary * 10 / 100;  //  + 10% от зп
  } else {
    return 0;
  }
}

int Cleaner::calcBase(int sl, int wt) {
  return Personal::calcBase(sl, wt);
}

void Cleaner::printInfo() {
  int cId = getId();
  std::string cName = getName();
  std::string cPosition = getPosition();
  int cWorkTime = getWorkTime();
  int cPayment = getPayment();
  int cSalary = getSalary();
  std::cout << "POSITION:  *** " << cPosition << " ***" << std::endl;
  std::cout << "ID: " << std::to_string(cId) << std::endl;
  std::cout << "NAME: " << cName << std::endl;
  std::cout << "WORK TIME: " << cWorkTime << std::endl;
  std::cout << "PAYMENT: " + std::to_string(cPayment) << std::endl;
  std::cout << "SALARY: " + std::to_string(cSalary) << "\n\n";
}
