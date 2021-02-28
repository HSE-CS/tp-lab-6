// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "Project.h"

TEST(test_cleaner, test1) {
Cleaner* cleaner1 = new Cleaner(0,
                                "ivan", 1000, 2,cleaner);
int payment = cleaner1->calc();
EXPECT_EQ(2000, payment);
}