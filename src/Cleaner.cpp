// Copyright 2021
#include "Cleaner.h"

void Cleaner::calc() {
    payment = Personal::calcBase(worktime);
}

double Cleaner::calcBonus() {
    return 0.0;
}
