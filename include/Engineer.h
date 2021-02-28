
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

//- **Engineer** - инженер.
//Имеет ставку и оплату
//за час + бонусы от выполняемого проекта.

/*
- **Engineer** - инженер.
Имеет ставку и оплату за час + бонусы от выполняемого проекта.
*/

class Engineer : public ProjectBudget, public Personal {
private:
  std::vector<char> project;
public:
  calcBudgetPart();
  void calc() overide;
}

/*
- **Programmer** - инженер-программист.
Получает зарплату за отработанное время,
часть бюджета проекта и дополнительную премию
за досрочно написанный код.
*/

class Programmer : public Engineer {
//private:
public:
  int calcProAdditions() override;
}

/*
- **TeamLeader** - ведущий программист.
Получает зарплату за отработанное время,
часть бюджета проекта и за руководство программистами.
*/

class TeamLeader : public Programmer {
private:
public:
  int calcHeads() override;
  //calc();
  int calcBonus() override;
}

/*
- **Tester** - инженер-тестировщик.
Получает зарплату за отработанное время,
за участие в проекте и за количество найденных ошибок.
*/

class Tester : public Engineer {
private:
public:
  int calcProAdditions() override;
  //int calcBonus() override;
  //void calc() override;
}



#endif // INCLUDE_ENGINEER_H_
