// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"
#include "Project.h"


TEST(lab_6, test1) {
    Project p1("First Project", 900000);
    EXPECT_EQ(900000, p1.getBudget());
}
