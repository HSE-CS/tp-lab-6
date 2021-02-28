#pragma once

#include "Personnel.h"

class Cleaner : public Personnel
{
public:
	Cleaner(int id_, string name_, int worktime_, int base_);
};