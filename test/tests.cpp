// Copyright 2021 Smirnov Grigory

#include <gtest/gtest.h>
#include <string>

#include "Factory.h"

TEST(TestCleaner, pos) {
  std::string n = "Glasha";
  Cleaner c(156, n, 130);
  EXPECT_EQ(0, c.getPos());
}

TEST(TestCleaner, calc) {
  std::string n = "Glasha";
  Cleaner c(156, n, 130);
  c.setWorkTime(100);
  c.calc();
  EXPECT_EQ(13000, c.getPayment());
}

TEST(TestDriver, calc) {
  std::string n = "Vasilii";
  Driver d(156, n, 130);
  d.setWorkTime(200);
  d.calc();
  EXPECT_EQ(31000, d.getPayment());
}

TEST(TestDriver, getName) {
  std::string n = "Vasilii";
  Driver d(156, n, 130);
  EXPECT_EQ("Vasilii", d.getName());
}

