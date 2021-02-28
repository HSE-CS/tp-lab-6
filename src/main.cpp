// Copyright 2021 kostinandrey
#include "Factory.h"
int main() {
    std::vector < Employee * > staff = Factory_Staff::make_staff();
    for (auto emp : staff) {
        emp->print_info();
    }
    for (auto emp : staff) {
        emp->calc_salary();
    }
}
