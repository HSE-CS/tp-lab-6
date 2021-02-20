// Copyright 2021 Arina Simonova

#include "..\include\Engineer.h"

Engineer::Engineer(int _id, string _name, string _pos,
  int _workTime, int _payment, int _salary, Project _myProject)
  : Personal(_id, _name, _pos, _workTime, _payment, _salary) {
  myProject.setBudget(_myProject.GetBudget());
  myProject.setID(_myProject.GetId());
}

Project Engineer::GetProject() {
  return myProject;
}

int Engineer::CalcBidgetPart(float part, int budget) {
  return static_cast<int>(part * budget);
}

int Engineer::calcProAdditions() {
  /*
  * расчет ставки, как половина оплаты от отработанных часов
  */ 
  return static_cast<int>(calcBase(GetSalary(), GetWorkTime()) * 0.5);
}

int Engineer::Calc() {
  SetPayment(calcProAdditions() + calcBase(GetSalary(), GetWorkTime()) +
    CalcBidgetPart(0.01, myProject.GetBudget()));
  return GetPayment();
}

void Engineer::PrintInfo() {
  cout << "id=" + to_string(GetId()) + ", name=" + GetName() +
    ", position=" + GetPosition() +
    ", work time=" + to_string(GetWorkTime()) +
    ", payment=" + to_string(GetPayment()) +
    ", salary=" + to_string(GetSalary()) +
    ", project id=" + to_string(myProject.GetId()) +
    ", budget=" + to_string(myProject.GetBudget()) << endl;
}

Programmer::Programmer(int _id, string _name, string _pos,
  int _workTime, int _payment, int _salary, Project _myProject)
  : Engineer(_id, _name, _pos, _workTime, _payment, _salary, _myProject) {}

int Programmer::calcProAdditions() {
  /*
  * больше часов работы, быстрее пишется код
  */
  return GetWorkTime() > 40 ? (GetWorkTime() - 40) * 50 : 0;
}

int Programmer::Calc() {
  SetPayment(calcProAdditions() + calcBase(GetSalary(), GetWorkTime()) +
    CalcBidgetPart(0.02, GetProject().GetBudget()));
  return GetPayment();
}

Tester::Tester(int _id, string _name, string _pos,
  int _workTime, int _payment, int _salary, Project _myProject)
  : Engineer(_id, _name, _pos, _workTime, _payment, _salary, _myProject) {}

int Tester::calcProAdditions() {
  return GetWorkTime() > 40 ? (GetWorkTime() - 40) * 40 : 0;;
}

int Tester::Calc() {
  SetPayment(calcProAdditions() + calcBase(GetSalary(), GetWorkTime()) +
    CalcBidgetPart(0.01, GetProject().GetBudget()));
  return GetPayment();
}

TeamLead::TeamLead(int _id, string _name, string _pos,
  int _workTime, int _payment, int _salary, Project _myProject)
  : Programmer(_id, _name, _pos, _workTime, _payment, _salary, _myProject) {}

int TeamLead::calcHeads() {
  return CalcBidgetPart(0.03, GetProject().GetBudget());
}

int TeamLead::Calc() {
  SetPayment(calcProAdditions() + calcBase(GetSalary(), GetWorkTime()) +
    CalcBidgetPart(0.02, GetProject().GetBudget()));
  return GetPayment();
}
