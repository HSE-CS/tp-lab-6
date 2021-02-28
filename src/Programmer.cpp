// Copyright 2021 Краюшкина Екатерина

#include "Programmer.h"

Programmer::Programmer(int id_, string name_, int worktime_, int base_) : Engineer(id_, name_, worktime_, base_)
{

}

int Programmer::project_payment_calculate()
{
	if (!proj.empty())
	{
		return proj[0]->Sal_Per_Programmer * proj[0]->get_budget_() / 100;
	}
	else
	{
		return 0;
	}
}