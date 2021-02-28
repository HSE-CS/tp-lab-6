// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Engineer.h"
#include "Manager.h"

TEST(test_cleaner, test1) {
Cleaner* cleaner1 = new Cleaner(0,
                                "ivan", 1000, 2, cleaner);
int payment = cleaner1->calc();
EXPECT_EQ(2000, payment);
}
TEST(test_cleaner2, test2) {
Cleaner* cleaner1 = new Cleaner(0,
                                "ivan", 1000, 3, cleaner);
int payment = cleaner1->calc();
EXPECT_EQ(3000, payment);
}
TEST(test_cleaner3, test3) {
Cleaner* cleaner1 = new Cleaner(0,
                                "ivan", 500, 2, cleaner);
int payment = cleaner1->calc();
EXPECT_EQ(1000, payment);
}
TEST(test_driver, test4) {
Driver* driver1 = new Driver(0,
                                "ivan", 500, 2, driver);
int payment = driver1->calc();
EXPECT_EQ(1004, payment);
}
TEST(test_driver2, test5) {
Driver* driver1 = new Driver(0,
                             "ivan", 1000, 2, driver);
int payment = driver1->calc();
EXPECT_EQ(2004, payment);
}

TEST(test_programmer, test6) {
Programmer* programmer1 = new Programmer(0,
                             "ivan", 1000, 2, programmer, nullptr);
int payment = programmer1->calc();
EXPECT_EQ(2010, payment);
}

TEST(test_programmer2, test7) {
Programmer* programmer1 = new Programmer(0,
                                         "ivan", 2000, 2, programmer, nullptr);
int payment = programmer1->calc();
EXPECT_EQ(4010, payment);
}

TEST(test_programmer3, test8) {
Project* project1 = new Project(0,1000,3)
Programmer* programmer1 = new Programmer(0,
                                         "ivan", 2000, 2, programmer, project1);
int payment = programmer1->calc();
EXPECT_EQ(4343, payment);
}
