// Copyright 2020 GHA Test Team
//
//#include <gtest/gtest.h>
//#include <string>
//#include <vector>
//#include "Personal.h"
//#include "Engineer.h"
//#include "Manager.h"
//#include "Project.h"
//
//TEST(test_cleaner, test1) {
//  Employee* employee = new Cleaner(0,
//    "alina wal", 8, 7000, 1);
//  std::string name = employee->getName();
//  EXPECT_EQ("alina wal", name);
//}
//TEST(test_cleaner, test2) {
//  Employee* employee = new Cleaner(0,
//    "alina wal", 8, 7000, 1);
//  int worktime = employee->getWorktime();
//  EXPECT_EQ(worktimw, 8);
//}
//TEST(test_cleaner, test3) {
//  Employee* employee = new Cleaner(0,
//    "alina wal", 8, 7000, 1);
//  employee->calc();
//  EXPECT_EQ(employee->getPay(), 5600);
//}
//TEST(test_driver, test4) {
//  Employee* employee = new Driver(0,
//    "anton", 8, 7000, 1);
//  std::string name = employee->getName();
//  EXPECT_EQ("anton", name);
//}
//TEST(test_driver, test5) {
//  Employee* employee = new Driver(0,
//    "anton", 8, 7000, 1);
//  employee->calc();
//  EXPECT_EQ(employee->getPay(), 91000);
//}
//TEST(test_programmer, test6) {
//  Employee* employee = new Programmer(0,
//    "anna", 8, 10000, 1, pr);
//  std::string name = employee->getName();
//  EXPECT_EQ("anna", name);
//}
//
//TEST(test_programmer, test7) {
//  Project* pr = new Project(1, "lala", 500, 2);
//  Employee* employee = new Programmer(0,
//    "anna", 8, 10000, 1, pr);
//  std::string name = employee->getName();
//  employee->calc();
//  EXPECT_EQ(employee->getPay(), 140250);
//}
//
//
//TEST(test_tester, test8) {
//  Project* pr = new Project(1, "lala", 500, 2);
//  Employee* employee = new Tester(0,
//    "rita", 8, 10000, 1, pr);
//  std::string name = employee->getName();
//  employee->calc();
//  EXPECT_EQ(employee->getPay(), 150400);
//}
//TEST(test_tester, test9) {
//  Employee* employee = new Tester(0,
//    "rita", 8, 10000, 1, nullptr);
//  std::string name = employee->getName();
//  EXPECT_EQ("rita", name);
//}
//
//TEST(test_manager, test10) {
//  Project* pr = new Project(1, "lala", 2000, 5);
//  std::vector<Project*> projects;
//  projects.push_back(pr);
//  Employee* employee = new ProjectManager(0,
//    "anna", 8, 1, 10000, projects);
//  std::string name = employee->getName();
//  employee->calc();
//  EXPECT_EQ(employee->getPay(), 50400);
//}
//
//TEST(test_manager, test11) {
//  Project* pr = new Project(1, "lala", 2000, 5);
//  std::vector<Project*> projects;
//  Project* pr2 = new Project(2, "ssjs", 1000, 2);
//  projects.push_back(pr);
//  projects.push_back(pr2);
//  Project* pr3 = new Project(3, "ssjs", 6000, 3);
//  projects.push_back(pr3);
//  Employee* employee = new SeniorManager(0,
//    "anna", 8, 1, 10000, projects);
//  std::string name = employee->getName();
//  employee->calc();
//  EXPECT_EQ(employee->getPay(), 2900);
//}
//TEST(test_driver, test12) {
//  Employee* employee = new Driver(0,
//    "alina wal", 9, 7000, 1);
//  int worktime = employee->getWorktime();
//  EXPECT_EQ(worktimw, 9);
//}
//TEST(test_programmer, test13) {
//  Employee* employee = new Programmer(0,
//    "anna", 8, 10000, 1, nullptr);
//  std::string name = employee->getName();
//  employee->calc();
//  EXPECT_EQ(employee->getPay(), 140000);
//}
//
//TEST(test_projectMan, test14) {
//  Employee* employee = new Cleaner(0,
//    "Katerina Tyulin",
//    "cleaner",
//    150);
//  std::string rez = "Katerina Tyulin";
//  EXPECT_EQ(employee->getName(), rez);
//}
//
//TEST(test_projectMan, test15) {
//  Project* pr = new Project(1, "", 6000, 9);
//  std::vector<Project*> projects;
//  Project* pr2 = new Project(2, "", 1500, 2);
//  projects.push_back(pr);
//  projects.push_back(pr2);
//  Project* pr3 = new Project(3, "", 9000, 3);
//  projects.push_back(pr3);
//  Employee* employee = new SeniorManager(0,
//    "anna", 8, 1, 5000, projects);
//  std::string name = employee->getName();
//  employee->calc();
//  EXPECT_EQ(employee->getPay(), 4416);
//}