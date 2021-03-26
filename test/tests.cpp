// Copyright 2020 GHA Test Team

#include "../include/Employee.h"
#include "../include/Factory.h"
#include "gtest/gtest.h"

#include "random"
#include "string"

TEST(Staff, test1) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  EXPECT_EQ(0, staff.at(0)->getPayment());
}

TEST(Staff, test2) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(42);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(6600, staff.at(0)->getPayment());
}

TEST(Staff, test3) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(42);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(2100, staff.at(1)->getPayment());
}

TEST(Staff, test4) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(55);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(600, staff.at(1)->getPayment());
}

TEST(Staff, test5) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  EXPECT_EQ(0, staff.at(2)->getPayment());
}

TEST(Staff, test6) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(55);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(7315, staff.at(2)->getPayment());
}

TEST(Staff, test7) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(55);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(4620, staff.at(3)->getPayment());
}

TEST(Staff, test8) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  EXPECT_EQ(0, staff.at(5)->getPayment());
}

TEST(Staff, test9) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(55);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(7600, staff.at(5)->getPayment());
}

TEST(Staff, test10) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(55);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(9360, staff.at(6)->getPayment());
}

TEST(Staff, test11) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  EXPECT_EQ(0, staff.at(9)->getPayment());
}

TEST(Staff, test12) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(55);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(14900, staff.at(9)->getPayment());
}

TEST(Staff, test13) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(60);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(3225, staff.at(26)->getPayment());
}

TEST(Staff, test14) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  EXPECT_EQ(0, staff.at(13)->getPayment());
}

TEST(Staff, test15) {
  std::vector<Employee*> staff = StaffFactory::makeStaff();
  std::minstd_rand simple_rand;
  simple_rand.seed(60);
  for (auto emp : staff) {
    emp->setWorkTime(simple_rand() % 40);
  }
  for (auto emp : staff) {
    emp->calc();
  }
  EXPECT_EQ(6525, staff.at(13)->getPayment());
}
