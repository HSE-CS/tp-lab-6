// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"

TEST(EmployeeTests, Test1) {
  Cleaner* newCleaner =
  new Cleaner(1, "Ivan Ivanov", 40, 100);
  EXPECT_EQ(1, newCleaner->getId());
}

TEST(EmployeeTests, Test2) {
  Cleaner* newCleaner =
  new Cleaner(1, "Ivan Ivanov", 40, 100);
  EXPECT_EQ("Ivan Ivanov", newCleaner->getName());
}

TEST(EmployeeTests, Test3) {
  Cleaner* newCleaner =
  new Cleaner(1, "Ivan Ivanov", 40, 100);
  unsigned salary = newCleaner->getSalary();
  EXPECT_EQ(100, salary);
}

TEST(EmployeeTests, Test4) {
  Cleaner* newCleaner =
  new Cleaner(1, "Ivan Ivanov", 40, 100);
  EXPECT_EQ(Position::Cleaner,
            newCleaner->getPosition());
}

TEST(EmployeeTests, Test5) {
  Cleaner* newCleaner =
  new Cleaner(1, "Ivan Ivanov", 40, 100);
  EXPECT_EQ(Position::Cleaner,
            newCleaner->getPosition());
}

TEST(EmployeeTests, Test6) {
  Cleaner* newCleaner =
  new Cleaner(1, "Ivan Ivanov", 40, 100);
  EXPECT_EQ(4000, newCleaner->getPayment());
}

TEST(EmployeeTests, Test7) {
  Cleaner* newCleaner =
  new Cleaner(1, "Ivan Ivanov", 40, 100);
  newCleaner->setWorktime(50);
  EXPECT_EQ(5000, newCleaner->getPayment());
}

TEST(ProjectTests, Test8) {
  Project* newProject =
  new Project(1, 123456);
  unsigned budget = newProject->getBudget();
  EXPECT_EQ(123456, budget);
}

TEST(ProjectTests, Test9) {
  Project* newProject =
  new Project(1, 123456);
  newProject->setMembersNum(10);
  EXPECT_EQ(10, newProject->getMembersNum());
}

TEST(FactoryTests, Test10) {
  std::string fileNameE = "./staffInfo.txt";
  std::string fileNameP = "./projectsInfo.txt";
  Factory* myFac = new Factory(fileNameE, fileNameP);
  myFac->readStaff();
  EXPECT_EQ(8, myFac->getEmployeesSize());
}

TEST(FactoryTests, Test11) {
  std::string fileNameE = "./staffInfo.txt";
  std::string fileNameP = "./projectsInfo.txt";
  Factory* myFac = new Factory(fileNameE, fileNameP);
  myFac->readStaff();
  EXPECT_EQ(2, myFac->getProjectsSize());
}

TEST(FactoryTests, Test12) {
  std::string fileNameE = "./staffInfo.txt";
  std::string fileNameP = "./projectsInfo.txt";
  Factory* myFac = new Factory(fileNameE, fileNameP);
  myFac->readStaff();
  myFac->calcAll();
  Employee* senior = myFac->getEmployee(5);
  EXPECT_EQ(215450, senior->getPayment());
}

TEST(FactoryTests, Test13) {
  std::string fileNameE = "./staffInfo.txt";
  std::string fileNameP = "./projectsInfo.txt";
  Factory* myFac = new Factory(fileNameE, fileNameP);
  myFac->readStaff();
  myFac->calcAll();
  Employee* e = myFac->getEmployee(5);
  SeniorManager* senior =
  static_cast<SeniorManager*>(e);
  Project* p = senior->getProject(0);
  p->setNewBudget(0);
  EXPECT_EQ(150200, senior->getPayment());
}

TEST(FactoryTests, Test14) {
  std::string fileNameE = "./staffInfo.txt";
  std::string fileNameP = "./projectsInfo.txt";
  Factory* myFac = new Factory(fileNameE, fileNameP);
  myFac->readStaff();
  myFac->calcAll();
  Employee* e = myFac->getEmployee(5);
  SeniorManager* senior =
  static_cast<SeniorManager*>(e);
  Project* p = senior->getProject(0);
  p->setNewBudget(0);
  p = senior->getProject(1);
  p->setNewBudget(0);
  EXPECT_EQ(0, senior->getPayment());
}

TEST(FactoryTests, Test15) {
  std::string fileNameE = "./staffInfo.txt";
  std::string fileNameP = "./projectsInfo.txt";
  Factory* myFac = new Factory(fileNameE, fileNameP);
  myFac->readStaff();
  myFac->calcAll();
  Employee* e = myFac->getEmployee(0);
  Programmer* pro =
  static_cast<Programmer*>(e);
  pro->setAheadCounter(0);
  unsigned payment1 = pro->getPayment();
  pro->setAheadCounter(5);
  unsigned payment2 = pro->getPayment();
  EXPECT_TRUE(payment1 < payment2);
}




