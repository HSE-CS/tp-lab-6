// Copyright 2021 ArinaMonicheva

#include <gtest/gtest.h>
#include <string>
#include "Engineer.h"

TEST(tester, test1) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);

  EXPECT_DOUBLE_EQ(0.0, newTester.getWorkTime());
}

TEST(tester, test2) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);
  newTester.updateWorkTime(30.0);

  EXPECT_DOUBLE_EQ(30.0, newTester.getWorkTime());
}

TEST(tester, test3) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);
  newTester.updateWorkTime(30.0);
  newTester.updateWorkTime(30.0);

  EXPECT_DOUBLE_EQ(60.0, newTester.getWorkTime());
}

TEST(tester, test4) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);

  EXPECT_EQ("Arina Monicheva", newTester.getName());
}

TEST(tester, test5) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);

  EXPECT_EQ("Tester", newTester.getPosition());
}

TEST(tester, test6) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);

  EXPECT_EQ(5377, newTester.getId());
}

TEST(tester, test7) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);

  EXPECT_DOUBLE_EQ(5000.5, newTester.getPayment());
}

TEST(cleaner, test8) {
  std::string name = "Arina Monicheva", pos = "Cleaner";

  Cleaner newCleaner(5377, name, pos, 500.5);

  EXPECT_DOUBLE_EQ(0.0, newCleaner.calc());
}

TEST(cleaner, test9) {
  std::string name = "Arina Monicheva", pos = "Cleaner";

  Cleaner newCleaner(5377, name, pos, 500.5);
  newCleaner.updateWorkTime(30.0);

  EXPECT_DOUBLE_EQ(15015.0, newCleaner.calc());
}

TEST(cleaner, test10) {
  std::string name = "Arina Monicheva", pos = "Cleaner";

  Cleaner newCleaner(5377, name, pos, 500.5);
  newCleaner.updateWorkTime(30.0);

  EXPECT_DOUBLE_EQ(0.0, newCleaner.getSalary());
}

TEST(cleaner, test11) {
  std::string name = "Arina Monicheva", pos = "Cleaner";

  Cleaner newCleaner(5377, name, pos, 500.5);
  newCleaner.updateWorkTime(30.0);
  newCleaner.calc();

  EXPECT_DOUBLE_EQ(15015.0, newCleaner.getSalary());
}

TEST(driver, test12) {
  std::string name = "Arina Monicheva", pos = "Driver";

  Driver newDriver(5377, name, pos, 730.5);
  newDriver.updateWorkTime(48.0);

  EXPECT_DOUBLE_EQ(8766.0, newDriver.calcBonus());
}

TEST(tester, test13) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);

  EXPECT_DOUBLE_EQ(35436.5, newTester.getProject()->getBudget());
}

TEST(tester, test14) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);

  EXPECT_EQ(2526, newTester.getProject()->getId());
}

TEST(tester, test15) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);

  EXPECT_EQ(0, newTester.getProject()->getStaffNum());
}

TEST(tester, test16) {
  std::string name = "Arina Monicheva", pos = "Tester";
  Project* k = new Project(2526, 35436.5);

  Tester newTester(5377, name, pos, 5000.5, k);
  k->updateStaffNum();

  EXPECT_EQ(1, newTester.getProject()->getStaffNum());
}

TEST(projmanager, test17) {
  std::string name = "Arina Monicheva", pos = "Project Manager";
  Project* k = new Project(2526, 35000.5);
  k->updateStaffNum();
  k->updateStaffNum();
  k->updateStaffNum();
  std::vector <Project*> ks;
  ks.push_back(k);

  ProjectManager newManager(5377, name, pos, 7800.5, ks);
  k->updateStaffNum();  // manager joined to this project too

  EXPECT_DOUBLE_EQ(30000.0, newManager.calcHeads());
}

TEST(projmanager, test18) {
  std::string name = "Arina Monicheva", pos = "Project Manager";
  Project* k = new Project(2526, 35000.5);
  std::vector <Project*> ks;
  ks.push_back(k);

  ProjectManager newManager(5377, name, pos, 7800.5, ks);
  k->updateStaffNum();  // manager joined to this project too

  EXPECT_DOUBLE_EQ(8750.125, newManager.calc());
}

TEST(projmanager, test19) {
  std::string name = "Arina Monicheva", pos = "Project Manager";
  Project* k = new Project(2526, 35000.5);
  k->updateStaffNum();  // + programmer
  k->updateStaffNum();  // + tester
  k->updateStaffNum();  // + teamlead
  std::vector <Project*> ks;
  ks.push_back(k);

  ProjectManager newManager(5377, name, pos, 7800.5, ks);
  k->updateStaffNum();  // manager joined to this project too

  EXPECT_DOUBLE_EQ(38750.125, newManager.getCurrentBudget());
}

TEST(seniormanager, test20) {
  std::string name = "Arina Monicheva", pos = "Senior Manager";
  Project* k = new Project(2526, 35000.5);
  Project* k2 = new Project(2527, 38000.0);
  std::vector <Project*> ks;
  ks.push_back(k);
  ks.push_back(k2);

  SeniorManager newManager(5377, name, pos, 9800.5, ks);

  EXPECT_EQ(2, newManager.getNumOfProjects());
}

TEST(seniormanager, test21) {
  std::string name = "Arina Monicheva", pos = "Senior Manager";
  Project* k = new Project(2526, 35000.5);
  Project* k2 = new Project(2527, 38000.0);
  std::vector <Project*> ks;
  ks.push_back(k);

  SeniorManager newManager(5377, name, pos, 9800.5, ks);
  newManager.addNewProject(k2);

  EXPECT_EQ(2, newManager.getNumOfProjects());
}

TEST(seniormanager, test22) {
  std::string name = "Arina Monicheva", pos = "Senior Manager";
  Project* k = new Project(2526, 35000.5);
  Project* k2 = new Project(2527, 38000.0);
  k->updateStaffNum();  // + programmer
  k->updateStaffNum();  // + tester
  k2->updateStaffNum();  // + teamlead
  k2->updateStaffNum();  // + projmanager
  std::vector <Project*> ks;
  ks.push_back(k);
  ks.push_back(k2);

  SeniorManager newManager(5377, name, pos, 9800.5, ks);
  newManager.addNewProject(k2);  // would not be added - same id

  EXPECT_DOUBLE_EQ(40000.0, newManager.calcHeads());
}

TEST(seniormanager, test23) {
  std::string name = "Arina Monicheva", pos = "Senior Manager";
  Project* k = new Project(2526, 35000.5);
  Project* k2 = new Project(2527, 38000.0);
  std::vector <Project*> ks;
  ks.push_back(k);
  ks.push_back(k2);

  SeniorManager newManager(5377, name, pos, 9800.5, ks);
  newManager.addNewProject(k2);  // would not be added - same id

  EXPECT_DOUBLE_EQ(18250.125, newManager.calc());
}

TEST(seniormanager, test24) {
  std::string name = "Arina Monicheva", pos = "Senior Manager";
  Project* k = new Project(2526, 35000.5);
  Project* k2 = new Project(2527, 38000.0);
  std::vector <Project*> ks;
  k->updateStaffNum();  // + programmer
  k->updateStaffNum();  // + tester
  k2->updateStaffNum();  // + teamlead
  k2->updateStaffNum();  // + projmanager
  ks.push_back(k);
  ks.push_back(k2);

  SeniorManager newManager(5377, name, pos, 9800.5, ks);
  newManager.addNewProject(k2);  // would not be added - same id

  EXPECT_DOUBLE_EQ(58250.125, newManager.getCurrentBudget());
}

TEST(programmer, test25) {
  std::string name = "Arina Monicheva", pos = "Programmer";
  Project* k = new Project(2526, 35000.0);

  Programmer newProgrammer(5377, name, pos, 7000.5, k);
  newProgrammer.updateWorkTime(50.0);

  EXPECT_DOUBLE_EQ(7000.0, newProgrammer.calcProAdditions());
}

TEST(programmer, test26) {
  std::string name = "Arina Monicheva", pos = "Programmer";
  Project* k = new Project(2526, 35000.0);

  Programmer newProgrammer(5377, name, pos, 7000.5, k);
  newProgrammer.updateWorkTime(50.0);

  EXPECT_DOUBLE_EQ(358775.0, newProgrammer.calc());
}

TEST(teamlead, test27) {
  std::string name = "Arina Monicheva", pos = "Team Leader";
  Project* k = new Project(2526, 35000.0);
  k->updateStaffNum();  // + programmer
  k->updateStaffNum();  // + tester
  k->updateStaffNum();  // + projmanager

  TeamLeader newLead(5377, name, pos, 8500.5, k);
  k->updateStaffNum();  // + teamlead
  newLead.updateWorkTime(50.0);

  EXPECT_DOUBLE_EQ(2000.0, newLead.calcHeads());
}

TEST(teamlead, test28) {
  std::string name = "Arina Monicheva", pos = "Team Leader";
  Project* k = new Project(2526, 35000.0);
  k->updateStaffNum();  // + programmer
  k->updateStaffNum();  // + tester
  k->updateStaffNum();  // + projmanager

  TeamLeader newLead(5377, name, pos, 8500.5, k);
  k->updateStaffNum();  // + teamlead
  newLead.updateWorkTime(50.0);

  EXPECT_DOUBLE_EQ(430525.0, newLead.calc());
}
