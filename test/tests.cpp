// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>


#include <vector>

#include "Engineer.h"
#include "Factory.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

TEST(Test, test1) {
    Cleaner a(1, "Lena", CLEANER, 20, 3, 4);
    EXPECT_EQ(1, a.get_Id());
}

TEST(Test, test2) {
    Cleaner b(2, "Masha", CLEANER, 20, 3, 4);
    EXPECT_EQ("Masha", b.get_Name());
}

TEST(Test, test3) {
    Cleaner c(3, "Dasha", CLEANER, 20, 3, 4);
    EXPECT_EQ(CLEANER, c.get_Position());
}

TEST(Test, test4) {
    int salary = 20;
    int worktime = 20;
    Driver d(4, "Vasya", DRIVER, worktime, 3, salary);   
    EXPECT_EQ(400, d.calcBase(salary, worktime));
}

TEST(Test, test5) {
    Driver e(5, "Kolya", DRIVER, 20, 3, 4);
    e.set_Worktime(30);
    EXPECT_EQ(30, e.get_Worktime());
}

TEST(Test, test6) {
    Programmer e1(6, "Ksusha", PROGRAMMER, 2, 3, 4, new Project(66, 30000));
    EXPECT_EQ("Ksusha", e1.get_Name());
}

TEST(Test, test7) {
    Tester e2(7, "Alisa", TESTER, 2, 3, 4, new Project(77, 30000));
    EXPECT_EQ(TESTER, e2.get_Position());
}

TEST(Test, test8) {
    TeamLeader e3(8, "Liza", TEAMLEADER, 2, 3, 4, new Project(88, 30000));
    EXPECT_EQ(TEAMLEADER, e3.get_Position());
}

TEST(StaffTest, test9) {
    TeamLeader e4(9, "Vanya", TEAMLEADER, 2, 3, 4, new Project(99, 30000));
    e4.set_Worktime(30);
    EXPECT_EQ(30, e4.get_Worktime());
}

TEST(Test, test10) {
    Programmer f(10, "Sasha", PROGRAMMER, 2, 3, 4, new Project(20, 30000));
    EXPECT_EQ(1000, f.calcProAdditions());
}

TEST(Test, test11) {
    Programmer g(11, "Misha", PROGRAMMER, 2, 3, 4, new Project(22, 30000));
    g.add_Bonus();
    int bon = 1;
    EXPECT_EQ(1, g.get_bonus());
}

TEST(Test, test12) {
    TeamLeader h(12, "Grisha", TEAMLEADER, 2, 3, 4, new Project(24, 30000));
    EXPECT_EQ(1000, h.calcHeads());
}

TEST(Test, test13) {
    double part = 0.1;
    int budget = 30000;
    Engineer k(13, "Matvey", ENGINEER, 2, 3, 4, new Project(26, budget));
    EXPECT_EQ(3000, k.calcBudgetPart(part, budget));
}

TEST(Test, test14) {
    double part = 0.1;
    int budget = 30000;
    Engineer m(14, "Timofey", ENGINEER, 2, 3, 4, new Project(28, budget));
    m.calc();
    EXPECT_EQ(3006, m.get_Payment());
}

TEST(Test, test15) {
    double part = 0.1;
    int budget = 100000;
    Engineer n(15, "Roman", ENGINEER, 2, 3, 4, new Project(30, budget));
    Project p(22, 100000);
    EXPECT_EQ(10006, n.get_Payment());
}