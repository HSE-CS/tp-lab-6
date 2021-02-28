// Copyright 2020 GHA Test Team
// #include "pch.h"
#include "gtest/gtest.h"
// #include "../Lab-6/Employee.cpp"
// #include "../Lab-6/Engineer.cpp"
// #include "../Lab-6/Factory.cpp"
// #include "../Lab-6/Manager.cpp"
// #include "../Lab-6/Personal.cpp"
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"


TEST(FactoryTest, TestInitData) {
  StaffFactory* staff_factory = new StaffFactory("staff.txt");
  std::vector<Employee*> staff = staff_factory->makeStaff();
  EXPECT_EQ(staff.size(), 7);
}


TEST(DriverTest, Test1) {
  Driver* driver = new Driver(1, "Ivanov Ivan Ivanich", 500);
  driver->setWorkTime(50);
  EXPECT_EQ(driver->calcBonus(), 10000);
}
TEST(DriverTest, Test2) {
  Driver* driver = new Driver(1, "Ivanov Ivan Ivanich", 500);
  driver->setWorkTime(50);
  EXPECT_EQ(driver->calcBase(500, 50), 25000);
}
TEST(DriverTest, Test3) {
  Driver* driver = new Driver(1, "Ivanov Ivan Ivanich", 500);
  driver->setWorkTime(50);
  driver->calc();
  EXPECT_EQ(driver->getPayment(), 35000);
}


TEST(CleanerTest, Test1) {
  Cleaner* cleaner = new Cleaner(2, "Zhdanova Alexandra Artemovna", 200);
  cleaner->setWorkTime(40);
  EXPECT_EQ(cleaner->calcBonus(), 0);
}
TEST(CleanerTest, Test2) {
  Cleaner* cleaner = new Cleaner(2, "Zhdanova Alexandra Artemovna", 200);
  cleaner->setWorkTime(40);
  EXPECT_EQ(cleaner->calcBase(200, 40), 8000);
}
TEST(CleanerTest, Test3) {
  Cleaner* cleaner = new Cleaner(2, "Zhdanova Alexandra Artemovna", 200);
  cleaner->setWorkTime(40);
  cleaner->calc();
  EXPECT_EQ(cleaner->getPayment(), 8000);
}


TEST(ProjectManagerTest, Test1) {
  Project* project = StaffFactory::createProject("project1", 50000, 10);
  ProjectManager* project_manager =
    new ProjectManager(3, "Tikhonov Emil Dmitrievich", project);
  project_manager->setWorkTime(40);
  EXPECT_EQ(project_manager->calcBudgetPart(0.5f, project->budget), 25000);
}
TEST(ProjectManagerTest, Test2) {
  Project* project = StaffFactory::createProject("project1", 50000, 10);
  ProjectManager* project_manager =
    new ProjectManager(3, "Tikhonov Emil Dmitrievich", project);
  project_manager->setWorkTime(40);
  EXPECT_EQ(project_manager->calcHeads(), 9000);
}
TEST(ProjectManagerTest, Test3) {
  Project* project = StaffFactory::createProject("project1", 50000, 10);
  ProjectManager* project_manager =
    new ProjectManager(3, "Tikhonov Emil Dmitrievich", project);
  project_manager->setWorkTime(40);
  project_manager->calc();
  EXPECT_EQ(project_manager->getPayment(), 34500);
}


Project** createTestThreeProjects() {
  Project** projects = new Project * [3];
  Project* project1 = StaffFactory::createProject("project1", 50000, 10);
  Project* project2 = StaffFactory::createProject("project2", 30000, 5);
  Project* project3 = StaffFactory::createProject("project3", 45000, 7);
  projects[0] = project1;
  projects[1] = project2;
  projects[2] = project3;
  return projects;
}

TEST(SeniorManagerTest, Test1) {
  Project** projects = createTestThreeProjects();
  SeniorManager* senior_manager =
    new SeniorManager(4, "Zelenin Roman Pavlovich", projects, 3);
  senior_manager->setWorkTime(45);
  EXPECT_EQ(senior_manager->calcBudgetPart(0.2f), 25000);
}
TEST(SeniorManagerTest, Test2) {
  Project** projects = createTestThreeProjects();
  SeniorManager* senior_manager =
    new SeniorManager(4, "Zelenin Roman Pavlovich", projects, 3);
  senior_manager->setWorkTime(45);
  EXPECT_EQ(senior_manager->calcHeads(), 19000);
}
TEST(SeniorManagerTest, Test3) {
  Project** projects = createTestThreeProjects();
  SeniorManager* senior_manager =
    new SeniorManager(4, "Zelenin Roman Pavlovich", projects, 3);
  senior_manager->setWorkTime(45);
  senior_manager->calc();
  EXPECT_EQ(senior_manager->getPayment(), 45500);
}


TEST(TesterTest, Test1) {
  Project* project = StaffFactory::createProject("project1", 50000, 10);
  Tester* tester = new Tester(5, "Sharov Artem Platonovich", 750, project);
  tester->setWorkTime(48);
  EXPECT_EQ(tester->calcBase(750, 48), 36000);
}
TEST(TesterTest, Test2) {
  Project* project = StaffFactory::createProject("project1", 50000, 10);
  Tester* tester = new Tester(5, "Sharov Artem Platonovich", 750, project);
  tester->setWorkTime(48);
  EXPECT_EQ(tester->calcBudgetPart(0.1f, project->budget), 5000);
}
TEST(TesterTest, Test3) {
  Project* project = StaffFactory::createProject("project1", 50000, 10);
  Tester* tester = new Tester(5, "Sharov Artem Platonovich", 750, project);
  tester->setWorkTime(48);
  tester->calc();
  EXPECT_EQ(tester->getPayment(), 43600);
}


TEST(ProgrammerTest, Test1) {
  Project* project = StaffFactory::createProject("project2", 25000, 5);
  Programmer* programmer =
    new Programmer(6, "Skvortsova Maria Nikitichna", 1000, project);
  programmer->setWorkTime(35);
  EXPECT_EQ(programmer->calcBase(1000, 35), 35000);
}
TEST(ProgrammerTest, Test2) {
  Project* project = StaffFactory::createProject("project2", 25000, 5);
  Programmer* programmer =
    new Programmer(6, "Skvortsova Maria Nikitichna", 1000, project);
  programmer->setWorkTime(35);
  EXPECT_EQ(programmer->calcBudgetPart(0.1f, project->budget), 2500);
}
TEST(ProgrammerTest, Test3) {
  Project* project = StaffFactory::createProject("project2", 25000, 5);
  Programmer* programmer =
    new Programmer(6, "Skvortsova Maria Nikitichna", 1000, project);
  programmer->setWorkTime(35);
  programmer->calc();
  EXPECT_EQ(programmer->getPayment(), 40250);
}


TEST(TeamLeaderTest, Test1) {
  Project* project = StaffFactory::createProject("project3", 35000, 7);
  TeamLeader* team_leader =
    new TeamLeader(7, "Rusanov Makar Artemyevich", 2000, project);
  team_leader->setWorkTime(40);
  EXPECT_EQ(team_leader->calcBase(2000, 40), 80000);
}
TEST(TeamLeaderTest, Test2) {
  Project* project = StaffFactory::createProject("project3", 35000, 7);
  TeamLeader* team_leader =
    new TeamLeader(7, "Rusanov Makar Artemyevich", 2000, project);
  team_leader->setWorkTime(40);
  EXPECT_EQ(team_leader->calcBudgetPart(0.1f, project->budget), 3500);
}
TEST(TeamLeaderTest, Test3) {
  Project* project = StaffFactory::createProject("project3", 35000, 7);
  TeamLeader* team_leader =
    new TeamLeader(7, "Rusanov Makar Artemyevich", 2000, project);
  team_leader->setWorkTime(40);
  EXPECT_EQ(team_leader->calcHeads(), 9000);
}
TEST(TeamLeaderTest, Test4) {
  Project* project = StaffFactory::createProject("project3", 35000, 7);
  TeamLeader* team_leader =
    new TeamLeader(7, "Rusanov Makar Artemyevich", 2000, project);
  team_leader->setWorkTime(40);
  team_leader->calc();
  EXPECT_EQ(team_leader->getPayment(), 95250);
}
