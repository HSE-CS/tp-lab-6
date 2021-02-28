// Copyright 2021 Egor Trukhin
#include <clocale>
#include <iostream>
#include <random>

#include "Factory.h"

int main() {
  setlocale(LC_ALL, "Russian");
  srand(time(0));

  try {
    std::vector<Employee*> staff = Factory::makeStaff("src/data.txt");

    // Присвоение отработанного времени
    for (auto worker : staff) worker->setWorkTime(rand() % 70);

    // Расчет зарплаты
    for (auto worker : staff) worker->calc();

    // Вывод данных о зарплате
    for (auto worker : staff) worker->printInfo();

  } catch (std::exception& error) {
    std::cerr << error.what() << std::endl;
  }

  return 0;
}
