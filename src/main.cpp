//// Copyright 2021 Dmitry Vargin
#include <iostream>

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

int main() {
    // Uncomment Factory.cpp and Factory.h to test this program
    std::vector<Employee*> staff = readData("data1.txt");
    for (Employee *em : staff) {
        em->calc();
        em->printInfo();
    }
    return 0;
}
