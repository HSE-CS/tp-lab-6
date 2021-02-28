#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <fstream>
#include "Employee.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Programmer.h"
#include "TeamLeader.h"
#include "Tester.h"
#include "ProjectManager.h"
#include "SeniorManager.h"
#include "Engineer.h" 

TEST(DriverTest, Test1) {
    Employee* emp = new Driver(1, "my name", "driver" , 100);
    EXPECT_EQ("my name", emp->getName());
}

TEST(DriverTest, Test2) {
    Driver * dr = new Driver(1, "my name", "driver", 100);
    int result = (int)dr->calcBase(40);
    EXPECT_EQ(40 * 100, result);
}

TEST(DriverTest, Test3) {
    Employee* emp = new Driver(1, "my name", "driver", 100);
    emp->setWorkTime();
    int time = emp->getWorkTime();
    emp->calc();
    int result = emp->getPayment();
    EXPECT_GE(time * 100, result);
}

TEST(CleanerTest, Test4) {
    Employee* emp = new Cleaner(1, "my name", "cleaner", 200);
    emp->setWorkTime();
    int time = emp->getWorkTime();
    emp->calc();
    int result = emp->getPayment();
    EXPECT_EQ(200 * time, result);
}

TEST(ProgrammerTest, Test5) {
    Project* project = new Project(1, 1000, "pr");
    Employee* emp = new Programmer(1, "my name", "programmer", 10, project);
    project->AddMember();
    emp->setWorkTime();
    int time = emp->getWorkTime();
    emp->calc();
    int result = emp->getPayment();
    EXPECT_GE(0.1 * 1000 + time * 10, result);
}

TEST(ProgrammerTest, Test5) {
    Project* project = new Project(1, 1000, "pr");
    Programmer* pr = new Programmer(1, "my name", "programmer", 10, project);
    int result = pr->calcBudgetPart(0.4, 1000);
    EXPECT_EQ(0.4 * 1000, result);
}

TEST(TesterTest, Test6) {
    Project* project = new Project(1, 1000, "pr");
    Employee* emp = new Tester(1, "my name", "programmer", 10, project);
    project->AddMember();
    emp->setWorkTime();
    int time = emp->getWorkTime();
    emp->calc();
    int result = emp->getPayment();
    EXPECT_GE((int)(0.2 * 1000 + time * 10), result);
}

TEST(TeamLeaderTest, Test7) {
    Project* project = new Project(1, 1000, "pr");
    project->AddMember();
    project->AddMember();
    project->AddProgrammer();
    Employee* emp = new TeamLeader(1, "my name", "team leader", 20, project);
    emp->setWorkTime();
    int time = emp->getWorkTime();
    emp->calc();
    int result = emp->getPayment();
    double expect = 1 * 10 + 0.3 * 1000 + 20 * time;
    EXPECT_EQ((int)expect, result);
}

TEST(TeamLeaderTest, Test8) {
    Project* project = new Project(1, 1000, "pr");
    project->AddProgrammer();
    TeamLeader* tl = new TeamLeader(1, "my name", "team leade", 30, project);
    int result = tl->calcHeads();
    EXPECT_EQ(10, result);
}

TEST(TeamLeaderTest, Test9) {
    Project* project = new Project(1, 1000, "pr");
    project->AddProgrammer();
    TeamLeader* tl = new TeamLeader(1, "my name", "team leade", 30, project);
    double result = tl->calcBudgetPart(0.3, project->getBudget());
    double exp = 0.3 * 1000;
    EXPECT_DOUBLE_EQ(exp, result);
}

TEST(ProjectManagerTest, Test10) {
    Project* project = new Project(1, 1000, "pr");
    project->AddProgrammer();
    project->AddMember();
    project->AddMember();
    Employee* emp = new ProjectManager(1, "my name", "manager", project);
    emp->calc();
    int result = emp->getPayment();
    double exp = 0.4 * 1000 + 2 * 13;
    EXPECT_EQ((int)exp, result);
}

TEST(ProjectManagerTest, Test11) {
    Project* project = new Project(1, 1000, "pr");
    project->AddProgrammer();
    project->AddMember();
    project->AddMember();
    ProjectManager* pm = new ProjectManager(1, "my name", "manager", project);
    int result = pm->calcHeads();
    EXPECT_EQ(2 * 13, result);
}

TEST(ProjectTest, Test12) {
    Project* pr = new Project(1, 100, "pr");
    pr->AddProgrammer();
    pr->AddMember();
    pr->AddMember();
    int result = pr->getMember();
    EXPECT_EQ(2, result);
}

TEST(SeniorManagerTest, Test13) {
    std::vector<Project*> vt;
    vt.push_back(new Project(1, 100, "pr"));
    vt.push_back(new Project(2, 100, "pr1"));
    vt[0]->AddMember();
    vt[0]->AddMember();
    vt[1]->AddMember();
    vt[1]->AddMember();
    Employee* emp = new SeniorManager(1, "n", "s", vt);
    emp->calc();
    double result = emp->getPayment();
    double exp = (100 * 0.4 * 2 + 4 * 5);
    EXPECT_DOUBLE_EQ(exp, result);
}

TEST(ProgrammerTest, Test14) {
    Project* project = new Project(1, 1000, "pr");
    Programmer* pr = new Programmer(1, "my name", "programmer", 10, project);
    pr->setWorkTime();
    int time = pr->getWorkTime();
    double result = pr->calcBase(time);
    EXPECT_DOUBLE_EQ(10 * time, result);
}

TEST(TesterTest, Test15) {
    Project* project = new Project(1, 1000, "pr");
    Tester* ts = new Tester(1, "my name", "tester", 10, project);
    double result = ts->calcBudgetPart(0.2, project->getBudget());
    double exp = 0.2 * 1000;
    EXPECT_DOUBLE_EQ(exp, result);
}
