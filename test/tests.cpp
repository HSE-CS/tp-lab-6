// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

TEST(function, test1) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  EXPECT_EQ("1", employees[0]->GetId());
}

TEST(function, test2) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  EXPECT_EQ("Edie Hancock", employees[0]->GetName());
}

TEST(function, test3) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  EXPECT_EQ(CLEANER, employees[1]->GetPosition());
}

TEST(function, test4) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  EXPECT_EQ(PROGRAMMER, employees[2]->GetPosition());
}

TEST(function, test5) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *driver = (Driver *)(employees[0]);
  EXPECT_EQ(DRIVER, driver->GetPosition());
}

TEST(function, test6) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *driver = (Driver *)(employees[0]);
  driver->SetWorkTime(50);
  driver->calc();
  EXPECT_EQ(6000, driver->GetPayment());
}

TEST(function, test7) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *cleaner = (Cleaner *)(employees[1]);
  cleaner->SetWorkTime(40);
  cleaner->calc();
  EXPECT_EQ(3600, cleaner->GetPayment());
}

TEST(function, test8) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *programmer = (Programmer *)(employees[2]);
  programmer->SetWorkTime(40);
  programmer->calc();
  EXPECT_EQ(14800, programmer->GetPayment());
}

TEST(function, test9) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *tester = (Programmer *)(employees[3]);
  tester->SetWorkTime(40);
  tester->calc();
  EXPECT_EQ(14600, tester->GetPayment());
}

TEST(function, test10) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *programmer = (Programmer *)(employees[2]);
  programmer->SetWorkTime(40);
  programmer->calc();
  programmer->calcProAdditions();
  EXPECT_EQ(20800, programmer->GetPayment());
}

TEST(function, test11) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *tester = (Programmer *)(employees[3]);
  tester->SetWorkTime(40);
  tester->calc();
  tester->calcProAdditions();
  EXPECT_EQ(19600, tester->GetPayment());
}

TEST(function, test12) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *tl = (TeamLeader *)(employees[4]);
  tl->SetWorkTime(40);
  tl->calcHeads();
  EXPECT_EQ(10000, tl->GetPayment());
}

TEST(function, test13) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *projectManager = (ProjectManager *)(employees[5]);

  EXPECT_EQ("R012", projectManager->GetProjects()[0]->GetId());
}

TEST(function, test14) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *seniorManager = (SeniorManager *)(employees[6]);

  EXPECT_EQ("R014", seniorManager->GetProjects()[1]->GetId());
}

TEST(function, test15) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *projectManager = (ProjectManager *)(employees[5]);
  projectManager->calc();

  EXPECT_EQ(20000, projectManager->GetPayment());
}

TEST(function, test16) {
  Factory factory;
  std::vector<Employee *> employees;
  employees = factory.generateEmployees();
  auto *seniorManager = (SeniorManager *)(employees[6]);
  seniorManager->calc();

  EXPECT_EQ( 100000, seniorManager->GetPayment());
}
