// Copyright 2021 Краюшкина Екатерина

#include "Tester.h"

Tester::Tester(int id_, string name_, int worktime_, int base_) : Engineer(id_, name_, worktime_, base_)
{

}

int Tester::project_payment_calculate()
{
	if (!proj.empty())
	{
		return (proj[0]->Sal_Per_Tester/100) * proj[0]->get_budget_();
	}
	else
	{
		return 0;
	}
}