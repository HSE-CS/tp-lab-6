#include "TeamLeader.h"

TeamLeader::TeamLeader(int id_, string name_, int worktime_, int base_) : Programmer(id_, name_, worktime_, base_)
{

}

int TeamLeader::calculate_heading_payment()
{
	return 170 * (proj[0]->Quantity_Programmers + proj[0]->Quantity_Testers);
}

int TeamLeader::project_payment_calculate()
{
	if (!proj.empty())
	{
		return (proj[0]->Sal_Per_TeamLeader/100) * proj[0]->get_budget_();
	}
	else
	{
		return 0;
	}
}

void TeamLeader::calculate()
{
	this->payment = calculate_working_time_payment() + project_payment_calculate() + calculate_heading_payment();
}