#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"
#include <gtest/gtest.h>
#include <string>
#include <map>

TEST(lab6, task1) {
    Driver* emp = new Driver("Alex", 77, 300, "Driver", 1.5);
    unsigned int res = emp->getId();
    EXPECT_EQ(77, res);
}

TEST(lab6, task2) {
    Driver* emp = new Driver("Alex", 78, 300, "Driver", 1.5);
    std::string res = emp->getName();
    EXPECT_EQ("Alex", res);
}

TEST(lab6, task3) {
    Driver* emp = new Driver("Alex", 79, 300, "Driver", 1.5);
    emp->setWorkTime(40);
    unsigned int res = emp->getWorkTime();
    EXPECT_EQ(40, res);
}


TEST(lab6, task4) {
    Driver* emp = new Driver("Alex", 1, 400, "Driver", 1.5);
    emp->setWorkTime(10);
    float res = emp->getPayment();
    EXPECT_EQ(6000, res);
}

TEST(lab6, task5) {
    extern std::map<std::string, int> projects;
    projects["Hello"] = 10000;
    Programmer* emp = new Programmer("Alex", 2, 400, "Programmer", "Hello", 0.3);
    emp->setWorkTime(10);
    float res = emp->getPayment();
    EXPECT_EQ(7000, res);
}

TEST(lab6, task6) {
    extern std::map<std::string, int> projects;
    projects["Bye"] = 10000;
    Manager* emp = new Manager("Alex", 3, "Manager", "Bye", 0.7);
    float res = emp->getPayment();
    EXPECT_EQ(7000, res);
}

TEST(lab6, task7) {
    extern std::map<std::string, int> projects;
    projects["Bye"] = 10000;
    Manager* emp = new Manager("Alex", 3, "Manager", "Bye", 0.7);
    float res = emp->getPayment();
    EXPECT_EQ(7000, res);
}

TEST(lab6, task8) {
    extern std::map<std::string, int> projects;
    projects["Z"] = 10000;
    SeniorManager* emp = new SeniorManager("Alex", 3, "SeniorManager", "Z", 0.7, 10);
    float res = emp->getPayment();
    EXPECT_EQ(12000, res);
}

TEST(lab6, task9) {
    extern std::map<std::string, int> projects;
    projects["Leader"] = 10000;
    TeamLeader* emp = new TeamLeader("Alex", 3, 1000, "TeamLeader", "Leader", 0.7, 3);
    emp->setWorkTime(10);
    float res = emp->getPayment();
    EXPECT_EQ(21500, res);
}