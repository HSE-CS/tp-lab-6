// Copyright 2021 Краюшкина Екатерина

#pragma once

#include "Engineer.h"

class Programmer : public Engineer
{
public:
	Programmer(int id_, string name_, int worktime_, int base_);
	int project_payment_calculate() ;
};