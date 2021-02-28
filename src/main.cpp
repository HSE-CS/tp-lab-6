// Copyright 2021 Pavlova D.

#include "../include/Factory.h"
#include <vector>

int main() {
// создание штата сотрудников на основе файла
  std::vector<Employee*> staff = StaffFactory::makeStaff();
// присвоение отработанного времени
  for (auto emp : staff) {
    emp -> setWorkTime(10);
  }
// расчет зарплаты
  for (auto emp : staff) {
    emp -> calc();
  }
// вывод данных о зарплате
  for (auto emp : staff) {
    emp -> printInfo();
  }
}
