// Copyright 2020 Stanislav Stoianov

#include <Factory.h>

int main() {
  // создание штата сотрудников на основе файла
  std::vector<Employee *> staff = Factory::makeStaff("/home/stanislav/CLionProjects/tp-lab-6/test/data/employes.csv");

  // присвоение отработанного времени и расчет зарплаты, вывод данных о зарплате
  for (Employee *employee: staff) {
    employee->setWorkTime(0);
    employee->calc();
    employee->printInfo();
  }

  return 0;
}

