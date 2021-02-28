// Copyright 2021 dmitrycvetkov2000

#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "Project.h"

#include <gtest/gtest.h>
#include <string>
#include <unordered_set>

TEST(StaffTest, driverHasNightBonus) {
    Driver driver(1, "aaa", 200);
    driver.setWorkTime(100);
    ASSERT_EQ(driver.calcBonus(), 8 * 200 * 0.5);
}

TEST(StaffTest, cleanerHasNoBonus) {
    ASSERT_EQ(Cleaner(1, "aaa", 100).calcBonus(), 0);
}

TEST(StaffTest, engineerHasNoBudget) {
    auto project = new Project;
    project->budget = 10000;
    Engineer emp(1, "aaa", 100,
        Position::Engineer, project, 0.1);
    ASSERT_EQ(emp.calcBudget(0.1), 0);

    delete project;
}

TEST(StaffTest, engineerAddition) {
    auto project = new Project;
    project->budget = 10000;
    Engineer emp(1, "aaa", 100,
        Position::Engineer, project, 0.1);
    ASSERT_EQ(emp.calcProAdditions(), 1000);

    delete project;
}

TEST(StaffTest, programmerBudget) {
    auto project = new Project;
    project->budget = 10000;
    Programmer emp(1, "aaa", 100, project, 0.1);
    const auto budget = emp.calcBudget(0.1);
    ASSERT_EQ(budget, 1000);

    delete project;
}

TEST(StaffTest, programmerBonus) {
    auto project = new Project;
    project->budget = 10000;
    Programmer emp(1, "aaa", 100, project, 0.1);
    emp.setWorkTime(100);
    const auto bonus = emp.calcBonus();
    ASSERT_EQ(bonus, 500);

    delete project;
}

TEST(StaffTest, teamleadBudget) {
    auto project = new Project;
    project->budget = 10000;
    TeamLeader emp(1, "aaa", 100, project, 0.15);
    const auto budget = emp.calcBudget(0.1);
    ASSERT_EQ(budget, 1500);

    delete project;
}

TEST(StaffTest, teamleadBonus) {
    auto project = new Project;
    project->budget = 10000;
    TeamLeader emp(1, "aaa", 100, project, 0.1);
    emp.setWorkTime(100);
    const auto bonus = emp.calcBonus();
    ASSERT_EQ(bonus, 500);

    delete project;
}

TEST(StaffTest, testerBudget) {
    auto project = new Project;
    project->budget = 10000;
    TeamLeader emp(1, "aaa", 100, project, 0.05);
    const auto budget = emp.calcBudget(0.1);
    ASSERT_EQ(budget, 500);

    delete project;
}

TEST(StaffTest, testerBonus) {
    auto project = new Project;
    project->budget = 10000;
    TeamLeader emp(1, "aaa", 100, project, 0.1);
    const auto bonus = emp.calcBonus();
    ASSERT_EQ(bonus, 300);

    delete project;
}

TEST(StaffTest, pmNoAdditions) {
    ASSERT_EQ(ProjectManager(1, "aaa").calcProAdditions(), 0);
}

TEST(StaffTest, pmBudget) {
    auto project = new Project;
    project->budget = 10000;
    ProjectManager emp(1, "aaa", project, 0.05);
    const auto budget = emp.calcBudget(0.05);
    ASSERT_EQ(budget, 500);

    delete project;
}

TEST(StaffTest, pmHeads) {
    auto project = new Project;
    project->budget = 10000;
    ProjectManager emp(1, "aaa", project, 0.05);
    const auto budget = emp.calcHeads();
    ASSERT_EQ(budget, 1000);

    delete project;
}

TEST(StaffTest, smNoAdditions) {
    ASSERT_EQ(SeniorManager(1, "aaa", {}).calcProAdditions(), 0);
}

TEST(StaffTest, smBudget) {
    std::unordered_set<Project*> projects;
    auto project1 = new Project;
    project1->budget = 10000;
    projects.insert(project1);

    auto project2 = new Project;
    project2->budget = 20000;
    projects.insert(project2);

    SeniorManager emp(1, "aaa", std::move(projects));
    const auto budget = emp.calcBudget(0.05);
    ASSERT_EQ(budget, 1500);

    delete project1;
    delete project2;
}

TEST(StaffTest, smHeads) {
    std::unordered_set<Project*> projects;
    auto project1 = new Project;
    project1->budget = 10000;
    projects.insert(project1);

    auto project2 = new Project;
    project2->budget = 20000;
    projects.insert(project2);

    SeniorManager emp(1, "aaa", std::move(projects));
    const auto budget = emp.calcHeads();
    ASSERT_EQ(budget, 3600);

    delete project1;
    delete project2;
}
