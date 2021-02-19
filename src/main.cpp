#include "Interfaces.h"
#include <iostream>

int main() {
	std::string work = "TEAMLEADER";
	int a;
	Project Myprod(1, 100, std::string("My Project"));
	if (work == "TEAMLEADER")
		a = TEAMLEADER;
	else if (work == "SECURITY")
		a = SECURITY;


	//Убрать поле setPay из конструтора не согласовано с добавлением других
	//участников проекта
	if (a == TEAMLEADER) {
		Programmer valera(1, std::string("Valea"), 120, 4, &Myprod, 10000);
		TeamLeader Michail(2, std::string("Proffesor Michail"), 100, 6, &Myprod, 20000);
		valera.printInfo();
		Michail.printInfo();
	}

	if (a == SECURITY) {
		Security valera(12, std::string("Valera"), 120, 3, 1500, 10);
		valera.printInfo();
	}




	return 0;
}