#include "Personnel.h"

Personnel::Personnel(int id_, string name_, int worktime_, int base_) : Employee(id_, name_, worktime_)
{
	base = base_;
}

int Personnel::calculate_working_time_payment()
{
	return worktime * base;
}

void Personnel::calculate()
{
	payment = calculate_working_time_payment();
}

int Personnel::get_base()
{
	return base;
}

void Personnel::set_base(int base_)
{
	base = base_;
}