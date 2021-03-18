// Copyright 2021 Stifeev Nikita

#include <iostream>
#include <vector>
#include <time.h>
#include "Project.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"
#include "Factory.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Employee*> staff;
    staff = Factory::makeStaff("projects staff.txt");
    srand(time(NULL));
    for (Employee* emp : staff) {
        emp->setWorkTime(40 + rand() % 101);
    }
    for (Employee* emp : staff) {
        emp->calc();
    }
    for (Employee* emp : staff) {
        emp->printInfo();
    }
    return 0;
}
