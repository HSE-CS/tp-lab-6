// Copyright 2021 Ksuvot

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"

TEST(TestDriver, test1) {
  Driver driver1(1, "name", 100);
  EXPECT_EQ(100, driver1.calcBonus());
}

TEST(TestDriver, test2) {
  Driver driver2(1, "name", 100);
  EXPECT_EQ("name", driver2.getName());
}

TEST(TestDriver, test3) {
  Driver driver3(1, "name", 100);
  driver3.setSalary(90);
  EXPECT_EQ(90, driver3.getSalary());
}

TEST(TestDriver, test4) {
  Driver driver4(156, "name", 130);
  driver4.setWorkTime(200);
  driver4.calc();
  EXPECT_EQ(26100, driver4.getPayment());
}

TEST(TestCleaner, test5) {
  Cleaner cleaner1(1, "name", 100);
  EXPECT_EQ(100, cleaner1.calcBonus());
}

TEST(TestCleaner, test6) {
  Cleaner cleaner2(1, "name", 100);
  EXPECT_EQ("name", cleaner2.getName());
}

TEST(TestCleaner, test7) {
  Cleaner cleaner3(1, "name", 100);
  cleaner3.setSalary(90);
  EXPECT_EQ(90, cleaner3.getSalary());
}

TEST(TestCleaner, test8) {
  Cleaner cleaner4(156, "name", 130);
  cleaner4.setWorkTime(200);
  cleaner4.calc();
  EXPECT_EQ(26100, cleaner4.getPayment());
}
