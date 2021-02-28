// Copyright 2021 Краюшкина Екатерина

#pragma once

#include "Engineer.h"

class Tester : public Engineer
{
public:
	Tester(int id_, string name_, int worktime_, int base_);
	int project_payment_calculate();
};