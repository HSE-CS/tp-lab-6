#include "Interfaces.h"
#include <iostream>

int main() {
	std::string work = "DRIVER";
	int a;
	if (work == "DRIVER")
		a = DRIVER;


	if (a == DRIVER) {
		Driver valera(12, std::string("Valera"), 120, 1, 1200);
		std::cout << valera.getSalary() << std::endl;
		std::cout << valera.getName() << std::endl;
		std::cout << valera.getPayment() << '\n';
		std::cout << valera.getPosition();
	}

	return 0;
}