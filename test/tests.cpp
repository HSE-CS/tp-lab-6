// Copyright 2021 Nikolaev Ivan
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"


TEST(Factory, test1) {
    Driver driver(10, "Alex", DRIVER, 0, 200);
    EXPECT_EQ(10, driver.getId());
}

TEST(Factory, test2) {
    Driver driver(10, "Alex", DRIVER, 0, 200);
    EXPECT_EQ("Alex", driver.getName());
}

TEST(Factory, test3) {
    Driver driver(10, "Alex", DRIVER, 0, 200);
    EXPECT_EQ(3, driver.getPosition());
}

TEST(Factory, test4) {
    Driver driver(10, "Alex", DRIVER, 0, 200);
    EXPECT_EQ("Driver", driver.positionToString());
}

TEST(Factory, test5) {
    Driver driver(10, "Alex", DRIVER, 0, 200);
    EXPECT_EQ(0, driver.getWorktime());
}

TEST(Factory, test6) {
    Driver driver(10, "Alex", DRIVER, 50, 200);
    EXPECT_EQ(50, driver.getWorktime());
}

TEST(Factory, test7) {
    Driver driver(10, "Alex", DRIVER, 40, 200);
    driver.calc();
    int payment = driver.getPayment();
    EXPECT_EQ(8000, payment);
}

TEST(Factory, test8) {
    Driver driver(10, "Alex", DRIVER, 50, 200);
    driver.calc();
    EXPECT_EQ(11000, driver.getPayment());
}

TEST(Factory, test9) {
    Cleaner cleaner(20, "Nikolay", CLEANER, 40, 200);
    cleaner.calc();
    EXPECT_EQ(8000, cleaner.getPayment());
}

TEST(Factory, test10) {
    Cleaner cleaner(20, "Nikolay", CLEANER, 50, 200);
    cleaner.calc();
    EXPECT_EQ(10000, cleaner.getPayment());
}

TEST(Factory, test11) {
    Programmer programmer(15, "Pavel", PROGRAMMER, 40, 1000,
        new Project(1, 100000));
    programmer.calc();
    EXPECT_EQ(71000, programmer.getPayment());
}

TEST(Factory, test12) {
    Programmer programmer(15, "Pavel", PROGRAMMER, 40, 1000,
        new Project(1, 100000));
    programmer.giveBonus();
    programmer.calc();
    EXPECT_EQ(71000, programmer.getPayment());
}

TEST(Factory, test13) {
    Tester tester(15, "Pavel", TESTER, 40, 800, new Project(1, 100000));
    tester.calc();
    EXPECT_EQ(33000, tester.getPayment());
}

TEST(Factory, test14) {
    Tester tester(15, "Pavel", TESTER, 40, 800, new Project(1, 100000));
    tester.addMistakes();
    tester.calc();
    EXPECT_EQ(34000, tester.getPayment());
}

TEST(Factory, test15) {
    Tester tester(15, "Pavel", TESTER, 40, 800, new Project(1, 100000));
    tester.addMistakes(2);
    tester.calc();
    EXPECT_EQ(35000, tester.getPayment());
}

TEST(Factory, test16) {
    Tester tester(15, "Pavel", TESTER, 50, 800, new Project(1, 100000));
    tester.addMistakes(2);
    tester.calc();
    EXPECT_EQ(47000, tester.getPayment());
}
