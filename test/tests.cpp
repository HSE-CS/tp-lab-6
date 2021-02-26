// Copyright 2021 Ksuvot

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"

TEST(test1, test1) {
  Driver driver1(1, "name", 100);
  EXPECT_EQ(100, driver1.calcBonus());
}

TEST(test2, test2) {
  Driver driver1(1, "name", 100);
  EXPECT_EQ(driver1.getPayment(), driver1.calc());
}

TEST(test3, test3) {
  Driver driver1(1, "name", 100);
  EXPECT_EQ("name", driver1.getName());
}

TEST(test4, test4) {
  Driver driver1(1, "name", 100);
  driver1.setSalary(90);
  EXPECT_EQ(90, driver1.getSalary());
}
