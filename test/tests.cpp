// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Personal.h"

TEST(Employee, Constructor) {
  auto *employee = new Personal(1, "Ivan", "SEO of Feminism", 2);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

