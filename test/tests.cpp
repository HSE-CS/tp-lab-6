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

TEST(lab_6, test2) {
    Driver driver1 = Driver(1, "Portnov", 300);
    EXPECT_EQ("Portnov", driver1.getName());
}

TEST(lab_6, test3) {
    Driver driver2 = Driver(2, "Ivanov", 500);
    EXPECT_EQ(500, driver2.getSalary());
}

TEST(lab_6, test4) {
    Driver driver3 = Driver(3, "Smirnov", 600);
    EXPECT_EQ(3, driver3.getId());
}

TEST(lab_6, test5) {
    Driver driver4 = Driver(4, "Volkov", 250);
    driver4.setWorkTime(40);
    EXPECT_EQ(40, driver4.getWorkTime());
}

TEST(lab_6, test6) {
    Project p2("Second Project", 555000);
    EXPECT_EQ("Second Project", p2.getId());
}

TEST(lab_6, test7) {
    std::vector<Employee*> staff;
    Project p3("Third Project", 1400000);
    staff.push_back(new Tester(1, "Lebedev", 500, &p3));
    staff.push_back(new Tester(2, "Pavlov", 500, &p3));
    staff.push_back(new Programmer(3, "Makarov", 1500, &p3));
    staff.push_back(new Programmer(4, "Morozov", 1500, &p3));
    EXPECT_EQ(4, staff.size());
}
