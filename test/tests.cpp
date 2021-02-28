// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>


#include <gtest/gtest.h>
#include <string>
#include "../include/Interfaces.h"
#include "../include/Employee.h"
#include "../include/Engineer.h"
#include "../include/Factory.h"
#include "../include/Manager.h"
#include "../include/Personal.h"


TEST(Test_Employee, test_1) {
    Cleaner* person_test_1 = new Cleaner(78, "Vitalyi Petrovish",
        "Cleaner", 8, 456);
    EXPECT_EQ(78, person_test_1->getId());
}

TEST(Test_Employee, test_2) {
    Driver* person_test_2 = new Driver(76, "Alexandr Robertovish",
       "Driver", 6, 432);
    EXPECT_EQ("Alexandr Robertovish", person_test_2->getName());
}

TEST(Test_Employee, test_3) {
    Cleaner* person_test_3 = new Cleaner(78, "Vitalyi Petrovish",
      "Cleaner", 6, 436);
    EXPECT_EQ("Cleaner", person_test_3->getPosition());
}

TEST(Test_Employee, test_4) {
    Cleaner* person_test_4 = new Cleaner(78, "Vitalyi Petrovish",
      "Cleaner", 8, 456);
    EXPECT_EQ(8, person_test_4->getWorkTime());
}

TEST(Test_Employee, test_5) {
    Driver* person_test_5 = new Driver(76, "Alexandr Robertovish",
      "Driver", 6, 432);
    EXPECT_EQ(432, person_test_5->getPayment());
}

TEST(Test_Employee, test_6) {
    Driver* person_test_6 = new Driver(76, "Alexandr Robertovish",
      "Driver", 6, 432);
    person_test_6->setSalary(356);
    EXPECT_EQ(356, person_test_6->getSalary());
}

TEST(Test_Employee, test_7) {
    Driver* person_test_7 = new Driver(76, "Alexandr Robertovish",
      "Driver", 6, 432);
    person_test_7->setSalary(35);
    EXPECT_EQ(210, person_test_7->calcBase(person_test_7->getSalary(),
         person_test_7->getWorkTime()));
}

TEST(Test_Employee, test_8) {
    Driver* person_test_8 = new Driver(76, "Alexandr Robertovish",
       "Driver", 6, 432);
    person_test_8->setSalary(35);
    person_test_8->calcBase(person_test_8->getSalary(),
         person_test_8->getWorkTime());
    person_test_8->calcBonus();
    EXPECT_EQ(273, person_test_8->calc());
}

TEST(Test_Employee, test_9) {
    Project project_test_9 = { 1, "test_1", 1257 };
    EXPECT_EQ(1, project_test_9.id);
}

TEST(Test_Employee, test_10) {
    Project project_test_10 = { 1, "test_1", 1257 };
    EXPECT_EQ("test_1", project_test_10.name);
}

TEST(Test_Employee, test_11) {
    Project project_test_11 = { 1, "test_1", 1257 };
    EXPECT_EQ(1257, project_test_11.budget);
}

TEST(Test_Employee, test_12) {
    Project pr_1 = { 34, "task", 34589 };
    std::vector<Project*> projects;
    projects.push_back(&pr_1);
    ProjectManager* person_test_12 = new ProjectManager(
         2, "Boris Petrovish", "Project Manager", 1, 8, 12234, projects);
    EXPECT_EQ(145, person_test_12->calcHeads());
}

TEST(Test_Employee, test_13) {
    Project pr_1 = { 34, "task", 34589 };
    Project pr_2 = { 332, "task_", 37859 };
    std::vector<Project*> projects;
    projects.push_back(&pr_1);
    projects.push_back(&pr_2);
    ProjectManager* person_test_13 = new ProjectManager(
         2, "Boris Petrovish", "Project Manager", 2, 8, 12234, projects);
    EXPECT_EQ(290, person_test_13->calcHeads());
}

TEST(Test_Employee, test_14) {
    Project pr_1 = { 123, "asd", 444 };
    Project pr_2 = { 52, "rsdf", 99830 };
    Project pr_3 = { 5, "gradf", 489556 };
    Project pr_4 = { 10, "uysdc", 34556 };
    std::vector<Project*> projects;
    projects.push_back(&pr_1);
    projects.push_back(&pr_2);
    projects.push_back(&pr_3);
    projects.push_back(&pr_4);
    ProjectManager* person_test_14 = new ProjectManager(
        2, "Boris Petrovish", "Project Manager", 1, 8, 12234, projects);
    EXPECT_EQ(12234, person_test_14->getPayment());
}

TEST(Test_Employee, test_15) {
    Project pr_1 = { 123, "asd", 444 };
    Project pr_2 = { 52, "rsdf", 99830 };
    Project pr_3 = { 5, "gradf", 489556 };
    Project pr_4 = { 10, "uysdc", 34556 };
    std::vector<Project*> projects;
    projects.push_back(&pr_1);
    projects.push_back(&pr_2);
    projects.push_back(&pr_3);
    projects.push_back(&pr_4);
    ProjectManager* person_test_15 = new ProjectManager(
         2, "Boris Petrovish", "Project Manager", 4, 8, 12234, projects);
    EXPECT_EQ(580, person_test_15->calcProAdditions());
}
