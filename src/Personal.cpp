// Copyright 2021 Kartseva Masha
#include "Personal.h"
#include <map>

extern std::map<std::string, int> projects;

Personal::Personal(std::string name, unsigned int id,
    float base, std::string position) :Employee(name, id) {
    this->base1 = base;
    this->position = position;
}

float Personal::getPaymentbyWorkTime() {
    return base1 * worktime;
}

Cleaner::Cleaner(std::string name, unsigned int id,
    float base, std::string position) : Personal(name, id,
        base, position);

float Cleaner::getPayment() {
    payment = getPaymentbyWorkTime();
    return payment;
}

Driver::Driver(std::string name, unsigned int id, float base,
    std::string position, float koef) : Personal(name, id, base,
        position) {
    this->koef = koef;
}

float Driver::getPayment() {
    payment = getPaymentbyWorkTime() * koef;
    return payment;
}
