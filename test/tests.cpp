// Copyright 2020 GHA Test Team

#include <Employee.h>
#include <Factory.h>
#include <gtest/gtest.h>

#include <random>
#include <string>

TEST(Staff, test0) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  EXPECT_EQ(0, staff.at(0)->getPayment());
}