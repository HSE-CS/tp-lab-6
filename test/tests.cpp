// Copyright 2021 Kuznetsov Mikhail
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

TEST(StaffDemoTest, test1) {
  unsigned int id = 2021;
  std::string name = "Esther Mann";
  POSITION position = DRIVER;
  unsigned int salary = 9;
  Driver employee(id, name, position, salary);
  EXPECT_EQ("Esther Mann", employee.getName());
}

TEST(StaffDemoTest, test2) {
  unsigned int id = 2021;
  std::string name = "Esther Mann";
  POSITION position = DRIVER;
  unsigned int salary = 9;
  Driver employee(id, name, position, salary);
  EXPECT_EQ(DRIVER, employee.getPosition());
}

TEST(StaffDemoTest, test3) {
  unsigned int id = 2021;
  std::string name = "Esther Mann";
  POSITION position = DRIVER;
  unsigned int salary = 9;
  Driver employee(id, name, position, salary);
  EXPECT_EQ(0, employee.getWorktime());
}

TEST(StaffDemoTest, test4) {
  unsigned int id = 2019;
  std::string name = "Katie Clark";
  POSITION position = CLEANER;
  unsigned int salary = 8;
  Cleaner employee(id, name, position, salary);
  employee.setWorktime(40);
  EXPECT_EQ(40, employee.getWorktime());
}

TEST(StaffDemoTest, test5) {
  unsigned int id = 2019;
  std::string name = "Katie Clark";
  POSITION position = CLEANER;
  unsigned int salary = 8;
  Cleaner employee(id, name, position, salary);
  employee.setWorktime(50);
  employee.calc();
  EXPECT_EQ(400, employee.getPayment());
}

TEST(StaffDemoTest, test6) {
  unsigned int id = 2018;
  std::string name = "Jamie Colon";
  POSITION position = DRIVER;
  unsigned int salary = 10;
  Driver employee(id, name, position, salary);
  employee.setWorktime(50);
  employee.calc();
  EXPECT_EQ(200, employee.calcBonus());
}

TEST(StaffDemoTest, test7) {
  unsigned int id = 2018;
  std::string name = "Jamie Colon";
  POSITION position = DRIVER;
  unsigned int salary = 10;
  Driver employee(id, name, position, salary);
  employee.setWorktime(50);
  employee.calc();
  EXPECT_EQ(50 * 10 + (50 - 40) * 2 * 10, employee.getPayment());
}

TEST(StaffDemoTest, test8) {
  unsigned int id = 2017;
  std::string name = "Greg Lynch";
  POSITION position = DRIVER;
  unsigned int salary = 8;
  Driver employee(id, name, position, salary);
  employee.setWorktime(35);
  employee.calc();
  EXPECT_EQ(0, employee.calcBonus());
}

TEST(StaffDemoTest, test9) {
  Project* project = new Project(1, 100);
  unsigned int id = 2016;
  std::string name = "Michael Lowe";
  POSITION position = PROGRAMMER;
  unsigned int salary = 20;
  Programmer employee(id, name, position, salary, project);
  EXPECT_EQ(project, employee.getProject());
}

TEST(StaffDemoTest, test10) {
  std::vector <Project*> projects;
  for (int i = 1; i <= 4; i++) {
    Project* project = new Project(i, i * 100);
    projects.push_back(project);
  }
  unsigned int id = 2015;
  std::string name = "Francis Stevens";
  POSITION position = SENIORMANAGER;
  SeniorManager employee(id, name, position, projects);
  EXPECT_EQ(projects, employee.getProjects());
}

TEST(StaffDemoTest, test11) {
  Project* project = new Project(1, 100);
  project->testers = 2;
  project->programmers = 5;
  unsigned int id = 2014;
  std::string name = "Frank Sanders";
  POSITION position = TEAMLEADER;
  unsigned int salary = 20;
  TeamLeader employee(id, name, position, salary, project);
  EXPECT_EQ((2 + 5) * 5, employee.calcHeads());
}

TEST(StaffDemoTest, test12) {
  Project* project = new Project(1, 100);
  unsigned int id = 2013;
  std::string name = "Charles Smith";
  POSITION position = TESTER;
  unsigned int salary = 20;
  Tester employee(id, name, position, salary, project);
  EXPECT_EQ(20, employee.calcBudgetPart(0.2, 100));
}

TEST(StaffDemoTest, test13) {
  std::vector <Project*> projects;
  for (int i = 1; i <= 4; i++) {
    Project* project = new Project(i, i * 100);
    projects.push_back(project);
  }
  unsigned int id = 2012;
  std::string name = "Mark Bryant";
  POSITION position = SENIORMANAGER;
  SeniorManager employee(id, name, position, projects);
  EXPECT_EQ(SENIORMANAGER, employee.getPosition());
}

TEST(StaffDemoTest, test14) {
  std::vector <Project*> projects;
  Project* project = new Project(4, 400);
  projects.push_back(project);
  unsigned int id = 2011;
  std::string name = "Robert Hayes";
  POSITION position = PROJECTMANAGER;
  ProjectManager employee(id, name, position, projects);
  EXPECT_EQ(PROJECTMANAGER, employee.getPosition());
}

TEST(StaffDemoTest, test15) {
  std::vector <Project*> projects;
  Project* project = new Project(3, 300);
  projects.push_back(project);
  unsigned int id = 2011;
  std::string name = "Robert Hayes";
  POSITION position = PROJECTMANAGER;
  ProjectManager employee(id, name, position, projects);
  employee.setWorktime(50);
  EXPECT_EQ(50, employee.getWorktime());
}

TEST(StaffDemoTest, test16) {
  Project* project = new Project(1, 100);
  unsigned int id = 2013;
  std::string name = "Sergio Rodriguez";
  POSITION position = TESTER;
  unsigned int salary = 20;
  Tester employee(id, name, position, salary, project);
  employee.setWorktime(45);
  EXPECT_EQ(20 * 45, employee.calcBase(salary, employee.getWorktime()));
}

TEST(StaffDemoTest, test17) {
  Project* project = new Project(10, 1000);
  project->programmers = 1;
  unsigned int id = 2013;
  std::string name = "Kevin Walsh";
  POSITION position = PROGRAMMER;
  unsigned int salary = 20;
  Programmer employee(id, name, position, salary, project);
  employee.setWorktime(45);
  unsigned int result =
  static_cast<unsigned int> (project->budget * (45 - 40) * 0.002);
  EXPECT_EQ(result, employee.calcProAdditions());
}

TEST(StaffDemoTest, test18) {
  Project* project = new Project(5, 5000);
  project->testers = 1;
  unsigned int id = 2012;
  std::string name = "Daniel Fuller";
  POSITION position = TESTER;
  unsigned int salary = 15;
  Tester employee(id, name, position, salary, project);
  employee.setWorktime(45);
  unsigned int result = static_cast<unsigned int> (project->budget * 0.005);
  EXPECT_EQ(result, employee.calcProAdditions());
}
