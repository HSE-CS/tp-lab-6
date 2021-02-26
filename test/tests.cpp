// Copyright 2021 Ksuvot

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"

TEST(test1, test1) {
  Employee employee();
  employee.setId(123);
  EXPECT_EQ(123, employee.getId());
}

TEST(test2, test2) {
  Employee employee();
  employee.setName("name");
  EXPECT_EQ("name", employee.getName());
}

TEST(test3, test3) {
  Employee employee();
  employee.setWorkTime(168);
  EXPECT_EQ(168, employee.getWorktime());
}

TEST(test4, test4) {
  Employee employee();
  employee.setPayment(25000);
  EXPECT_EQ(25000, employee.getPayment());
}
