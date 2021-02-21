//// Copyright 2021 Ozhiganova Polina
#include "Engineer.h"

/* Engineer */
int Engineer::calc() {
  int pmnt = getPayment();
  int wt = getWorkTime();
  int initSalBase = calcBase(pmnt, wt);
  int bonus = calcBonus();
  int sal = initSalBase + bonus;
  setSalary(sal);
  return sal;
}

int Engineer::calcBonus() {
  int wt = getWorkTime();
  int pmnt = getPayment();
  int initialSalary = calcBase(pmnt, wt);
  if (wt > 40) {  //  если работал больше 8 часов в день
    return initialSalary * 30 / 100;  //  + 30% от зп
  } else {
    return 0;
  }
}

int Engineer::calcBase(int sl, int wt) {
  return Personal::calcBase(sl, wt);
}

int Engineer::calcBudgetPart(double part, int budget) {
  return floor(part * budget);
}

int Engineer::calcProAdditions() {
  return calcBonus();
}

Project *Engineer::getProject() {
  return this->project;
}

void Engineer::printInfo() {
  int eId = getId();
  std::string eName = getName();
  std::string ePosition = getPosition();
  int eWorkTime = getWorkTime();
  int ePayment = getPayment();
  int eSalary = getSalary();
  std::string projId = getProject()->id;
  int projBudget = getProject()->budget;
  std::cout << "POSITION:  *** " << ePosition << " ***" << std::endl;
  std::cout << "ID: " << std::to_string(eId) << std::endl;
  std::cout << "NAME: " << eName << std::endl;
  std::cout << "WORK TIME: " << eWorkTime << std::endl;
  std::cout << "PAYMENT: " + std::to_string(ePayment) << std::endl;
  std::cout << "SALARY: " + std::to_string(eSalary) << std::endl;
  std::cout << "PROJECT:" << std::endl;
  std::cout << "    id: " + projId << std::endl;
  std::cout << "    budget: " + std::to_string(projBudget) << "\n\n";
}

/* Tester */
int Tester::calc() {
  int pmnt = getPayment();
  int wt = getWorkTime();
  int initSalBase = calcBase(pmnt, wt);
  int bonus = calcBonus();
  int additionalBonus = calcProAdditions();
  int budgPart = calcBudgetPart(0.02, getProject()->budget);
  int sal = initSalBase + bonus + additionalBonus + budgPart;
  setSalary(sal);
  return sal;
}

int Tester::calcBonus() {
  int wt = getWorkTime();
  int pmnt = getPayment();
  int initialSalary = calcBase(pmnt, wt);
  if (this->mistakes >= 25) {
    return initialSalary * 15 / 100;  // + 15% от зп
  } else {
    return 0;
  }
}

int Tester::calcBase(int sl, int wt) {
  return Engineer::calcBase(sl, wt);
}

int Tester::calcBudgetPart(double part, int budget) {
  return Engineer::calcBudgetPart(part, budget);
}

int Tester::calcProAdditions() {
  return Tester::calcBonus();
}

void Tester::printInfo() {
  int tId = getId();
  std::string tName = getName();
  std::string tPosition = getPosition();
  int tWorkTime = getWorkTime();
  int tPayment = getPayment();
  int tSalary = getSalary();
  std::string projId = getProject()->id;
  int projBudget = getProject()->budget;
  std::cout << "POSITION:  *** " << tPosition << " ***" << std::endl;
  std::cout << "ID: " << std::to_string(tId) << std::endl;
  std::cout << "NAME: " << tName << std::endl;
  std::cout << "WORK TIME: " << tWorkTime << std::endl;
  std::cout << "PAYMENT: " + std::to_string(tPayment) << std::endl;
  std::cout << "SALARY: " + std::to_string(tSalary) << std::endl;
  std::cout << "PROJECT:" << std::endl;
  std::cout << "    id: " + projId << std::endl;
  std::cout << "    budget: " + std::to_string(projBudget) << "\n\n";
}

/* Programmer */
int Programmer::calc() {
  int pmnt = getPayment();
  int wt = getWorkTime();
  int initSalBase = calcBase(pmnt, wt);
  int bonus = calcBonus();
  int additionalBonus = calcProAdditions();
  int budgPart = calcBudgetPart(0.03, getProject()->budget);
  int sal = initSalBase + bonus + additionalBonus + budgPart;
  setSalary(sal);
  return sal;
}

int Programmer::calcBonus() {
  return Engineer::calcBonus();
}

int Programmer::calcBase(int sl, int wt) {
  return Engineer::calcBase(sl, wt);
}

int Programmer::calcBudgetPart(double part, int budget) {
  return Engineer::calcBudgetPart(part, budget);
}

int Programmer::calcProAdditions() {
  return Engineer::calcProAdditions();
}

void Programmer::printInfo() {
  int pId = getId();
  std::string pName = getName();
  std::string pPosition = getPosition();
  int pWorkTime = getWorkTime();
  int pPayment = getPayment();
  int pSalary = getSalary();
  std::string projId = getProject()->id;
  int projBudget = getProject()->budget;
  std::cout << "POSITION:  *** " << pPosition << " ***" << std::endl;
  std::cout << "ID: " << std::to_string(pId) << std::endl;
  std::cout << "NAME: " << pName << std::endl;
  std::cout << "WORK TIME: " << pWorkTime << std::endl;
  std::cout << "PAYMENT: " << std::to_string(pPayment) << std::endl;
  std::cout << "SALARY: " << std::to_string(pSalary) << std::endl;
  std::cout << "PROJECT:" << std::endl;
  std::cout << "    id: " << projId << std::endl;
  std::cout << "    budget: " << std::to_string(projBudget) << "\n\n";
}

/* TeamLeader */
int TeamLeader::calc() {
  int pmnt = getPayment();
  int wt = getWorkTime();
  int initSalBase = calcBase(pmnt, wt);
  int bonus = calcBonus();
  int additionalBonus = calcProAdditions();
  int budgPart = calcBudgetPart(0.05, getProject()->budget);
  int salHead = calcHeads();
  int sal = initSalBase + bonus + additionalBonus + budgPart + salHead;
  setSalary(sal);
  return sal;
}

int TeamLeader::calcBonus() {
  int wt = getWorkTime();
  int pmnt = getPayment();
  int initialSalary = calcBase(pmnt, wt);
  if (wt > 40) {  //  если работал больше 8 часов в день
    return initialSalary * 35 / 100;  //  + 35% от зп
  } else {
    return 0;
  }
}

int TeamLeader::calcBase(int salary, int wtime) {
  return Programmer::calcBase(salary, wtime);
}

int TeamLeader::calcBudgetPart(double part, int budget) {
  return Programmer::calcBudgetPart(part, budget);
}

int TeamLeader::calcProAdditions() {
  return TeamLeader::calcBonus();
}

int TeamLeader::calcHeads() {
  double headAddings = 0.005;
  return floor(getProject()->budget * headAddings);
}

void TeamLeader::printInfo() {
  int tlId = getId();
  std::string tlName = getName();
  std::string tlPosition = getPosition();
  int tlWorkTime = getWorkTime();
  int tlPayment = getPayment();
  int tlSalary = getSalary();
  std::string projId = getProject()->id;
  int projBudget = getProject()->budget;
  std::cout << "POSITION:  *** " << tlPosition << " ***" << std::endl;
  std::cout << "ID: " << std::to_string(tlId) << std::endl;
  std::cout << "NAME: " << tlName << std::endl;
  std::cout << "WORK TIME: " << tlWorkTime << std::endl;
  std::cout << "PAYMENT: " << std::to_string(tlPayment) << std::endl;
  std::cout << "SALARY: " << std::to_string(tlSalary) << std::endl;
  std::cout << "PROJECT:" << std::endl;
  std::cout << "    id: " << projId << std::endl;
  std::cout << "    budget: " << std::to_string(projBudget) << "\n\n";
}
