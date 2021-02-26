//  Copyright Baklanov 2021
#include <gtest/gtest.h>
#include <string>
#include "Interfaces.h"
#include "Factory.h"
#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"
#include "Employee.h"
#include "Resource.h"

TEST(Employee, TEST1) {
    std::string name = "Petr Ivanich";
    Cleaner* a = new Cleaner(1, "Cleaner", name, 25, 0, 250);
    EXPECT_EQ(1, a->getId());
}

TEST(Employee, TEST2) {
    std::string name = "Petr Ivanich";
    Cleaner* a = new Cleaner(1, "Cleaner", name, 25, 0, 250);
    EXPECT_EQ("Petr Ivanich", a->getName());
}

TEST(Employee, TEST3) {
    std::string name = "Petr Ivanich";
    Cleaner* a = new Cleaner(1, "Cleaner", name, 25, 0, 250);
    a->setWorkTime(25);
    EXPECT_EQ(0, a->getPayment());
}

TEST(Employee, TEST4) {
    std::string name = "Petr Ivanich";
    Cleaner* a = new Cleaner(1, "Cleaner", name, 25, 0, 250);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(25*250, a->getPayment());
}

TEST(Employee, TEST5) {
    std::string name = "Petr Ivanich";
    Driver* a = new Driver(1, "Driver", name, 25, 0, 250);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(25 * 250 + 2000, a->getPayment());
}

TEST(Employee, TEST6) {
    Project* project = new Project(12, 100000);
    std::vector<Project*> projects;
    projects.push_back(project);
    std::string name = "Petr Ivanich";
    ProjectManager* a = new ProjectManager(projects,
        1, "ProjectManager", name, 25, 0);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(200000, a->getPayment());
}

TEST(Employee, TEST7) {
    Project* project = new Project(12, 100000);
    std::vector<Project*> projects;
    projects.push_back(project);
    std::string name = "Petr Ivanich";
    SeniorManager* a = new SeniorManager(project,
        projects, 1, "SeniorManager", name, 25, 0);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(project, a->getProject());
}

TEST(Employee, TEST8) {
    Project* project = new Project(12, 100000);
    std::vector<Project*> projects;
    projects.push_back(project);
    std::string name = "Petr Ivanich";
    SeniorManager* a = new SeniorManager(project,
        projects, 1, "SeniorManager", name, 25, 0);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(15000, a->calcBudjetPart(project->partForSeniors,
        project->budjet));
}


TEST(Employee, TEST9) {
    Project* project = new Project(12, 100000);
    std::vector<Project*> projects;
    projects.push_back(project);
    std::string name = "Petr Ivanich";
    SeniorManager* a = new SeniorManager(project,
        projects, 1, "SeniorManager", name, 25, 0);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(25000, a->calcBudjetPart(project->partForManagers,
        project->budjet));
}

TEST(Employee, TEST10) {
    Project* project = new Project(12, 100000);
    std::vector<Project*> projects;
    projects.push_back(project);
    std::string name = "Petr Ivanich";
    Engineer* a = new Engineer(project, 1, "Engineer", name, 25, 0, 1000);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(project, a->getProject());
}

TEST(Employee, TEST11) {
    Project* project1 = new Project(12, 100000);
    Project* project2 = new Project(15, 200000);
    std::vector<Project*> projects;
    projects.push_back(project1);
    projects.push_back(project2);
    std::string name = "Petr Ivanich";
    Engineer* a = new Engineer(project2, 1, "Engineer", name, 25, 0, 1000);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(project2, a->getProject());
}

TEST(Employee, TEST12) {
    Project* project1 = new Project(12, 100000);
    Project* project2 = new Project(15, 200000);
    std::vector<Project*> projects;
    projects.push_back(project1);
    projects.push_back(project2);
    std::string name = "Petr Ivanich";
    ProjectManager* a = new ProjectManager(project2, 1, "Engineer", name, 25, 0, 1000);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(15, project1.id);
}

TEST(Employee, TEST13) {
    Project* project1 = new Project(12, 100000);
    Project* project2 = new Project(15, 200000);
    std::vector<Project*> projects;
    projects.push_back(project1);
    projects.push_back(project2);
    std::string name = "Petr Ivanich";
    ProjectManager* a = new ProjectManager(project2, 1, "Engineer", name, 25, 0, 1000);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(100000, project1->budjet);
}

TEST(Employee, TEST14) {
    Project* project1 = new Project(12, 100000);
    Project* project2 = new Project(15, 200000);
    std::vector<Project*> projects;
    projects.push_back(project1);
    projects.push_back(project2);
    std::string name = "Petr Ivanich";
    Engineer* a = new Engineer(project2, 1, "Engineer", name, 25, 0, 1000);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(25*1000+project2->budjet*25, a->getPayment());
}

TEST(Employee, TEST15) {
    Project* project1 = new Project(12, 100000);
    Project* project2 = new Project(15, 200000);
    std::vector<Project*> projects;
    projects.push_back(project1);
    projects.push_back(project2);
    std::string name = "Petr Ivanich";
    Tester* a = new Tester(project2, 1, "Tester", name, 25, 0, 1000);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(project2, a->getProject())
}
