// Copyright 2021 Egor Trukhin
#include <clocale>
#include <iomanip>
#include <iostream>
#include <random>

#include "Factory.h"

int main() {
  setlocale(LC_ALL, "Russian");
  std::random_device rd;
  std::mt19937 gen(rd());

  try {
    Factory* f =
        new Factory("../../src/employees.txt", "../../src/projects.txt");
    std::vector<Employee*> staff = f->getStaff();

    // Присвоение отработанного времени
    for (auto worker : staff) worker->setWorkTime(gen() % 70);

    // Расчет зарплаты
    for (auto worker : staff) worker->calc();

    // Заголовок таблицы
    std::cout << std::endl;
    std::cout << " id | " << std::setw(37) << "Name | " << std::setw(22)
              << "Position | "
              << " Salary | "
              << " WT |"
              << " Payment |"
              << " Projects" << std::endl;
    std::cout << "-------------------------------------------------------------"
                 "---------------------------------------------"
              << std::endl;

    // Вывод данных о зарплате в виде таблицы
    for (auto worker : staff) worker->printInfo();
  } catch (std::exception& error) {
    std::cerr << error.what() << std::endl;
  }

  return 0;
}
