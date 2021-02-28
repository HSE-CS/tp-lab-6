// Copyright 2021
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Factory.h"

int main() {
    Factory factory;
    factory.makeStaff("Staff.txt");
    factory.setAllWorkTime();
    factory.calcPayment();
    factory.printAllInfo();
}
