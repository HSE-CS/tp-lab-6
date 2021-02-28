// Copyright 2021 Краюшкина Екатерина

#pragma once

#include "Personnel.h"

class Driver : public Personnel
{
public:
	Driver(int id_, string name_, int worktime_, int base_);
	void calculate();
};