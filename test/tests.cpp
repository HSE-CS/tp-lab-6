// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <Factory.h>

TEST(Test, test1) {
  Cleaner employee1(99, "Vova Vilkin", 100);
  EXPECT_EQ(99, employee1.getId());
}

TEST(Test, test2) {
  Cleaner employee1(99, "Vova Vilkin", 100);
  EXPECT_EQ(8, employee1.getId());
}

TEST(Test, test3) {
  Cleaner employee1(99, "Vova Vilkin", 100);
  EXPECT_EQ("Vova Vilkin", employee1.getName());
}

