// Copyright 2021 Arina Simonova

#include <gtest/gtest.h>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

TEST(Personal, Constructor) {
  Personal *employee =
    new Personal(1, "Arina", "Senior Pomidor", 20, 2000, 100);
  EXPECT_EQ(employee->GetId(), 1);
  EXPECT_EQ(employee->GetName(), "Arina");
  EXPECT_EQ(employee->GetPosition(), "Senior Pomidor");
  EXPECT_EQ(employee->GetWorkTime(), 20);
  EXPECT_EQ(employee->GetPayment(), 2000);
  EXPECT_EQ(employee->GetSalary(), 100);
}

TEST(Personal, Payment) {
  Personal *employee =
    new Personal(1, "Arina", "Senior Pomidor", 20, 0, 100);
  EXPECT_EQ(employee->Calc(), 2000);
}

TEST(Driver, Constructor) {
  Driver *employee =
    new Driver(1, "Arina", "Senior Pomidor", 20, 2000, 100);
  EXPECT_EQ(employee->GetId(), 1);
  EXPECT_EQ(employee->GetName(), "Arina");
  EXPECT_EQ(employee->GetPosition(), "Senior Pomidor");
  EXPECT_EQ(employee->GetWorkTime(), 20);
  EXPECT_EQ(employee->GetPayment(), 2000);
  EXPECT_EQ(employee->GetSalary(), 100);
}

TEST(Driver, Payment) {
  Driver *employee =
    new Driver(1, "Arina", "Senior Pomidor", 50, 0, 100);
  EXPECT_EQ(employee->Calc(), 5200);
}

TEST(Cleaner, Constructor) {
  Cleaner *employee =
    new Cleaner(1, "Arina", "Senior Pomidor", 20, 2000, 100);
  EXPECT_EQ(employee->GetId(), 1);
  EXPECT_EQ(employee->GetName(), "Arina");
  EXPECT_EQ(employee->GetPosition(), "Senior Pomidor");
  EXPECT_EQ(employee->GetWorkTime(), 20);
  EXPECT_EQ(employee->GetPayment(), 2000);
  EXPECT_EQ(employee->GetSalary(), 100);

  EXPECT_EQ(employee->Calc(), 2000);
}

TEST(Cleanerr, Payment) {
  Cleaner *employee =
    new Cleaner(1, "Arina", "Senior Pomidor", 50, 0, 100);
  EXPECT_EQ(employee->Calc(), 5000);
}

TEST(Engineer, Constructor) {
  Project proj(3, 10000);
  Engineer *employee =
    new Engineer(1, "Arina", "Senior Pomidor", 20, 2000, 100, proj);
  EXPECT_EQ(employee->GetId(), 1);
  EXPECT_EQ(employee->GetName(), "Arina");
  EXPECT_EQ(employee->GetPosition(), "Senior Pomidor");
  EXPECT_EQ(employee->GetWorkTime(), 20);
  EXPECT_EQ(employee->GetPayment(), 2000);
  EXPECT_EQ(employee->GetSalary(), 100);
}

TEST(Engineer, Payment) {
  Project proj(3, 10000);
  Engineer *employee =
    new Engineer(1, "Arina", "Senior Pomidor", 20, 0, 100, proj);
  EXPECT_EQ(employee->Calc(), 3100);
}

TEST(Programmer, Constructor) {
  Project  proj(3, 10000);
  Programmer *employee =
    new Programmer(1, "Arina", "Senior Pomidor", 20, 2000, 100, proj);
  EXPECT_EQ(employee->GetId(), 1);
  EXPECT_EQ(employee->GetName(), "Arina");
  EXPECT_EQ(employee->GetPosition(), "Senior Pomidor");
  EXPECT_EQ(employee->GetWorkTime(), 20);
  EXPECT_EQ(employee->GetPayment(), 2000);
  EXPECT_EQ(employee->GetSalary(), 100);
}

TEST(Programmer, Payment) {
  Project proj(3, 10000);
  Programmer *employee =
    new Programmer(1, "Arina", "Senior Pomidor", 20, 0, 100, proj);
  EXPECT_EQ(employee->Calc(), 2200);
}

TEST(Tester, Constructor) {
  Project  proj(3, 10000);
  Tester *employee =
    new Tester(1, "Arina", "Senior Pomidor", 20, 2000, 100, proj);
  EXPECT_EQ(employee->GetId(), 1);
  EXPECT_EQ(employee->GetName(), "Arina");
  EXPECT_EQ(employee->GetPosition(), "Senior Pomidor");
  EXPECT_EQ(employee->GetWorkTime(), 20);
  EXPECT_EQ(employee->GetPayment(), 2000);
  EXPECT_EQ(employee->GetSalary(), 100);
}

TEST(Tester, Payment) {
  Project proj(3, 10000);
  Tester *employee =
    new Tester(1, "Arina", "Senior Pomidor", 20, 0, 100, proj);
  EXPECT_EQ(employee->Calc(), 2100);
}

TEST(TeamLead, Constructor) {
  Project  proj(3, 10000);
  TeamLead *employee =
    new TeamLead(1, "Arina", "Senior Pomidor", 20, 2000, 100, proj);
  EXPECT_EQ(employee->GetId(), 1);
  EXPECT_EQ(employee->GetName(), "Arina");
  EXPECT_EQ(employee->GetPosition(), "Senior Pomidor");
  EXPECT_EQ(employee->GetWorkTime(), 20);
  EXPECT_EQ(employee->GetPayment(), 2000);
  EXPECT_EQ(employee->GetSalary(), 100);
}

TEST(TeamLead, Payment) {
  Project proj(3, 10000);
  TeamLead *employee =
    new TeamLead(1, "Arina", "Senior Pomidor", 20, 0, 100, proj);
  EXPECT_EQ(employee->Calc(), 2200);
}

TEST(ProjectManager, Constructor) {
  Project  proj(3, 10000);
  ProjectManager *employee =
    new ProjectManager(1, "Arina", "Senior Pomidor", 20, 2000, 0, proj);
  EXPECT_EQ(employee->GetId(), 1);
  EXPECT_EQ(employee->GetName(), "Arina");
  EXPECT_EQ(employee->GetPosition(), "Senior Pomidor");
  EXPECT_EQ(employee->GetWorkTime(), 20);
  EXPECT_EQ(employee->GetPayment(), 2000);
}

TEST(ProjectManager, Payment) {
  Project proj(3, 10000);
  ProjectManager *employee =
    new ProjectManager(1, "Arina", "Senior Pomidor", 20, 0, 100, proj);
  EXPECT_EQ(employee->Calc(), 2000);
}

TEST(SeniorManager, Constructor) {
  Project prj1(0, 10000), prj2(1, 20000);
  vector<Project> projects;
  projects.push_back(prj1);
  projects.push_back(prj2);
  SeniorManager *employee =
    new SeniorManager(1, "Arina", "Senior Pomidor", 20, 2000, 0, projects);
  EXPECT_EQ(employee->GetId(), 1);
  EXPECT_EQ(employee->GetName(), "Arina");
  EXPECT_EQ(employee->GetPosition(), "Senior Pomidor");
  EXPECT_EQ(employee->GetWorkTime(), 20);
  EXPECT_EQ(employee->GetPayment(), 2000);
}

TEST(SeniorManager, Payment) {
  Project prj1(0, 10000), prj2(1, 20000);
  vector<Project> projects;
  projects.push_back(prj1);
  projects.push_back(prj2);
  SeniorManager *employee =
    new SeniorManager(1, "Arina", "Senior Pomidor", 20, 2000, 0, projects);
  EXPECT_EQ(employee->Calc(), 9000);
}

