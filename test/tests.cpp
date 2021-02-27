// Copyright 2021 Ksuvot

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"

TEST(TestDriver, test1) {
  Driver driver1(1, "name", 100);
  EXPECT_EQ(100, driver1.calcBonus());
}

TEST(TestDriver, test3) {
  Driver driver1(1, "name", 100);
  EXPECT_EQ("name", driver1.getName());
}

TEST(TestDriver, test4) {
  Driver driver1(1, "name", 100);
  driver1.setSalary(90);
  EXPECT_EQ(90, driver1.getSalary());
}

TEST(TestDriver, test5) {
  Driver d(156, "name", 130);
  d.setWorkTime(200);
  d.calc();
  EXPECT_EQ(31000, d.getPayment());
}
