#pragma once

#include "Programmer.h"
#include "Heading.h"
#include "Tester.h"

class TeamLeader : public Programmer, public Heading
{
public:
	TeamLeader(int id_, string name_, int worktime_, int base_);
	int calculate_heading_payment();
	int project_payment_calculate();
	void calculate();
};