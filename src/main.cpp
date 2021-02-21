// Copyright 2021 valvarl

#include <random>
#include <chrono>
#include "Employee.h"
#include "Factory.h"

int main() {
    // создание штата сотрудников на основе файла
    std::vector<Employee*> staff = StaffFactory::makeStaff();

    std::minstd_rand simple_rand;
//    simple_rand.seed(
//    std::chrono::system_clock::now().time_since_epoch().count());
    simple_rand.seed(55);

    // присвоение отработанного времени
    for(auto emp: staff) {
        emp->setWorkTime(simple_rand() % 40);
    }

    // расчет зарплаты
    for(auto emp: staff) {
        emp->calc();
    }

    // вывод данных о зарплате
    for(auto emp: staff) {
        emp->printInfo();
    }
    return 0;
}
