// Copyright 2021 Ryzhova Irina

#include "Engineer.h"
#include "Manager.h"
#include "Factory.h"

int main() {
  // создание штата сотрудников на основе файла
vector<Employee*> staff = StaffFactory::makeStaff('data.txt');

// присвоение отработанного времени
for(Employee emp: staff) {
   emp -> setWorkTime(42);
}

// расчет зарплаты
for(Employee emp: staff) {
   emp -> calc();
}

// вывод данных о зарплате
for(Employee emp: staff) {
   emp -> printInfo();
}
  return 0;
}