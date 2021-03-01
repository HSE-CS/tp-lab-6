// Copyright 2020 GHA Test Team

#include "gtest/gtest.h"
#include "Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"

TEST(TestStaff, Test1) {
    Project pr = { "Online banking", 230490 };
    Employee* emp = new Engineer("0004896ET2", "Evan Tate", "Engineer", 1550, pr);
    EXPECT_EQ("Engineer", emp->getPosition());
}

TEST(TestStaff, Test2) {
    Employee* emp = new Cleaner("0004896AW2", "Adele Wilkinson", "Cleaner", 550);
    EXPECT_EQ("Adele Wilkinson", emp->getName());
}

TEST(TestStaff, Test3) {
    Project pr = { "Online banking", 230490 };
    Employee* emp = new Engineer("0004896ET2", "Evan Tate", "Engineer", 1550, pr);
    emp->setWorkTime(37);
    emp->calc();
    EXPECT_EQ(80399, emp->getPayment());
}

TEST(TestStaff, Test4) {
    Project pr = { "Navigator", 550000 };
    std::vector<Project> projects;
    projects.push_back(pr);
    Employee* emp = new ProjectManager("0004896ET2", "Evan Tate", "ProjectManager", projects);
    EXPECT_EQ(emp->getId(), "0004896ET2");
}

TEST(TestStaff, Test5) {
    Project pr = { "Navigator", 550000 };
    std::vector<Project> projects;
    projects.push_back(pr);
    Employee* emp = new SeniorManager("0004896ET2", "Evan Tate", "SeniorManager", projects);
    emp->setWorkTime(20);
    emp->calc();
    EXPECT_EQ(emp->getPayment(), 240000);
}

TEST(TestStaff, Test6) {
    Driver* emp = new Driver("0001300ME2", "Marilyn Ellis", "Driver", 1200);
    emp->setWorkTime(30);
    EXPECT_EQ(1200 * 30 * 0.2, emp->calcBonus());
}

TEST(TestStaff, Test7) {
    Driver* emp = new Driver("0001300ME2", "Marilyn Ellis", "Driver", 1200);
    emp->setWorkTime(30);
    EXPECT_EQ(1200 * 30, emp->calcBase(1200, 30));
}

TEST(TestStaff, Test8) {
    Project pr = { "Online banking", 400000 };
    Tester* emp = new Tester("0001300ME2", "Marilyn Ellis", "Tester", 1200, pr);
    emp->setWorkTime(30);
    emp->calc();
    EXPECT_EQ(30 * 1200 * 0.4, emp->calcProAdditins());
}

TEST(TestStaff, Test9) {
    Project pr1 = { "Navigator", 550000 };
    Project pr2 = { "Online banking", 400000 };
    std::vector<Project> projects;
    projects.push_back(pr1);
    projects.push_back(pr2);
    ProjectManager* emp = new ProjectManager("0004896ET2", "Evan Tate", "ProjectManager", projects);
    emp->setWorkTime(30);
    emp->calc();
    EXPECT_EQ(550000, emp->getProjects()[0].budget);
}

TEST(TestStaff, Test10) {
    Project pr1 = { "Navigator", 550000 };
    Project pr2 = { "Online banking", 400000 };
    std::vector<Project> projects;
    projects.push_back(pr1);
    projects.push_back(pr2);
    ProjectManager* emp = new ProjectManager("0004896ET2", "Evan Tate", "ProjectManager", projects);
    emp->setWorkTime(30);
    emp->calc();
	EXPECT_EQ("Online banking", emp->getProjects()[1].name);
}
TEST(TestStaff, Test11) {
    Project pr = { "Online banking", 350000 };
    TeamLeader* emp = new TeamLeader("0004896ET2", "Evan Tate", "TeamLeader", 2000, pr);
    emp->setWorkTime(30);
    emp->calc();
    EXPECT_EQ(10000, emp->calcHeads());
}

TEST(TestStaff, Test12) {
    Project pr1 = { "Navigator", 550000 };
    Project pr2 = { "Online banking", 400000 };
    std::vector<Project> projects;
    projects.push_back(pr1);
    projects.push_back(pr2);
    SeniorManager* emp = new SeniorManager("0004896ET2", "Evan Tate", "SeniorManager", projects);
    emp->setWorkTime(20);
    emp->calc();
    int bonus = (550000 + 400000) * 20 * 0.02;
    EXPECT_EQ(bonus + 20000, emp->getPayment());
}

TEST(TestStaff, Test13) {
    Cleaner* emp = new Cleaner("0004896AW2", "Adele Wilkinson", "Cleaner", 550);
    emp->setWorkTime(25);
    EXPECT_EQ(25, emp->getWorktime());
}

TEST(TestStaff, Test14) {
    Project pr = { "Online banking", 230490 };
    Engineer* emp = new Engineer("0004896ET2", "Evan Tate", "Engineer", 1550, pr);
    emp->setWorkTime(25);
    EXPECT_EQ(0.1 * 230490, emp->calcBugetPart(0.1, pr.budget));
}

TEST(TestStaff, Test15) {
	Project pr = { "Online banking", 230490 };
	Programmer* emp = new Programmer("0004896ET2", "Evan Tate", "Programmer", 1550, pr);
	emp->setWorkTime(25);
	EXPECT_EQ(25 * 1550 * 0.5, emp->calcProAdditins());
}
