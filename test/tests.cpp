// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Employee.h"
#include "Factory.h"
#include "Engineer.h"

TEST(MyTests, test1) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    EXPECT_EQ("Lory Ellington", staff.at(0)->getName());
}

TEST(MyTests, test2) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    EXPECT_EQ("driver", staff.at(1)->getPosition());
}

TEST(MyTests, test3) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    EXPECT_EQ(0, staff.at(2)->getWorktime());
}

TEST(MyTests, test4) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(5)->setWorkTime(15);
    staff.at(5)->calc();
    EXPECT_EQ(18250, staff.at(5)->getPayment());
}

TEST(MyTests, test5) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(6)->setWorkTime(0);
    staff.at(6)->calc();
    EXPECT_EQ(10000, staff.at(6)->getPayment());
}

TEST(MyTests, test6) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(12)->setWorkTime(15);
    staff.at(12)->calc();
    EXPECT_EQ(8930, staff.at(12)->getPayment());
}

TEST(MyTests, test7) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(12)->setWorkTime(15);
    staff.at(12)->calc();
    staff.at(12)->setWorkTime(0);
    staff.at(12)->calc();
    EXPECT_EQ(2000, staff.at(12)->getPayment());
}

TEST(MyTests, test8) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    EXPECT_EQ("tester", staff.at(19)->getPosition());
}

TEST(MyTests, test9) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(19)->setWorkTime(10);
    staff.at(19)->calc();
    EXPECT_EQ(13733, staff.at(19)->getPayment());
}

TEST(MyTests, test10) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    EXPECT_EQ(0, staff.at(12)->getPayment());
}

TEST(MyTests, test11) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(22)->setWorkTime(2);
    staff.at(22)->calc();
    EXPECT_EQ(11566, staff.at(22)->getPayment());
}

TEST(MyTests, test12) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(24)->setWorkTime(2);
    staff.at(24)->calc();
    EXPECT_EQ(5126, staff.at(24)->getPayment());
}

TEST(MyTests, test13) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(27)->setWorkTime(4);
    staff.at(27)->calc();
    EXPECT_EQ(18900, staff.at(27)->getPayment());
}

TEST(MyTests, test14) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(28)->setWorkTime(10);
    staff.at(28)->calc();
    EXPECT_EQ(22800, staff.at(28)->getPayment());
}

TEST(MyTests, test15) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(30)->setWorkTime(7);
    staff.at(30)->calc();
    EXPECT_EQ(6880, staff.at(30)->getPayment());
}

TEST(MyTests, test16) {
    std::vector<Employee*> staff = StaffFactory::makeStaff();
    staff.at(31)->setWorkTime(40);
    staff.at(31)->calc();
    EXPECT_EQ(53200, staff.at(31)->getPayment());
}


