// Copyright 2020 GHA Test Team
#include <gtest/gtest.h>
#include <string>

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

TEST(Test, Test_1) {
  Driver* pers = new Driver(42, "Ilya", "Driver", 666, 3);
  EXPECT_EQ(42, pers->get_id());
}

TEST(Test, Test_2) {
  Driver* pers = new Driver(42, "Ilya", "Driver", 666, 3);
  EXPECT_EQ("Ilya", pers->get_name());
}

TEST(Test, Test_3) {
  Driver* pers = new Driver(42, "Ilya", "Driver", 666, 3);
  EXPECT_EQ("Driver", pers->get_position());
}

TEST(Test, Test_4) {
  Driver* pers = new Driver(42, "Ilya", "Driver", 666, 3);
  EXPECT_EQ(666, pers->get_salary());
}

TEST(Test, Test_5) {
  Driver* pers = new Driver(42, "Ilya", "Driver", 666, 3);
  EXPECT_EQ(3, pers->get_worktime());
}
TEST(Test, Test_6) {
  Driver* pers = new Driver(42, "Ilya", "Driver", 666, 10);
  EXPECT_EQ(1332, pers->calcBonus());
}
TEST(Test, Test_7) {
  Driver* pers = new Driver(42, "Ilya", "Driver", 666, 10);
  EXPECT_EQ(7992, pers->calc());
}
TEST(Test, Test_8) {
  Project num = {56, "rabota", 668145};
  EXPECT_EQ("rabota", num.name);
}
TEST(Test, Test_9) {
  Project num = {56, "rabota", 668145};
  EXPECT_EQ(56, num.id);
}
TEST(Test, Test_10) {
  Project num = {56, "rabota", 668145};
  EXPECT_EQ(668145, num.budget);
}

