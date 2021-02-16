#include "Interfaces.h"
#include <iostream>

int main() {
	Employee valera(12, std::string("Valera"), 120, 1, 1200);
	valera.getName();
	valera.getPayment();
	std::cout << valera.getPosition();
}