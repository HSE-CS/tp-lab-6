// Copyright 2021 Islam Osmanov

#include "gtest/gtest.h"
#include "Factory.h"
#include "Manager.h"
#include "Employee.h"
#include "Engineer.h"
#include "Personal.h"

TEST(getTimeTest, Test1) {
Employee* driver = new Driver(1, 50, "DRIVER", "Islam");
driver->setWorkTime(50);
EXPECT_EQ(driver->getWorkTime(), 50);
}

TEST(getPositionTest, Test2) {
Employee* driver = new Driver(1, 50, "DRIVER", "Islam");
EXPECT_EQ(driver->getPosition(), "DRIVER");
}

TEST(getNameTest, Test3) {
Employee* driver = new Driver(1, 50, "DRIVER", "Islam");
EXPECT_EQ(driver->getName(), "Islam");
}

TEST(getIdTest, Test4) {
Employee* driver = new Driver(1, 50, "DRIVER", "Islam");
EXPECT_EQ(driver->getId(), 1);
}

TEST(CalcTest, Test5) {
Employee* driver = new Driver(1, 50, "DRIVER", "Islam");
driver->calc()
EXPECT_EQ(driver->getPayment(), 3000);
}

TEST(CleanerCalcTest, Test6) {
Employee* cleaner = new Cleaner(2, 800, "CLEANER", "Anna");
cleaner->setWorkTime(45);
cleaner->calc();
EXPECT_EQ(cleaner->getPayment(), 36000);
}

TEST(TesterErrorsTest, Test7) {
Project* proj1 = new Project(1, 200000);
Tester* tester = new Tester(1, "TESTER", "vOLF", 800, proj1);
tester->addErrors();
tester->addErrors();
EXPECT_EQ(tester->getErrorsNum(), 2);
}

TEST(TesterCalcTest, Test8) {
Project* proj1 = new Project(1, 200000);
Tester* tester = new Tester(1, "TESTER", "vOLF", 800, proj1);
tester->addErrors();
tester->addErrors();
Employee* testPay = tester;
testPay->calc();
EXPECT_EQ(testPay->getPayment(), 13355);
}

TEST(ProgrammerTest, Test9) {
Project* proj2 = new Project(1, 200000);
Employee* progr = new Programmer(3, "PROGRAMMER", "vAD", 1000, proj2);
EXPECT_EQ(progr->getPosition(), "PROGRAMMER");
}

TEST(ProgrammerCalcTest, Test10) {
Project* proj2 = new Project(1, 200000);
Employee* progr = new Programmer(3, "PROGRAMMER", "vAD", 1000, proj2);
progr->calc();
EXPECT_EQ(progr->getPayment(), 15333);
}

TEST(ProgectTest, Test11) {
Project* proj3 = new Project(1, 200000);
proj3->addWorkers(5);
EXPECT_EQ(proj3->getWorkersNum(), 5);
}

TEST(TeamLeadTest, Test12) {
Project* proj3 = new Project(1, 200000);
proj3->addWorkers(5);
TeamLeader* teamlead = new TeamLeader(2,
                                      "TEAMLEADER",
                                      "QWE",
                                      1000,
                                      proj3->getWorkersNum(), proj3);

EXPECT_EQ(teamlead->getProgrammers(), 5);
}

TEST(ProgectManagerBudgetTest, Test13) {
Project* proj3 = new Project(1, 200000);
proj3->addWorkers(5);
ProjectManager* pj = new ProjectManager(2,
                                        "PROJECTMANAGER",
                                        "KARL",
                                        8, proj3, 900);
EXPECT_EQ(pj->calcBudgetPart(2,proj3->getBudget()), 100000);
}

TEST(ProgectManagerAdditionsTest, Test14) {
Project* proj3 = new Project(1, 200000);
proj3->addWorkers(5);
ProjectManager* pj = new ProjectManager(2,
                                        "PROJECTMANAGER",
                                        "KARL",
                                        8, proj3, 900);
EXPECT_EQ(pj->calcProAdditions(5), 40);
}

TEST(SeniorManagerTest, Test15) {
Project* proj3 = new Project(1, 200000);
proj3->addWorkers(5);
std::vector<Project*> projects;
projects.push_back(proj3);
Employee* sm = new SeniorManager(3, "SENIORMANAGER", "BNM", projects, 10, 0);
sm->calc();

EXPECT_EQ(sm->getPayment(), 40500);
}








