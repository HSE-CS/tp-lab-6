// Copyright 2021 Egor Trukhin

#include <gtest/gtest.h>

#include <string>

#include "Engineer.h"
#include "Manager.h"

TEST(simple, test1) {
  Employee* worker = new Cleaner(1, "Test Testov Testovich", 100);
  EXPECT_EQ(0, worker->getPayment());
}

TEST(cleaner, test1) {
  Employee* worker = new Cleaner(1, "Test Testov Testovich", 100);
  worker->setWorkTime(0);
  worker->calc();
  EXPECT_EQ(0, worker->getPayment());
}

TEST(cleaner, test2) {
  Employee* worker = new Cleaner(1, "Test Testov Testovich", 100);
  worker->setWorkTime(25);
  worker->calc();
  EXPECT_EQ(2500, worker->getPayment());
}

TEST(driver, test1) {
  Employee* worker = new Driver(1, "Test Testov Testovich", 500);
  worker->setWorkTime(0);
  worker->calc();
  EXPECT_EQ(0, worker->getPayment());
}

TEST(driver, test2) {
  Employee* worker = new Driver(1, "Test Testov Testovich", 250);
  worker->setWorkTime(20);
  worker->calc();
  EXPECT_EQ(5000 + 10000, worker->getPayment());
}

TEST(programmer, test1) {
  project_t project;
  project.budget = 50000;
  project.staff_size = 10;
  project.name = "Test";

  Employee* worker = new Programmer(1, "Test Testov Testovich", 1000, &project);
  worker->setWorkTime(35);
  worker->calc();
  EXPECT_EQ(35000 + 25000 + 0, worker->getPayment());
}

TEST(programmer, test2) {
  project_t project;
  project.budget = 50000;
  project.staff_size = 10;
  project.name = "Test";

  Employee* worker = new Programmer(1, "Test Testov Testovich", 1000, &project);
  worker->setWorkTime(7);
  worker->calc();
  EXPECT_EQ(7000 + 5000 + 250, worker->getPayment());
}

TEST(team_leader, test1) {
  project_t project;
  project.budget = 50000;
  project.staff_size = 10;
  project.name = "Test";

  Employee* worker = new TeamLeader(1, "Test Testov Testovich", 1000, &project);
  worker->setWorkTime(35);
  worker->calc();
  EXPECT_EQ(35000 + 25000 + 0 + (9 * 2500), worker->getPayment());
}

TEST(team_leader, test2) {
  project_t project;
  project.budget = 50000;
  project.staff_size = 10;
  project.name = "Test";

  Employee* worker = new TeamLeader(1, "Test Testov Testovich", 2000, &project);
  worker->setWorkTime(7);
  worker->calc();
  EXPECT_EQ(14000 + 5000 + 500 + (9 * 2500), worker->getPayment());
}

TEST(project_manager, test1) {
  project_t project;
  project.budget = 50000;
  project.staff_size = 10;
  project.name = "Test";

  std::vector<project_t*> tmp;
  tmp.push_back(&project);

  ProjectManager* worker = new ProjectManager(1, "Test Testov Testovich", tmp);
  EXPECT_EQ(1, worker->getProjects().size());
}

TEST(project_manager, test2) {
  project_t project1;
  project1.budget = 50000;
  project1.staff_size = 10;
  project1.name = "Test1";

  project_t project2;
  project2.budget = 100000;
  project2.staff_size = 20;
  project2.name = "Test2";

  std::vector<project_t*> tmp;
  tmp.push_back(&project1);
  tmp.push_back(&project1);
  tmp.push_back(&project2);
  tmp.push_back(&project2);

  ProjectManager* worker = new ProjectManager(1, "Test Testov Testovich", tmp);
  EXPECT_EQ(1, worker->getProjects().size());
}

TEST(project_manager, test3) {
  project_t project;
  project.budget = 50000;
  project.staff_size = 10;
  project.name = "Test";

  std::vector<project_t*> tmp;
  tmp.push_back(&project);

  Employee* worker = new ProjectManager(1, "Test Testov Testovich", tmp);
  worker->calc();
  EXPECT_EQ(5000 + 25000, worker->getPayment());
}

TEST(senior_manager, test1) {
  project_t project1;
  project1.budget = 50000;
  project1.staff_size = 10;
  project1.name = "Test1";

  project_t project2;
  project2.budget = 100000;
  project2.staff_size = 20;
  project2.name = "Test2";

  std::vector<project_t*> tmp;
  tmp.push_back(&project1);
  tmp.push_back(&project1);
  tmp.push_back(&project2);
  tmp.push_back(&project2);

  SeniorManager* worker = new SeniorManager(1, "Test Testov Testovich", tmp);
  EXPECT_EQ(4, worker->getProjects().size());
}

TEST(senior_manager, test2) {
  project_t project1;
  project1.budget = 50000;
  project1.staff_size = 10;
  project1.name = "Test1";

  project_t project2;
  project2.budget = 100000;
  project2.staff_size = 20;
  project2.name = "Test2";

  std::vector<project_t*> tmp;
  tmp.push_back(&project1);
  tmp.push_back(&project2);

  SeniorManager* worker = new SeniorManager(1, "Test Testov Testovich", tmp);
  EXPECT_EQ(20, worker->getProjects()[1]->staff_size);
}

TEST(senior_manager, test3) {
  project_t project1;
  project1.budget = 50000;
  project1.staff_size = 10;
  project1.name = "Test1";

  project_t project2;
  project2.budget = 100000;
  project2.staff_size = 20;
  project2.name = "Test2";

  std::vector<project_t*> tmp;
  tmp.push_back(&project1);
  tmp.push_back(&project2);

  SeniorManager* worker = new SeniorManager(1, "Test Testov Testovich", tmp);
  worker->calc();
  EXPECT_EQ(12500 + 25000 + (2500 * 30), worker->getPayment();
}
