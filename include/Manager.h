#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Interfaces.h"

#include <iostream>
#include <vector>

class Project {
private:
    int id = 0;
    std::vector<char> name;

public:


}

/*
- **ProjectManager** - проектный менеджер.
Получает зарплату из бюджета проекта
и за руководство участниками проекта.
*/

class ProjectManager : public Heading, public ProjectBudget {
private:
    int n = 0;
  vector <char> project[n];
public:
    int calcHeads() override;
   int calcBudgetPart(float part, int budget) override;
   int calcProAdditions() override;
   void calc() override;
   void printInfo() override;

}


/*
- **SeniorManager** - руководитель направления.
Получает из бюджетов всех проектов и за руководство всеми участниками.
*/

class SeniorManager : public ProjectManager {
private:
    vector<vector<char>> project;
public:
  void calc() override;
}


#endif // INCLUDE_MANAGER_H_
