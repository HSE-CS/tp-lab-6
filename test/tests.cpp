// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <Factory.h>

TEST(Test, test1) {
  Cleaner employee1(99, "Vova Vilkin", 100);
  EXPECT_EQ(99, employee1.getID());
}

TEST(Test, test2) {
  Cleaner employee1(99, "Vova Vilkin", 100);
  EXPECT_EQ(8, employee1.getPos());
}

TEST(Test, test3) {
  Cleaner employee1(99, "Vova Vilkin", 100);
  EXPECT_EQ("Vova Vilkin", employee1.getName());
}

TEST(Test, test4) {
  Cleaner employee1(99, "Vova Vilkin", 100);
  employee1.setWorkTime(2);
  employee1.calc();
  EXPECT_EQ(20200, employee1.getPayment());
}

TEST(Test, test5) {
  Cleaner employee1(99, "Vova Vilkin", 100);
  employee1.setWorkTime(0);
  employee1.calc();
  EXPECT_EQ(20000, employee1.getPayment());
}

TEST(Test, test6) {
  Driver employee2(1, "Tanya Bulkina", 10);
  employee2.setWorkTime(10);
  employee2.addBonus(1);
  employee2.calc();
  EXPECT_EQ(46100, employee2.getPayment());
}

TEST(Test, test7) {
  Driver employee2(1, "Tanya Bulkina", 10);
  employee2.setWorkTime(0);
  employee2.addBonus(100);
  employee2.calc();
  EXPECT_EQ(145000, employee2.getPayment());
}

TEST(Test, test8) {
  Project pr1;
  pr1.id = "pr1";
  pr1.budget = 1000;
  Programmer progman(11, "Vova Vist", 100, &pr1);
  progman.setWorkTime(2);
  progman.calc();
  EXPECT_EQ(1300, progman.getPayment());
}

TEST(Test, test9) {
  Project pr1;
  pr1.id = "pr1";
  pr1.budget = 0;
  Programmer progman(12, "Vova Vist", 100, &pr1);
  progman.setWorkTime(0);
  progman.calc();
  EXPECT_EQ(1000, progman.getPayment());
}

TEST(Test, test10) {
  Project pr1;
  pr1.id = "pr1";
  pr1.budget = 1000;
  Tester testman(13, "Dima Bibica", 25, &pr1);
  testman.setWorkTime(100);
  testman.setErrors(5);
  testman.calc();
  EXPECT_EQ(2850, testman.getPayment());
}

TEST(Test, test11) {
  Project pr1;
  pr1.id = "pr1";
  pr1.budget = 100000;
  TeamLeader teamman(998, "Team Mate", 200, &pr1);
  teamman.setWorkTime(12);
  teamman.calc();
  EXPECT_EQ(42400, teamman.getPayment());
}

TEST(Test, test12) {
  Project pr1;
  pr1.id = "pr1";
  pr1.budget = 100000;
  TeamLeader teamman(999, "Team Mate", 200, &pr1);
  teamman.setWorkTime(12);
  teamman.calc();
  EXPECT_EQ(42400, teamman.getPayment());
}

TEST(Test, test13) {
  Project pr1;
  pr1.id = "pr1";
  pr1.budget = 100000;
  TeamLeader teamman(1000, "Team Mate", 200, &pr1);
  teamman.setWorkTime(12);
  teamman.addSub(5);
  teamman.calc();
  EXPECT_EQ(42400, teamman.getPayment());
}

TEST(Test, test14) {
  Project pr1;
  pr1.id = "pr1";
  pr1.budget = 100000;
  ProjectManager projman(100, "Ching Chong", &pr1);
  projman.addSub(5);
  projman.calc();
  EXPECT_EQ(120000, projman.getPayment());
}

TEST(Test, test15) {
  Project pr1;
  pr1.id = "pr1";
  pr1.budget = 0;
  ProjectManager projman(101, "Ching Chong", &pr1);
  projman.addSub(0);
  projman.calc();
  EXPECT_EQ(75000, projman.getPayment());
}