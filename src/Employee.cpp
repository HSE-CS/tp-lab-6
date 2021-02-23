// Copyright 2021 Smirnov Grigory
#include "../include/Employee.h"

void Employee::setWorkTime(int numbOfHours) {
	worktime = numbOfHours;
}

void Employee::setPayment(int money) {
	payment = money;
}

int Employee::getWorkTime() {
	return worktime;
}
