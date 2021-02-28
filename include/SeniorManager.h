// Copyright 2021 Краюшкина Екатерина

#pragma once

#include "ProjectManager.h"

class SeniorManager : public ProjectManager
{
public:
	SeniorManager(int id_, string name_, int worktime_);
	int calculate_heading_payment();
	int project_payment_calculate();
	void calculate();
};