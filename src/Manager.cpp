#include "Manager.h"

Manager::Manager(int id_, string name_, int worktime_) : Employee(id_, name_, worktime_)
{

}

int Manager::project_payment_calculate()
{
	if (!this->proj.empty())
	{
		return (proj[0]->Sal_Per_Manager/100) * proj[0]->get_budget_();
	}
	else
	{
		return 0;
	}
}

int Manager::calculate_working_time_payment()
{
	return 0;
}

void Manager::calculate()
{
	payment = project_payment_calculate();
}