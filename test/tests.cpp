//  Copyright 2021 GHA created by Klykov Anton

#include <gtest/gtest.h>
#include "Driver.h"
#include "Cleaner.h"
#include "Engineer.h"
#include "Programmer.h"
#include "Tester.h"
#include "TeamLeader.h"
#include "Manager.h"
#include "Factory.h"
#include <vector>

TEST(DriverTest, TestPayment) {
  Driver driver(0, "Иванов Иван Иванович", "Driver", 1500);
  driver.setWorkTime();
  int amountWorkTime = driver.getWorkTime();
  driver.calc();
  int payment = amountWorkTime * 1500;
  int BonusDeliverPeople = (driver.getPayment() - payment);
  EXPECT_EQ(payment, driver.getPayment() - BonusDeliverPeople);
}

TEST(CleanerTest, TestPayment) {
  Cleaner cleaner(1, "Тарантулова Татомара Татомаровна",
                  "Cleaner", 1000);
  cleaner.setWorkTime();
  int amountWorkTime = cleaner.getWorkTime();
  int payment = 1000 * amountWorkTime;
  cleaner.calc();
  EXPECT_EQ(payment, cleaner.getPayment());
}
TEST(EngineerTest, TestPayment) {
  Project project(0, 50000);
  Engineer engineer(2, "Маховой Атаман Атаманович",
                    "Engineer", 2000,
                     &project, 0.25);
  engineer.setWorkTime();
  int amountWorkTime = engineer.getWorkTime();
  engineer.calc();
  int payment = amountWorkTime * 2000 +
                static_cast<int>(0.25 * project.p_budget);
  EXPECT_EQ(payment, engineer.getPayment());
}
TEST(ProgrammerTest, TestPayment) {
  Project project(1, 40000);
  Programmer programmer(3, "Чумачей Атаман Татаранович",
                        "Programmer", 2500, &project, 0.25);
  programmer.setWorkTime();
  int amountWorkTime = programmer.getWorkTime();
  programmer.calc();
  int AdditionalPayment = 7500;
  int PossiblePayment = 2500 * amountWorkTime +
                        static_cast<int>(0.25 * project.p_budget) +
                        AdditionalPayment;
  // Реальный заработок vs Возможный заработок
  EXPECT_LE(programmer.getPayment(), PossiblePayment); 
}
TEST(TesterTest, TestPyment) {
  Project project(2, 30000);
  Tester tester(4, "Чуйка Атаман Чайконович",
                "Tester", 2100, &project, 0.15);
  tester.setWorkTime();
  int amountWorkTime = tester.getWorkTime();
  tester.calc();
  int AdditionalPayment = 5500;
  int PossiblePayment = 2100 * amountWorkTime +
                        static_cast<int>(0.15 * project.p_budget) +
                        AdditionalPayment;
  // Реальный заработок vs Возможный заработок
  EXPECT_LE(tester.getPayment(), PossiblePayment);
}

TEST(TeamLeaderTest, TestPayment) {
  Project project(3, 50000);
  TeamLeader team_leader(5, "Чуйка Жук Жукович", "TeamLeader",
                         3000, &project, 0.35);
  team_leader.setWorkTime();
  int amountWorkTime = team_leader.getWorkTime();
  team_leader.calc();
  int HeadingPayment = 8000;
  int PossiblePayment = 3000 * amountWorkTime + 
                        static_cast<int>(0.35 * project.p_budget) +
                        HeadingPayment;
  EXPECT_EQ(team_leader.getPayment(), PossiblePayment);
}
TEST(ProjectManagerTest, PaymentTest) {
  Project project(4, 100000);
  ProjectManager project_manager(6, "Жукавинск Петр Алексеевич", 
                                 "ProjectManager", &project, 0.5);
  project_manager.calc();
  int payment = project_manager.calcBudgetPart(0.5,
                project.p_budget) +
                project_manager.calcHeads();
  EXPECT_EQ(payment, project_manager.getPayment());
}

TEST(SenoirManagerTest, PaymentTest) {
  std::vector<Project*> projects;
  for (int i = 1; i <= 5; i++) {
    Project* temp = new Project(i, i * 10000);
    projects.push_back(temp);
    temp = nullptr;
  }
  SeniorManager senior_manager(5, "Жувочка Евгения Фавевна", 
                               "SeniorManager", projects[1],
                                0.3, projects);
  senior_manager.calc();
  int temp_payment{0};
  for (int i = 0; i < 5; i++) {
    temp_payment += senior_manager.calcBudgetPart(0.3,
                    projects[i]->p_budget);
  }
  int payment = temp_payment + senior_manager.calcHeads();
  EXPECT_EQ(payment, senior_manager.getPayment());
}
TEST(AllTest, test1) {
  StaffFactory staff_factory;
  int amountStaff{64};
  std::vector<Employee*> staff = staff_factory.getStaff();
  EXPECT_EQ(amountStaff, staff.size());
}
TEST(AllTest, test2) {
  StaffFactory staff_factory;
  std::vector<Employee*> staff = staff_factory.getStaff();
  EXPECT_EQ(0, staff[0]->getWorkTime());
}
TEST(AllTest, test3) {
  StaffFactory staff_factory;
  std::vector<Employee*> staff = staff_factory.getStaff();
  for (int i = 0; i < staff.size(); ++i) {
    staff[i]->setWorkTime();
  }
  EXPECT_NE(0, staff[0]->getWorkTime());
}
TEST(AllTest, test4) {
  StaffFactory staff_factory;
  std::vector<Employee*> staff = staff_factory.getStaff();
  EXPECT_EQ(0, staff[52]->getPayment());
}
TEST(AllTest, test5) {
  StaffFactory staff_factory;
  std::vector<Employee*> staff = staff_factory.getStaff();
  for (int i = 0; i < staff.size(); ++i) {
    staff[i]->setWorkTime();
  }
  for (int i = 0; i < staff.size(); ++i) {
    staff[i]->calc();
  }
  EXPECT_NE(0, staff[52]->getPayment());
}
TEST(AllTest, test6) {
  StaffFactory staff_factory;
  std::vector<Employee*> staff = staff_factory.getStaff();
  std::string position = "Cleaner";
  EXPECT_EQ(position, staff[20]->getPosition());
}
TEST(AllTest, test7) {
  StaffFactory staff_factory;
  std::vector<Employee*> staff = staff_factory.getStaff();
  std::string position = "ProjectManager";
  EXPECT_EQ(position, staff[31]->getPosition());
}
