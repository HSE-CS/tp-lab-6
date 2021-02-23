// Copyright 2020 Stanislav Stoianov

#include <random>
#include "../include/Factory.h"

static std::mt19937_64 rng;

int main() {
  /**
   * создание штата сотрудников на основе файла
   */
  std::string string =
      "/home/stanislav/CLionProjects/tp-lab-6/test/data/employees.csv";
  std::string string2 =
      "/home/stanislav/CLionProjects/tp-lab-6/test/data/projects.csv";
  std::vector<Employee *> staff =
      Factory::makeStaff(&string[0], &string2[0]);

  /**
   * присвоение отработанного времени
   * расчет зарплаты
   * вывод данных о зарплате
   */
  for (Employee *employee : staff) {
    employee->setWorktime(static_cast<int>(rng() % 20 + 40));
    employee->calc();
    employee->printInfo();
  }

  return 0;
}

