// Copyright 2021 Sozinov Kirill

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

TEST(StaffDemoTest, test1) {
    unsigned int id = 1;
    std::string name = "Steve Jobs";
    std::string position = "Cleaner";
    unsigned int salary = 15;
    Cleaner employee(id, name, position, salary);
    EXPECT_EQ("Steve Jobs", employee.getName());
}

TEST(StaffDemoTest, test2) {
    unsigned int id = 2;
    std::string name = "Steve Jobs";
    std::string position = "Cleaner";
    unsigned int salary = 15;
    Cleaner employee(id, name, position, salary);
    EXPECT_EQ("Cleaner", employee.getPosition());
}

TEST(StaffDemoTest, test3) {
    unsigned int id = 3;
    std::string name = "Steve Jobs";
    std::string position = "Cleaner";
    unsigned int salary = 15;
    Cleaner employee(id, name, position, salary);
    EXPECT_EQ(0, employee.getWorktime());
}

TEST(StaffDemoTest, test4) {
    unsigned int id = 4;
    std::string name = "Bill Gates";
    std::string position = "Driver";
    unsigned int salary = 25;
    Driver employee(id, name, position, salary);
    employee.setWorktime(40);
    EXPECT_EQ(40, employee.getWorktime());
}

TEST(StaffDemoTest, test5) {
    unsigned int id = 5;
    std::string name = "Nataly Portman";
    POSITION position = CLEANER;
    unsigned int salary = 8;
    Cleaner employee(id, name, position, salary);
    employee.setWorktime(50);
    employee.calc();
    EXPECT_EQ(400, employee.getPayment());
}

TEST(StaffDemoTest, test6) {
    unsigned int id = 6;
    std::string name = "Bill Gates";
    std::string position = "Driver";
    unsigned int salary = 25;
    Driver employee(id, name, position, salary);
    employee.setWorktime(10);
    EXPECT_EQ(350, employee.getWorktime());
}

