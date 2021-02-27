// Copyright 2021 Andrey Bakurskii

#include "./Engineer.h"
#include "./Factory.h"
#include "./Personal.h"

#include "gtest/gtest.h"

TEST(TestPersonal, TestCalc1) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  EXPECT_EQ(300, person.calc());
}

TEST(TestPersonal, TestCalc2) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  person.setWorktime(50);
  EXPECT_EQ(650, person.calc());
}

TEST(TestPersonal, TestId) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  EXPECT_EQ(1, person.getId());
}

TEST(TestPersonal, TestName) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  EXPECT_EQ(std::string("Andrey Bakurskii"), person.getName());
}

TEST(TestPersonal, TestPosition) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  EXPECT_EQ(std::string("Developer"), person.getPosition());
}

TEST(TestPersonal, TestPayment) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  EXPECT_EQ(10, person.getPayment());
}

TEST(TestPersonal, TestWorktime1) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  EXPECT_EQ(30, person.getWorktime());
}

TEST(TestPersonal, TestWorktime2) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  person.setWorktime(40);
  EXPECT_EQ(40, person.getWorktime());
}

TEST(TestPersonal, TestCalcBase1) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  EXPECT_EQ(300, person.calcBase(person.getPayment(), person.getWorktime()));
}

TEST(TestPersonal, TestCalcBase2) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  person.setWorktime(50);
  EXPECT_EQ(500, person.calcBase(person.getPayment(), person.getWorktime()));
}

TEST(TestPersonal, TestCalcBonus1) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  30, 10);
  EXPECT_EQ(0, person.calcBonus());
}

TEST(TestPersonal, TestCalcBonus2) {
  Personal person(1, std::string("Andrey Bakurskii"), std::string("Developer"),
                  50, 30);
  EXPECT_EQ(static_cast<int>(30 * 50 * 0.3), person.calcBonus());
}

TEST(TestEngineer, TestProject1) {
  Project pr(1, 500000);
  EXPECT_EQ(1, pr.id);
}

TEST(TestEngineer, TestProject2) {
  Project pr(1, 500000);
  EXPECT_EQ(500000, pr.budget);
}

TEST(TestFactory, TestSizeEmployees) {
  Factory factory(std::string(""), std::string(""));
  factory.makeProjects();
  factory.makeStaff();

  EXPECT_EQ(0, factory.employees.size());
}

TEST(TestFactory, TestSizeProjects) {
  Factory factory(std::string(""), std::string(""));
  factory.makeProjects();
  factory.makeStaff();

  EXPECT_EQ(0, factory.projects.size());
}
