// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Engineer.h"
#include "Manager.h"

TEST(test_cleaner, test1) {
Cleaner* cleaner1 = new Cleaner(0,
                                "ivan", 1000, 2,cleaner);
int payment = cleaner1->calc();
EXPECT_EQ(2000, payment);
}
TEST(test_cleaner2, test2) {
Cleaner* cleaner1 = new Cleaner(0,
                                "ivan", 1000, 3,cleaner);
int payment = cleaner1->calc();
EXPECT_EQ(3000, payment);
}
TEST(test_cleaner3, test3) {
Cleaner* cleaner1 = new Cleaner(0,
                                "ivan", 500, 2,cleaner);
int payment = cleaner1->calc();
EXPECT_EQ(1000, payment);
}
TEST(test_driver, test4) {
Driver* driver1 = new Driver(0,
                                "ivan", 500, 2,cleaner);
int payment = driver1->calc();
EXPECT_EQ(1004, payment);
}
TEST(test_driver2, test5) {
Driver* driver1 = new Driver(0,
                             "ivan", 500, 20,cleaner);
int payment = driver1->calc();
EXPECT_EQ(1040, payment);
}