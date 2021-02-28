//  Copyright 2021 GHA created by Klykov Anton

#include "Personal.h"

Personal::Personal(int id, std::string name,
                   std::string position, int salary)
                    : Employee(id, name, position) {
  m_salary = salary;
}
int Personal::calcBase(int salary, int wtime) {
  return salary * wtime;
}

