// Copyright 2020 GHA Test Team

#include "../include/Employee.h"
#include "../include/Factory.h"
#include "gtest/gtest.h"
#include "../employees.json"
#include "../projects.json"

#include "random"
#include "string"

TEST(Staff, test0) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  EXPECT_EQ(0, staff.at(0)->getPayment());
}
