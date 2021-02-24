// Copyright 2021 Dev-will-work

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <cstdlib>
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

TEST(MyCompanyTest, CleanerBase) {
  int worktime = 50;
  int salary = 120;
  Cleaner* c = new Cleaner(salary, "Appleseed John Smith", Position::CLEANER);
  c->setWorkTime(worktime);
  EXPECT_EQ(worktime * salary, c->calcBase(salary, worktime));
  delete c;
}

TEST(MyCompanyTest, CleanerFull) {
  int worktime = 50;
  int salary = 120;
  Cleaner* c = new Cleaner(salary, "Appleseed John Smith", Position::CLEANER);
  c->setWorkTime(worktime);
  c->calc();
  EXPECT_EQ(worktime * salary, c->getPayment());
  delete c;
}

TEST(MyCompanyTest, DriverBase) {
  int worktime = 50;
  int salary = 240;
  Driver* c = new Driver(salary, "Appleseed John Smith", Position::DRIVER);
  c->setWorkTime(worktime);
  EXPECT_EQ(worktime * salary, c->calcBase(salary, worktime));
  delete c;
}

TEST(MyCompanyTest, DriverBonus) {
  int worktime = 50;
  int salary = 240;
  float ratio = 0.25;
  Driver* c = new Driver(salary, "Appleseed John Smith", Position::DRIVER);
  c->setWorkTime(worktime);
  EXPECT_DOUBLE_EQ(ratio * salary * worktime, c->calcBonus());
  delete c;
}

TEST(MyCompanyTest, DriverFull) {
  int worktime = 50;
  int salary = 240;
  float ratio = 0.25;
  Driver* c = new Driver(salary, "Appleseed John Smith", Position::DRIVER);
  c->setWorkTime(worktime);
  c->calc();
  EXPECT_DOUBLE_EQ(ratio * salary * worktime + worktime * salary,
    c->getPayment());
  delete c;
}

TEST(MyCompanyTest, ProgrammerBudget) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.5;
  Project p {13, 1200000};
  Programmer* c = new Programmer(p, salary, "Appleseed John Smith",
    Position::PROGRAMMER);
  c->setWorkTime(worktime);
  EXPECT_EQ(ratio * p.budget, c->calcBudgetPart(ratio, p.budget));
  delete c;
}

TEST(MyCompanyTest, ProgrammerBase) {
  int worktime = 50;
  int salary = 500;
  Project p {13, 1200000};
  Programmer* c = new Programmer(p, salary, "Appleseed John Smith",
    Position::PROGRAMMER);
  c->setWorkTime(worktime);
  EXPECT_EQ(worktime * salary, c->calcBase(salary, worktime));
  delete c;
}

TEST(MyCompanyTest, ProgrammerBonus) {
  int worktime = 50;
  int salary = 500;
  Project p {13, 1200000};
  Programmer* c = new Programmer(p, salary, "Appleseed John Smith",
    Position::PROGRAMMER);
  c->setWorkTime(worktime);
  EXPECT_EQ(2000 * worktime, c->calcProAdditions());
  delete c;
}

TEST(MyCompanyTest, ProgrammerFull) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.05f;
  Project p {13, 1200000};
  Programmer* c = new Programmer(p, salary, "Appleseed John Smith",
    Position::PROGRAMMER);
  c->setWorkTime(worktime);
  c->calc();
  EXPECT_EQ(worktime * salary + 2000 * worktime + ratio * p.budget,
    c->getPayment());
  delete c;
}

TEST(MyCompanyTest, TesterBudget) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.5;
  Project p {13, 1200000};
  Tester* c = new Tester(p, salary, "Appleseed John Smith", Position::TESTER);
  c->setWorkTime(worktime);
  EXPECT_EQ(ratio * p.budget, c->calcBudgetPart(ratio, p.budget));
  delete c;
}

TEST(MyCompanyTest, TesterBase) {
  int worktime = 50;
  int salary = 500;
  Project p {13, 1200000};
  Tester* c = new Tester(p, salary, "Appleseed John Smith", Position::TESTER);
  c->setWorkTime(worktime);
  EXPECT_EQ(worktime * salary, c->calcBase(salary, worktime));
  delete c;
}

TEST(MyCompanyTest, TesterBonus) {
  int worktime = 50;
  int salary = 500;
  Project p {13, 1200000};
  Tester* c = new Tester(p, salary, "Appleseed John Smith", Position::TESTER);
  c->setWorkTime(worktime);
  EXPECT_EQ(1000 * worktime, c->calcProAdditions());
  delete c;
}

TEST(MyCompanyTest, TesterFull) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.05f;
  Project p {13, 1200000};
  Tester* c = new Tester(p, salary, "Appleseed John Smith", Position::TESTER);
  c->setWorkTime(worktime);
  c->calc();
  EXPECT_EQ(worktime * salary + 1000 * worktime + ratio * p.budget,
    c->getPayment());
  delete c;
}

TEST(MyCompanyTest, TeamLeaderBase) {
  int worktime = 50;
  int salary = 500;
  Project p {13, 1200000};
  TeamLeader* c = new TeamLeader(p, salary, "Appleseed John Smith",
    Position::TEAMLEADER);
  c->setWorkTime(worktime);
  EXPECT_EQ(worktime * salary, c->calcBase(salary, worktime));
  delete c;
}

TEST(MyCompanyTest, TeamLeaderBudget) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.5;
  Project p {13, 1200000};
  TeamLeader* c = new TeamLeader(p, salary, "Appleseed John Smith",
    Position::TEAMLEADER);
  c->setWorkTime(worktime);
  EXPECT_EQ(ratio * p.budget, c->calcBudgetPart(ratio, p.budget));
  delete c;
}

TEST(MyCompanyTest, TeamLeaderHeads) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.5;
  int subord_count = 5;
  Project p {13, 1200000};
  TeamLeader* c = new TeamLeader(p, salary, "Appleseed John Smith",
    Position::TEAMLEADER);
  c->setWorkTime(worktime);
  c->setSubordCount(subord_count);
  EXPECT_EQ(3000 * subord_count, c->calcHeads());
  delete c;
}

TEST(MyCompanyTest, TeamLeaderFull) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.2f;
  int subord_count = 5;
  Project p {13, 1200000};
  TeamLeader* c = new TeamLeader(p, salary, "Appleseed John Smith",
    Position::TEAMLEADER);
  c->setWorkTime(worktime);
  c->setSubordCount(subord_count);
  c->calc();
  EXPECT_EQ(worktime * salary + 3000 * subord_count + ratio * p.budget,
    c->getPayment());
  delete c;
}

TEST(MyCompanyTest, ProjectManagerBudget) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.5;
  Project* p = new Project{13, 1200000};
  ProjectManager* c = new ProjectManager(p, "Appleseed John Smith",
    Position::PROJECT_MANAGER);
  c->setWorkTime(worktime);
  EXPECT_EQ(ratio * p->budget, c->calcBudgetPart(ratio, p->budget));
  delete c;
}

TEST(MyCompanyTest, ProjectManagerHeads) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.5;
  int subord_count = 10;
  Project* p = new Project{13, 1200000};
  ProjectManager* c = new ProjectManager(p, "Appleseed John Smith",
    Position::PROJECT_MANAGER);
  c->setWorkTime(worktime);
  c->setSubordCount(subord_count);
  EXPECT_EQ(500 * subord_count, c->calcHeads());
  delete c;
}

TEST(MyCompanyTest, ProjectManagerFull) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.2f;
  int subord_count = 10;
  Project* p = new Project{13, 1200000};
  ProjectManager* c = new ProjectManager(p, "Appleseed John Smith",
    Position::PROJECT_MANAGER);
  c->setWorkTime(worktime);
  c->setSubordCount(subord_count);
  c->calc();
  EXPECT_EQ(500 * subord_count + ratio * p->budget, c->getPayment());
  delete c;
}

TEST(MyCompanyTest, SeniorManagerBudget) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.5;
  Project* p = new Project{13, 1200000};
  SeniorManager* c = new SeniorManager(p, "Appleseed John Smith",
    Position::SENIOR_MANAGER, 1);
  c->setWorkTime(worktime);
  EXPECT_EQ(ratio * p->budget, c->calcBudgetPart(ratio, p->budget));
  delete c;
}

TEST(MyCompanyTest, SeniorManagerHeads) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.5;
  int subord_count = 30;
  Project* p = new Project{13, 1200000};
  SeniorManager* c = new SeniorManager(p, "Appleseed John Smith",
    Position::SENIOR_MANAGER, 1);
  c->setWorkTime(worktime);
  c->setSubordCount(subord_count);
  EXPECT_EQ(500 * subord_count, c->calcHeads());
  delete c;
}

TEST(MyCompanyTest, SeniorManagerFull) {
  int worktime = 50;
  int salary = 500;
  float ratio = 0.1f;
  int subord_count = 30;
  Project* p = new Project{13, 1200000};
  SeniorManager* c = new SeniorManager(p, "Appleseed John Smith",
    Position::SENIOR_MANAGER, 1);
  c->setWorkTime(worktime);
  c->setSubordCount(subord_count);
  c->calc();
  EXPECT_EQ(500 * subord_count + ratio * p->budget, c->getPayment());
  delete c;
}

TEST(MyCompanyTest, DataGetTest) {
  StaffFactory sf;
  int count = 0;
  int payments[]{3720, 5550, 11000, 9375, 172500, 186700, 192600, 212300,
    105700, 125100, 113000, 109750, 327700, 301500, 251000, 945500};
  int random_workhours[]{31, 37, 44, 30, 39, 34, 48, 48,
    32, 34, 35, 35, 31, 37, 31, 41};
  Position positions[16]{ Position::CLEANER, Position::CLEANER,
    Position::DRIVER, Position::DRIVER, Position::PROGRAMMER,
    Position::PROGRAMMER, Position::PROGRAMMER, Position::PROGRAMMER,
    Position::TESTER, Position::TESTER, Position::TESTER, Position::TESTER,
    Position::TEAMLEADER, Position::PROJECT_MANAGER,
    Position::PROJECT_MANAGER, Position::SENIOR_MANAGER};


  std::vector<Employee*> staff = sf.makeStaff();

  // working time assignment
for(Employee* emp : staff) {
  emp -> setWorkTime(random_workhours[count++]);
}

// salary calculation
for(Employee* emp : staff) {
  emp -> calc();
}

  EXPECT_EQ(16, staff.size());
  for (size_t i = 0; i < staff.size(); i++) {
    EXPECT_EQ(payments[i], staff[i]->getPayment());
    EXPECT_EQ(positions[i], staff[i]->getPosition());
  }
}
