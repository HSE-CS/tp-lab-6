// Copyright 2021 Artyom Lavrov


#include <iostream>
#include <Factory.h>


int main() {
	Factory factory = Factory();
	std::vector<Employee*> employees;
	employees = factory.generateEmployees();
	employees[0]->calc();
}
