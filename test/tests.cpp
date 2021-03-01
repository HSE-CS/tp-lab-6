// Copyright 2021 Lab_6 TiNa

#include <gtest/gtest.h>
#include "Employee.h"
#include "Factory.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"
#include <string>

TEST(PostfixTest, test1) {
  Cleaner* cl = new Cleaner(225, "Abramova Arina Ivanovna", "Cleaner", 167, 6, 1002);
  EXPECT_EQ(225, empl->getId());
}

TEST(PostfixTest, test2) {
  Cleaner* cl = new Cleaner(225, "Abramova Arina Ivanovna", "Cleaner", 167, 6, 1002);
  EXPECT_EQ("Abramova Arina Ivanovna", empl->getName());
}

TEST(PostfixTest, test3) {
  Cleaner* cl = new Cleaner(225, "Abramova Arina Ivanovna", "Cleaner", 167, 6, 1002);
  EXPECT_EQ("Cleaner", empl->getPosition());
}

TEST(PostfixTest, test4) {
  Cleaner* cl = new Cleaner(225, "Abramova Arina Ivanovna", "Cleaner", 167, 6, 1002);
  EXPECT_EQ(6, empl->getWorktime());
}

TEST(PostfixTest, test5) {
  Cleaner* cl = new Cleaner(225, "Abramova Arina Ivanovna", "Cleaner", 167, 6, 1002);
  EXPECT_EQ(1002, empl->getPayment());
}

TEST(PostfixTest, test6) {
  Driver* cl = new Cleaner(225, "Abramova Arina Ivanovna", "Driver", 167, 6, 1002);
  EXPECT_EQ(1002, cl->getPayment());
}

TEST(PostfixTest, test7) {
  Personal* pers = new Personal(225, "Abramova Arina Ivanovna", "Driver", 167, 6, 1002);
  EXPECT_EQ(167, pers->getSalary());
}

TEST(PostfixTest, test8) {
  Driver* pers = new Driver(225, "Abramova Arina Ivanovna", "Driver", 167, 6, 1002);
  int sal = pers->calc();
  EXPECT_EQ(6012, sal);
}

TEST(PostfixTest, test9) {
  Driver* pers = new Driver(225, "Abramova Arina Ivanovna", "Driver", 167, 32, 500);
  int sal = pers->calc();
  EXPECT_EQ(17600, sal);
}

/* TEST(PostfixTest, test10) {
  
  EXPECT_EQ(, );
}

TEST(PostfixTest, test11) {
  
  EXPECT_EQ(, );
}

TEST(PostfixTest, test12) {
  
  EXPECT_EQ(, );
}

TEST(PostfixTest, test13) {
  
  EXPECT_EQ(, );
}

TEST(PostfixTest, test14) {
  
  EXPECT_EQ(, );
}

TEST(PostfixTest, test15) {
  
  EXPECT_EQ(, );
} */
