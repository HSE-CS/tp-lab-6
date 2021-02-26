#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <random>
#include "Interfaces.h"
#include "Factory.h"
#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"
#include "Employee.h"
#include "resource.h"

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
    ProjectManager* a = new ProjectManager(projects, 1, "ProjectManager", name, 25, 0);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(200000, a->getPayment());
}

TEST(Employee, TEST7) {
    Project* project = new Project(12, 100000);
    std::vector<Project*> projects;
    projects.push_back(project);
    std::string name = "Petr Ivanich";
    SeniorManager* a = new SeniorManager(project, projects, 1, "SeniorManager", name, 25, 0);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(project, a->getProject());
}

TEST(Employee, TEST8) {
    Project* project = new Project(12, 100000);
    std::vector<Project*> projects;
    projects.push_back(project);
    std::string name = "Petr Ivanich";
    SeniorManager* a = new SeniorManager(project, projects, 1, "SeniorManager", name, 25, 0);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(15000, a->calcBudjetPart(project->partForSeniors, project->budjet));
}


TEST(Employee, TEST9) {
    Project* project = new Project(12, 100000);
    std::vector<Project*> projects;
    projects.push_back(project);
    std::string name = "Petr Ivanich";
    SeniorManager* a = new SeniorManager(project, projects, 1, "SeniorManager", name, 25, 0);
    a->setWorkTime(25);
    a->calc();
    EXPECT_EQ(25000, a->calcBudjetPart(project->partForManagers, project->budjet));
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
    Resource* a = new Resource("staff.txt", "output.txt");
    std::vector<Employee*> staff;
    staff = makeStaff(a);
    EXPECT_EQ("Ivan", staff[0]->getName());
}

TEST(Employee, TEST12) {
    Resource* a = new Resource("staff.txt", "output.txt");
    std::vector<Employee*> staff;
    staff = makeStaff(a);
    EXPECT_EQ(1, staff[0]->getId());
}

TEST(Employee, TEST13) {
    Resource* a = new Resource("staff.txt", "output.txt");
    std::vector<Employee*> staff;
    staff = makeStaff(a);
    EXPECT_EQ("ProjectManager", staff[0]->getPosition());
}

TEST(Employee, TEST14) {
    Resource* a = new Resource("staff.txt", "output.txt");
    std::vector<Employee*> staff;
    staff = makeStaff(a);
    EXPECT_EQ("200000", staff[0]->getPayment());
}

TEST(Employee, TEST15) {
    std::string r = "staff.txt";
    std::string w = "output.txt";
    Resource* a = new Resource(r, w);
    std::vector<Employee*> staff;
    std::vector<Project*> Projects;
    staff = makeStaff(a);
    a->readpath = "projects.txt";
    makeStaffForProject(a, Projects, staff);
    for (Employee* emp : staff) {
        emp->calc();
    }
    EXPECT_EQ("160000", staff[1]->getPayment());
}