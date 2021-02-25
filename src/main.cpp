#include <iostream>
#include <string>
#include <vector>
#include "Factory.h"
#include "Personal.h"
#include "Interfaces.h"


int main() {
	//Driver dr(1, "max", Position::DRIVER, 109, 20);
	std::vector<Employee*> staff = makeStaff();

	for (auto emp : staff) {
		emp->setWorkTime(20);
	}
	// расчет зарплаты
	for (auto emp : staff) {
		emp->calc();
	}

	// вывод данных о зарплате
	for (auto emp : staff) {
		emp->printInfo();
	}
}