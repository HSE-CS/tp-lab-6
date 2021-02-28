// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Employee.h"
#include "Factory.h"
#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"
#include "Interfaces.h"

TEST(StaffDemo, test1) {
  Driver *newstaff = new Driver("1", "Ivan Sergeev", Position(driver), 10, 20);
  EXPECT_EQ(1200, newstaff->calcBase(newstaff->getSalary(),
                                     newstaff->getWorkTime()));
}

TEST(StaffDemo, test2) {
  Project pr("100", 23490);
  Tester* emp = new Tester("1515", "Naruto Uzumaki", Position(tester), 8,
                           &pr, 550);
  EXPECT_EQ("10", emp->getId());
}

TEST(StaffDemo, test3) {
  Cleaner* emp = new Cleaner("11111", "Dasay Dasay", Position(cleaner), 4, 550);
  emp->setWorkTime(3);
  EXPECT_EQ("Dasay Dasay", emp->getName());
}

TEST(StaffDemo, test4) {
  Project pr("abc", 23490);
  std::vector<Project>prr;
  prr.push_back(pr);
  SeniorManager muy("2223", "Kozhy", Position(senior_Manager), 24, 999, prr);
  muy.calc();
  EXPECT_EQ(24976, muy.getPayment());
}

TEST(StaffDemo, test5) {
  Project pr("abc", 23490);
  std::vector<Project>prr;
  prr.push_back(pr);
  SeniorManager muy("2223", "Kozhy", Position(senior_Manager), 24, 999, prr);
  EXPECT_EQ(999, muy.getPayment());
}

TEST(StaffDemo, test6) {
  Project pr("abc", 23490);
  std::vector<Project>prr;
  prr.push_back(pr);
  SeniorManager muy("2223", "Kozhy", Position(senior_Manager), 24, 999, prr);
  EXPECT_EQ(1000, muy.calcProAdditions());
}

TEST(StaffDemo, test7) {
  Project pr("abc", 23490);
  std::vector<Project>prr;
  prr.push_back(pr);
  SeniorManager muy("2223", "Kozhy", Position(senior_Manager), 24, 999, prr);
  EXPECT_EQ(234, muy.calcHeads());
}

TEST(StaffDemo, test8) {
  Project pr("abc", 23490);
  Project ar("a", 23);
  std::vector<Project>prr;
  prr.push_back(pr);
  prr.push_back(ar);
  SeniorManager muy("2223", "Kozhy", Position(senior_Manager), 24, 999, prr);
  EXPECT_EQ(999, muy.getPayment());
}

TEST(StaffDemo, test9) {
  Project pr("abc", 23490);
  Project ar("a", 23);
  std::vector<Project>prr;
  prr.push_back(pr);
  prr.push_back(ar);
  SeniorManager muy("2223", "Kozhy", Position(senior_Manager), 24, 999, prr);
  muy.calc();
  EXPECT_EQ(24976, muy.getPayment());
}

TEST(StaffDemo, test10) {
  Project pr("abc", 23490);
  Project ar("a", 23);
  std::vector<Project>prr;
  prr.push_back(pr);
  prr.push_back(ar);
  SeniorManager muy("2223", "Kozhy", Position(senior_Manager), 24, 999, prr);
  EXPECT_EQ(1000, muy.calcProAdditions());
}

TEST(StaffDemo, test11) {
  Project pr("abc", 23490);
  Project ar("a", 23);
  std::vector<Project>prr;
  prr.push_back(pr);
  prr.push_back(ar);
  SeniorManager muy("2223", "Kozhy", Position(senior_Manager), 24, 999, prr);
  EXPECT_EQ(234, muy.calcHeads());
}

TEST(StaffDemo, test12) {
  Cleaner* emp = new Cleaner("111", "Marina", Position(cleaner), 4, 550);
  emp->setWorkTime(3);
  EXPECT_EQ(884257971, emp->calcBonus());
}

TEST(StaffDemo, test13) {
  Cleaner* emp = new Cleaner("111", "Marina", Position(cleaner), 4, 550);
  EXPECT_EQ(550, emp->getPayment());
}

TEST(StaffDemo, test14) {
  Cleaner* emp = new Cleaner("111", "Marina", Position(cleaner), 4, 550);
  emp->calc();
  EXPECT_EQ(2200, emp->getPayment());
}

TEST(StaffDemo, test15) {
  Cleaner* emp = new Cleaner("111", "Marina", Position(cleaner), 4, 550);
  EXPECT_EQ(0, emp->getPosition());
}
