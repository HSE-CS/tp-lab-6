// Copyright 2021 Краюшкина Екатерина

#include "Driver.h"
#include <ctime>

Driver::Driver(int id_, string name_, int worktime_, int base_) : Personnel(id_, name_, worktime_, base_)
{
	
}

void Driver::calculate()
{
	payment = calculate_working_time_payment();
}