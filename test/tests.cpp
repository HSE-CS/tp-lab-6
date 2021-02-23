// Copyright 2021 BekusovMikhail

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"

TEST(all, test1) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    EXPECT_EQ("99", programmist.getId());
}

TEST(all, test2) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    EXPECT_EQ("Piter Porker", programmist.getName());
}

TEST(all, test3) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    EXPECT_EQ(0, programmist.getPosition());
}

TEST(all, test4) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    EXPECT_EQ(1500, programmist.getSalary());
}

TEST(all, test5) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    EXPECT_EQ(52500, programmist.calcBase(programmist.getSalary(), programmist.getWorkTime()) );

}

TEST(all, test6) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    programmist.setWorkTime(35);
    EXPECT_EQ(35, programmist.getWorkTime());
}

TEST(all, test7) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    EXPECT_EQ(0, programmist.calcBonus());
}

TEST(all, test8) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    EXPECT_EQ(7500, programmist.calcBudgetPart((float) 0.05, programmist.getProject()->getBudget()));
}

TEST(all, test9) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    EXPECT_EQ("10", programmist.getProject()->getId());
}

TEST(all, test10) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    EXPECT_EQ(0, programmist.getPayment());
}

TEST(all, test11) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    programmist.calc();
    EXPECT_EQ(60000, programmist.getPayment());
}

TEST(all, test12) {
    Programmer programmist = Programmer
        ("99", "Piter Porker", PROG, 1500, new Project("10", 150000));
    programmist.setSalary(2500);
    EXPECT_EQ(2500, programmist.getSalary());
}

TEST(all, test13) {
    Driver driver = Driver("50", "Piter Drifter", DRIV, 150);
    driver.setWorkTime(80);
    driver.calc();
    EXPECT_EQ(24000, driver.getPayment());
}

TEST(all, test14) {
    Driver driver = Driver("50", "Piter Drifter", DRIV, 150);
    EXPECT_EQ(5, driver.getPosition());
}

TEST(all, test15) {
    std::vector<Project *> projects;
    projects.push_back(new Project("11", 200000));
    ProjectManager PM = ProjectManager("5", "Debra Mendoza", PRMA, projects);
    PM.calc();
    EXPECT_EQ(40000, PM.getPayment());
}
