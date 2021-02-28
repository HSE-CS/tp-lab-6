#include "ProjectManager.h"

ProjectManager::ProjectManager(int id_, string name_, int worktime_) : Manager(id_, name_, worktime_)
{

}

int ProjectManager::calculate_heading_payment()
{
	return 100 * (proj[0]->Quantity_Of_All()); 
}

int ProjectManager::project_payment_calculate()
{
	if (!this->proj.empty())
	{
		return proj[0]->Sal_Per_ProjectManager * proj[0]->get_budget_() / 100;
	}
	else
	{
		return 0;
	}
}

void ProjectManager::calculate()
{
	payment = project_payment_calculate() + calculate_heading_payment();
}