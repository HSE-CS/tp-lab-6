// Copyright 2021 Краюшкина Екатерина

#include "SeniorManager.h"

SeniorManager::SeniorManager(int id_, string name_, int worktime_) : ProjectManager(id_, name_, worktime_)
{

}

int SeniorManager::calculate_heading_payment()
{
	int sum = 0;
	for (int g = 0; g < proj.size(); g++)
	{
		sum += proj[g]->Quantity_Of_All() + 1;
	}
	return 90 * sum;
}

int SeniorManager::project_payment_calculate()
{
	if (!proj.empty())
	{
		int sum = 0;
		for (int i = 0; i < proj.size(); i++)
		{
			sum += proj[i]->get_budget_() * 0.1;
		}
		return sum;
	}
	else
	{
		return 0;
	}
}

void SeniorManager::calculate()
{
	payment =  project_payment_calculate() + calculate_heading_payment();
}