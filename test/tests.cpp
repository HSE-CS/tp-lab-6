// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <cstring>
#include <vector>

#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"

TEST(ENGINEERS, test1) {
    Project *project = new Project(1, 1000000);
    Engineer *engineer = new Programmer(1, "DIMA", "PythonDeveloper",
    1337, 20, project, 0.2);
    EXPECT_EQ(engineer->getSalary(), 1337);
}

TEST(ENGINEERS, test2) {
    Project *project = new Project(1, 1000);
    Engineer *engineer = new Programmer(
            1, "DIMA", "PythonDeveloper",
            1337, 20, project, 0.2);
    EXPECT_EQ(strcmp(engineer->getName().c_str(), "DIMA"), 0);
}

TEST(ENGINEERS, test3) {
    Project *project = new Project(1, 1000000);
    Engineer *engineer = new Programmer(
            1, "DIMA", "PythonDeveloper",
            1337, 20, project, 0.2);
    EXPECT_EQ(engineer->calc(), 20000);
}

TEST(ENGINEERS, test4) {
    Project *project = new Project(1, 1000000);
    Engineer *engineer1 = new TeamLeader(
            1, "Ahmed", "TeamLead",
            1337, 20, project, 0.2);
    Engineer *engineer2 = new TeamLeader(
            2, "Kek", "King",
            1337, 20, project, 0.2);
    EXPECT_EQ(strcmp(engineer1->getPosition(), "TeamLead"), 0);
}

TEST(ENGINEERS, test5) {
    Project *project = new Project(1, 1234);
    EXPECT_EQ(project->getBudget(), 1234);
}

TEST(PERSONAL, test6) {
    Personal *personal = new Driver(1, "Kek",
    "Driver", 1234, 80);
    EXPECT_EQ(1, personal->getId());
}

TEST(PERSONAL, test7) {
    Employee *employee = new Cleaner(
            1, "Kate", "cleaner",
            1000, 50);
    EXPECT_EQ(strcmp(employee->getPosition().c_str(),
                     "cleaner"), 0);
}

TEST(PERSONAL, test8) {
    Employee *employee = new Driver(
            50, "Lol",
            "driver", 300, 80);
    EXPECT_EQ(strcmp(employee->getName().c_str(), "lol"), 0);
}

TEST(PERSONAL, test9) {
    Employee* employee = new Driver(
            12, "anton", "driver", 500, 80);
    employee->calc();
    EXPECT_EQ(floor(employee->getSalary()), 500);
}

TEST(PERSONAL, test10) {
    Employee *cleaner = new Cleaner(
            1, "Qwe", "cleaner", 500, 51);
    EXPECT_EQ(25550, cleaner->calc());
}

TEST(MANAGERS, test11) {
    Project *project = new Project(1, 500000);
    Employee *employee = new ProjectManager(
            0, "KekLol",
            "project manager", project);
    EXPECT_EQ(strcmp(employee->getName().c_str(),
                     "KekLol"), 0);
}

TEST(MANAGERS, test12) {
    Project *project = new Project(1, 500000);
    ProjectManager *employee = new ProjectManager(
            0, "KekLol",
            "project manager", project);
    EXPECT_EQ(employee->getProject()->getId(), 1);
}

TEST(MANAGERS, test13) {
    Project *project1 = new Project(1, 100);
    Project *project2 = new Project(2, 200);
    std::vector<Project *> projects = {project1, project2};
    SeniorManager *seniorManager = new SeniorManager(
            1, "AsDfG", "Senior Manager",
            projects);
    EXPECT_EQ(2, seniorManager->getProjects()[0]->getId() *
                seniorManager->getProjects()[1]->getId());
}

TEST(MANAGERS, test14) {
    Project *project1 = new Project(1, 50000);
    Project *project2 = new Project(2, 100000);
    std::vector<Project *> projects = {project1, project2};
    SeniorManager *seniorManager = new SeniorManager(
            1, "AsDfG", "Senior Manager",
            projects);
    EXPECT_EQ(seniorManager->calc(), 45000);
}

TEST(MANAGERS, test15) {
    std::vector<Project *> projects = {};
    SeniorManager *seniorManager = new SeniorManager(
            1, "AsDfG", "Senior Manager",
            projects);
    EXPECT_EQ(seniorManager->calc(), 0);
}
