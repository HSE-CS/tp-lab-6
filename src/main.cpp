//
// Created by Valera on 20.02.2021.
//

#include "Employee.h"
#include "Factory.h"

int main() {
    std::vector<Employee*> staff = StaffFactory::makeStaff(...);
}
