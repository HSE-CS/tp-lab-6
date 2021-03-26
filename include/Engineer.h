// Copyright 2021 by mila
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <string>
#include <vector>

#include "Manager.h"
#include "Personal.h"

// - **Engineer** - инженер.
// Имеет ставку и оплату
// за час + бонусы от выполняемого проекта.

/*
- **Engineer** - инженер.
Имеет ставку и оплату за час + бонусы от выполняемого проекта.
*/

class Engineer : public ProjectBudget, public Personal {
 private:
  std::vector<char> project;
 public:
    Engineer(int id, std::string name, pos post,
             int salary, Project *myProject, float part)
          : Personal(id, name, post, salary),
          myProject(myProject), part(part) {}

  int calcBudgetPart(float part, int budget) override;
  void calc() override;
}

/*
- **Programmer** - инженер-программист.
Получает зарплату за отработанное время,
часть бюджета проекта и дополнительную премию
за досрочно написанный код.
*/

class Programmer : public Engineer {
// private:
 public:
    Programmer(int id, std::string name, pos post,
               int salary, Project *myProject, float part)
            : Engineer(id, name, position, salary, myProject, part) {}

    int calcProAdditions() override;
    int calcBonus();
}

/*
- **TeamLeader** - ведущий программист.
Получает зарплату за отработанное время,
часть бюджета проекта и за руководство программистами.
*/

class TeamLeader : public Programmer {
// private:
 public:
    TeamLeader(int id, std::string name, pos post,
               int salary, Project *myProject, float part)
            : Programmer(id, name, post, salary, myProject, part) {}
    int calcHeads() override;
  // calc();
    int calcBonus() override;
}

/*
- **Tester** - инженер-тестировщик.
Получает зарплату за отработанное время,
за участие в проекте и за количество найденных ошибок.
*/

class Tester : public Engineer {
// private:
 public:
    Tester(int id, std::string name, pos post,
           int salary, Project *myProject, float part)
        : Programmer(id, name, pos, salary, myProject, part) {}
    int calcProAdditions() override;
    int calcBonus() override;
    void calc() override;
}

#endif  // INCLUDE_ENGINEER_H_
