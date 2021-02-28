// Copyright 2021 Artyom Lavrov


#include <Employee.h>


const std::string& Employee::GetId() const {
	return id;
}

void Employee::SetId(const std::string& id) {
	Employee::id = id;
}

const std::string& Employee::GetName() const {
	return name;
}

void Employee::SetName(const std::string& name) {
	Employee::name = name;
}

POSITION Employee::GetPosition() const {
	return position;
}

void Employee::SetPosition(POSITION position) {
	Employee::position = position;
}

int Employee::GetWorkTime() const {
	return workTime;
}

void Employee::SetWorkTime(int work_time) {
	workTime = work_time;
}

int Employee::GetPayment() const {
	return payment;
}

void Employee::SetPayment(int payment) {
	Employee::payment = payment;
}
