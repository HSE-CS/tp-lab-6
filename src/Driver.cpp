// Copyright 2021
#include "Driver.h"
#include <iostream>
#include <sstream>
#include <string>

double Driver::calcBonus() {

    return std::rand() % 100;
}

void Driver::calc() {
    payment = Personal::calcBase(worktime) + calcBonus();
}
