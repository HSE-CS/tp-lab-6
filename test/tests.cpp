// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "Employee.h"

TEST(test_cleaner, test1) {
  Employee* employee = new Cleaner(1,
    "Igor", "driver", 20);
  std::string name = employee->getName();
  EXPECT_EQ("Igor", name);
}

TEST(test_cleaner, test2) {
  Employee* employee = new Cleaner(1,
    "Igor", "driver", 20);
  int position = int(employee->getPosition());
  EXPECT_EQ(position, 1);
}

TEST(test_cleaner, test3) {
  Employee* employee = new Cleaner(1,
    "Igor", "driver", 20);
  int time =  employee->getWorktime();
  EXPECT_EQ(time, 20);
}

TEST(test_cleaner, test4) {
  Employee* employee = new Cleaner(1,
    "Igor", "driver", 20);
  int payment =  employee->getPayment();
  EXPECT_EQ(payment, 600);
}
