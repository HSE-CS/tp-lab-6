#include "Interfaces.h"
#include <iostream>

int main() {
	std::string work = "DRIVER";
	int a;
	if (work == "DRIVER")
		a = DRIVER;
	else if (work == "SECURITY")
		a = SECURITY;


	if (a == DRIVER) {
		Driver valera(12, std::string("Valera"), 120, 1, 1200);
		valera.printInfo();
	}

	if (a == SECURITY) {
		Security valera(12, std::string("Valera"), 120, 3, 1500, 10);
		valera.printInfo();
	}

	Project Myprod(1, 100, std::string("My Project!"));

	return 0;
}