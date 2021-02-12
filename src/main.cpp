// Copyright 2020 Stanislav Stoianov

#include "../include/Factory.h"

int main() {
  // создание штата сотрудников на основе файла
  std::string string = "/home/stanislav/CLionProjects/tp-lab-6/test/data/employees.csv";
  std::vector<Employee *> staff = Factory::makeStaff(&string[0]);

  // присвоение отработанного времени и расчет зарплаты, вывод данных о зарплате
  for (Employee *employee : staff) {
    employee->setWorktime(0);
    employee->calc();
    employee->printInfo();
  }

  return 0;
}

