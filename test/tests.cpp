// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Personal.h"
#include "../include/Engineer.h"

TEST(Employee, Constructor) {
  auto *employee =
      new Personal(1, "Ivan", "SEO of Feminism", 2);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(Driver, Constructor) {
  auto *employee =
      new Driver(1, "Ivan", "SEO of Feminism", 2);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(Cleaner, Constructor) {
  auto *employee =
      new Cleaner(1, "Ivan", "SEO of Feminism", 2);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(Engineer, Constructor) {
  auto *project = new Project(1, 200);
  auto *employee =
      new Engineer(1, "Ivan", "SEO of Feminism", 2, project);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(Programmer, Constructor) {
  auto *project = new Project(1, 200);
  auto *employee =
      new Programmer(1, "Ivan", "SEO of Feminism", 2, project);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(Tester, Constructor) {
  auto *project = new Project(1, 200);
  auto *employee =
      new Tester(1, "Ivan", "SEO of Feminism", 2, project);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(TeamLeader, Constructor) {
  auto *project = new Project(1, 200);
  auto *employee =
      new TeamLeader(1, "Ivan", "SEO of Feminism", 2, project);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(ProjectManager, Constructor) {
  auto *project = new Project(1, 200);
  auto *employee =
      new ProjectManager(1, "Ivan", "SEO of Feminism", 2, project);
  EXPECT_EQ(employee->getPayment(), 2);
}

TEST(SeniorManager, Constructor) {
  auto *project = new Project(1, 400);
  auto *project2 = new Project(2, 400);
  std::vector<Project *> projects;
  projects.push_back(project);
  projects.push_back(project2);
  auto *employee = new SeniorManager(
      1, "Ivan", "SEO of Feminism", 2, project, projects);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getProjects().size(), 2);
}
