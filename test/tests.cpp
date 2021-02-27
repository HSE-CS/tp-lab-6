// Copyright 2020 Elise

#include <gtest/gtest.h>
#include <string>

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

TEST(Test, Test_1) {
  Driver* pers4 = new Driver(2, "Danil", "Driver", 500, 6);
  EXPECT_EQ(2, pers4->get_id());
}

TEST(Test, Test_2) {
  Driver* pers4 = new Driver(2, "Danil", "Driver", 500, 6);
  EXPECT_EQ("Danil", pers4->get_name());
}

TEST(Test, Test_3) {
  Driver* pers4 = new Driver(2, "Danil", "Driver", 500, 6);
  EXPECT_EQ("Driver", pers4->get_position());
}

TEST(Test, Test_4) {
  Driver* pers4 = new Driver(2, "Danil", "Driver", 500, 6);
  EXPECT_EQ(500, pers4->get_salary());
}

TEST(Test, Test_5) {
  Driver* pers4 = new Driver(2, "Danil", "Driver", 500, 6);
  std::cout << pers4->calcBonus() << '\n';
  std::cout << pers4->calc() << '\n';
  EXPECT_EQ(6, pers4->get_worktime());
}

TEST(Test, Test_6) {
  Driver* pers4 = new Driver(2, "Danil", "Driver", 500, 6);
  EXPECT_EQ(2, pers4->calcBonus());
}

TEST(Test, Test_7) {
  Driver* pers4 = new Driver(2, "Danil", "Driver", 500, 6);
  EXPECT_EQ(3002, pers4->calc());
}

TEST(Test, Test_8) {
  Project num1 = {50, "rabota1", 33444};
  EXPECT_EQ("rabota1", num1.name);
}


TEST(Test, Test_9) {
  Project num1 = {50, "rabota1", 33444};
  EXPECT_EQ(50, num1.id);
}


TEST(Test, Test_10) {
  Project num1 = {50, "rabota1", 33444};
  EXPECT_EQ(33444, num1.budget);
}

TEST(Test, Test_11) {
  Tester* pers3 = new Tester(3, "Kadykov", "Tester", 1200, 10, &num1, 6);
  pers3->set_salary(1000);
  EXPECT_EQ(666, pers3->calcProAdditions());
}

TEST(Test, Test_12) {
  Project num1 = {50, "rabota1", 33444};
  Project num2 = {50, "rabota2", 93930};
  Project num3 = {50, "raabota3", 3334556};
  std::vector<Project*> projects;
  projects.push_back(&num2);
  projects.push_back(&num3);
  ProjectManager* manager = new ProjectManager(
      4, "Rokin Maks", "Project Manager", 2, 100000, 10, projects);
  EXPECT_EQ(1000, manager->calcHeads());
}

TEST(Test, Test_13) {
  Project num1 = {50, "rabota1", 33444};
  Project num2 = {50, "rabota2", 93930};
  Project num3 = {50, "raabota3", 3334556};
  std::vector<Project*> projects;
  projects.push_back(&num2);
  projects.push_back(&num3);
  ProjectManager* manager = new ProjectManager(
      4, "Rokin Maks", "Project Manager", 2, 100000, 10, projects);
  EXPECT_EQ(1000, manager->calcProAdditions());
}


TEST(Test, Test_14) {
  Project num1 = {50, "rabota1", 33444};
  Project num2 = {50, "rabota2", 93930};
  Project num3 = {50, "raabota3", 3334556};
  std::vector<Project*> projects;
  projects.push_back(&num2);
  projects.push_back(&num3);
  ProjectManager* manager = new ProjectManager(
      4, "Rokin Maks", "Project Manager", 2, 100000, 10, projects);
  EXPECT_EQ(1002000, manager->calc());
}


TEST(Test, Test_15) {
  Project num1 = {50, "rabota1", 33444};
  Project num2 = {50, "rabota2", 93930};
  Project num3 = {50, "raabota3", 3334556};
  std::vector<Project*> projects;
  projects.push_back(&num2);
  projects.push_back(&num3);
  ProjectManager* manager = new ProjectManager(
      4, "Rokin Maks", "Project Manager", 2, 100000, 10, projects);
  EXPECT_EQ(100000, manager->get_payment());
}
