// Copyright 2020 GHA Test Team
#include "Employee.h"


void Employee::setWorkTime(int work_time) {
  this->worktime = work_time;
}

int Employee::getPayment() const {
	return payment;
}

std::string Employee::getPosition() const {
	std::string pos = "";
	switch (position)
	{
	case Position::CLEANER:
		pos = "CLEANER";
		break;
	case Position::DRIVER:
		pos = "DRIVER";
		break;
	case Position::TESTER:
		pos = "TESTER";
		break;
	case Position::PROGRAMMER:
		pos = "PROGRAMMER";
		break;
	case Position::TEAM_LEADER:
		pos = "TEAM LEADER";
		break;
	case Position::PROJECT_MANAGER:
		pos = "PROJECT MANAGER";
		break;
	case Position::SENIOR_MANAGER:
		pos = "SENIOR MANAGER";
		break;
	default:
		break;
	}
	return pos;
}
