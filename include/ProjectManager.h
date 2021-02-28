#pragma once

#include "Manager.h"
#include "Heading.h"
#include <vector>

class ProjectManager : public Manager, public Heading
{
public:
	ProjectManager(int id_, string name_, int worktime_);
	int calculate_heading_payment();
	int project_payment_calculate();
	void calculate();
};