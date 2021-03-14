// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"
#include "Factory.h"

TEST(Test, test1) {
    Staff newteam;
    Project * name = new Project("Microsoft", 1000);
    newteam.addMember(new SeniorManager("110", "Nikolay Krotov",
                      name));
    EXPECT_EQ(newteam.staffNumber(), 1);
}

TEST(Test, test2) {
    Staff newteam;
    Project * name = new Project("Microsoft", 1000);
    newteam.addMember(new SeniorManager("110", "Nikolay Krotov",
                      name));
    EXPECT_EQ(newteam.projectsNumber(), 1);
}

TEST(Test, test3) {
    Staff newteam;
    Project * name = new Project("Microsoft", 1000);
    newteam.addMember(new SeniorManager("110", "Nikolay Krotov",
                     name));
    newteam.addMember(new Cleaner("101", "Ekaterina Stupina", 30));
    newteam.addMember(new Tester("109", "Nikolay Popov", 60,
                     name));
    EXPECT_EQ(newteam.staffNumber(), 3);
}

TEST(Test, test4) {
    Cleaner example("101", "Ekaterina Stupina", 40);
    example.addWorkTime(10);
    example.calc();
    EXPECT_EQ(example.returnPayment(), 400);
}

TEST(Test, test5) {
    Driver example("101", "Ekaterina Stupina", 40);
    example.addWorkTime(40);
    example.calc();
    EXPECT_EQ(example.returnPayment(), 1800);
}

TEST(Test, test6) {
    Driver example("101", "Ekaterina Stupina", 40);
    example.addWorkTime(20);
    example.calc();
    EXPECT_EQ(example.returnPayment(), 800);
}

TEST(Test, test7) {
    std::ifstream file("work.txt");
    Staff newteam;
    newteam.makeStaff(std::move(file));
    newteam.addTimeToAll(40);
    EXPECT_EQ(newteam.staffNumber(), 12);
}

TEST(Test, test8) {
    std::ifstream file("work.txt");
    Staff newteam;
    newteam.makeStaff(std::move(file));
    newteam.addTimeToAll(40);
    EXPECT_EQ(newteam.projectsNumber(), 2);
}

TEST(Test, test9) {
    std::ifstream file("work.txt");
    Staff newteam;
    newteam.makeStaff(std::move(file));
    newteam.addTimeToAll(40);
    newteam.calcAll();
    EXPECT_EQ(newteam.returnPayment("107"), 210);
}

TEST(Test, test10) {
    std::ifstream file("work.txt");
    Staff newteam;
    newteam.makeStaff(std::move(file));
    newteam.addTimeToAll(40);
    newteam.calcAll();
    EXPECT_EQ(newteam.returnPayment("110"), 2410);
}

TEST(Test, test11) {
    std::ifstream file("work.txt");
    Staff newteam;
    newteam.makeStaff(std::move(file));
    newteam.addTimeToAll(40);
    newteam.calcAll();
    SeniorManager * newone = new SeniorManager("113",
     "NikolayKrotov", newteam.findProject("Microsoft"));
    newone->addProject(newteam.findProject("Oxford"));
    Employee * example = newone;
    example->addWorkTime(20);
    example->calc();
    newteam.addMember(example);
    EXPECT_EQ(newteam.returnPayment("113"), 620);
}

TEST(Test, test12) {
    std::ifstream file("work.txt");
    Staff newteam;
    newteam.makeStaff(std::move(file));
    newteam.addTimeToAll(40);
    newteam.calcAll();
    EXPECT_EQ(newteam.returnPayment("101"), 5110);
}

TEST(Test, test13) {
    std::ifstream file("work.txt");
    Staff newteam;
    newteam.makeStaff(std::move(file));
    newteam.addTimeToAll(40);
    newteam.calcAll();
    SeniorManager * newone = new SeniorManager("113",
     "NikolayKrotov", newteam.findProject("Microsoft"));
    Employee * example = newone;
    example->addWorkTime(20);
    example->calc();
    newteam.addMember(example);
    EXPECT_EQ(newteam.returnPayment("113"), 410);
}

TEST(Test, test14) {
    Tester example("101", "Ekaterina Stupina", 20,
                   new Project("New", 30));
    example.addWorkTime(10);
    example.calc();
    EXPECT_EQ(example.returnPayment(), 203);
}

TEST(Test, test15) {
    Tester example("101", "Ekaterina Stupina", 20,
                   new Project("New", 30));
    example.addWorkTime(10);
    example.errors(50);
    example.calc();
    EXPECT_EQ(example.returnPayment(), 1203);
}
