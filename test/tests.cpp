// Copyright 2021 me

#include <gtest/gtest.h>
#include <string>
#include "../include/Employee.h"
#include "../include/Engineer.h"
#include "../include/Factory.h"
#include "../include/Interfaces.h"
#include "../include/Manager.h"
#include "../include/Personal.h"

TEST(Employee, test1) {
  Programmer Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
                   Position(1), 250, nullptr);
  unsigned expected = 1;
  unsigned result = Vasya.getId();
  EXPECT_EQ(expected, result);
}

TEST(Employee, test2) {
  Programmer Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
                   Position(1), 250, nullptr);
  std::string expected = "Garfield U. Upadhyaya";
  std::string result = Vasya.getName();
  EXPECT_EQ(expected, result);
}

TEST(Employee, test3) {
  Programmer Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
                   Position(1), 250, nullptr);
  Vasya.setWorkTime(100);
  unsigned expected = 100;
  unsigned result = Vasya.getWorkTime();
  EXPECT_EQ(expected, result);
}

TEST(Project, test4) {
  Project pr(1, 10000);
  unsigned expected = 10000;
  unsigned result = pr.getBudget();
  EXPECT_EQ(expected, result);
}

TEST(Project, test5) {
  Project pr(1, 10000);
  unsigned expected = 1;
  unsigned result = pr.getProjectID();
  EXPECT_EQ(expected, result);
}

TEST(Programmer, test6) {
  Project pr(1, 300000);
  Programmer Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
                   Position(1), 190, &pr);
  pr.addWorker(&Vasya);
  Vasya.setWorkTime(150);
  int expected = 118500;
  int result = Vasya.getPayment();
  EXPECT_EQ(expected, result);
}

TEST(Tester, test7) {
  Project pr(1, 200000);
  Tester Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
               Position(2), 100, &pr);
  pr.addWorker(&Vasya);
  Vasya.setWorkTime(200);
  int expected = 60000;
  int result = Vasya.getPayment();
  EXPECT_EQ(expected, result);
}

TEST(Tester, test8) {
  Project pr(1, 300000);
  Tester Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
               Position(2), 100, &pr);
  Vasya.setWorkTime(150);
  std::string expected = "tester";
  std::string result = Vasya.getPosition();
  EXPECT_EQ(expected, result);
}

TEST(TeamLeader, test9) {
  Project pr(1, 200000);
  TeamLeader Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
                   Position(3), 200, &pr);
  Vasya.setWorkTime(150);
  int expected = 100000;
  int result = Vasya.getPayment();
  EXPECT_EQ(expected, result);
}

TEST(Project, test10) {
  Project pr(1, 300000);
  TeamLeader Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
                   Position(3), 200, &pr);
  pr.addWorker(&Vasya);
  Vasya.setWorkTime(150);
  int expected = 1;
  int result = pr.getWorkers();
  EXPECT_EQ(expected, result);
}

TEST(ProjectManager, test11) {
  Project pr(1, 200000);
  ProjectManager Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
                   Position(4), &pr);
  Vasya.setWorkTime(160);
  int expected = 56000;
  int result = Vasya.getPayment();
  EXPECT_EQ(expected, result);
}

TEST(SeniorManager, test12) {
  Project pr1(1, 200000);
  Project pr2(2, 300000);
  Project pr3(3, 100000);
  SeniorManager Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
                       Position(5));
  Vasya.setWorkTime(140);
  Vasya.addProject(&pr1);
  Vasya.addProject(&pr2);
  Vasya.addProject(&pr3);
  int expected = 74000;
  int result = Vasya.getPayment();
  EXPECT_EQ(expected, result);
}

TEST(Driver, test13) {
  Driver Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
               Position(6), 100, 20);
  Vasya.setWorkTime(140);
  int expected = 18000;
  int result = Vasya.getPayment();
  EXPECT_EQ(expected, result);
}

TEST(Cleaner, test14) {
  Cleaner Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
               Position(6), 90);
  Vasya.setWorkTime(100);
  int expected = 9000;
  int result = Vasya.getPayment();
  EXPECT_EQ(expected, result);
}

TEST(Driver, test15) {
  Driver Vasya(1, static_cast<std::string>("Garfield U. Upadhyaya"),
               Position(6), 100, 0);
  Vasya.setWorkTime(140);
  int expected = 14000;
  int result = Vasya.getPayment();
  EXPECT_EQ(expected, result);
}
