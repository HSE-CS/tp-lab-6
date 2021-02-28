// Copyright DBarinov

#include <gtest/gtest.h>
#include <string>
#include"Factory.h"

TEST(StaffDemo, test1) {
  Factory F;
  std::vector<Employee*> staff = F.makeStaff("src/Personals.txt");
  EXPECT_EQ(15, staff.size());
}
  TEST(StaffDemo, test2) {
  Driver d(11, "StepanFomin", Position::Driver, 250, 20);
  d.calc();
  EXPECT_EQ(d.getPayment(), 100*20 + 250*d.getWorkTime());
}
TEST(StaffDemo, test3) {
  Project *p = new Project(7, 2100000), *p2 = new Project(12, 1000000);
  std::vector<Project *> P{p, p2};
  SeniorManager SM(1, "KiraPriti", Position::SeniorManager, 0.25, 13, P);
  SM.calc();
  EXPECT_EQ(SM.getPayment(), (2100000 + 1000000) * 0.25 + 13 * 2500);
}
TEST(StaffDemo, test4) {
  Project *p = new Project(7, 2100000);
  std::vector<Project *> P{p};
  ProjectManager PM(3, "AlexSpirin", Position::ProjectManager, 0.3, 4, P);
  PM.calc();
  EXPECT_EQ(PM.getPayment(), 2100000 * 0.3 + 4 * 2500);
}
TEST(StaffDemo, test5) {
  Project *p = new Project(7, 2100000);
  Programmer P(4, "MarkTsuk", Position::Programmer, 2500, 0.05, 10, p);
  P.calc();
  EXPECT_EQ(P.getPayment(),
            1000 * 10 + 0.05 * 2100000 + 2500 * P.getWorkTime());
}
TEST(StaffDemo, test6) {
  Project *p = new Project(7, 2100000);
  Tester T(4, "MarkTsuk", Position::Tester, 2000, 0.05, 30, p);
  T.calc();
  EXPECT_EQ(T.getPayment(), 700 * 30 + 0.05 * 2100000 + 2000 * T.getWorkTime());
}
TEST(StaffDemo, test7) {
  Project *p = new Project(7, 2100000);
  TeamLeader TL(5, "NikDemoShow", Position::TeamLeader, 3700, 0.35, 25, 3, p);
  TL.calc();
  EXPECT_EQ(TL.getPayment(),
            3 * 2500 + 1000 * 25 + 0.35 * 2100000 + 3700 * TL.getWorkTime());
}
TEST(StaffDemo, test8) {
  Project *p = new Project(7, 2100000);
  TeamLeader TL(5, "NikDemoShow", Position::TeamLeader, 3700, 0.35, 25, 3, p);
  TL.calc();
  EXPECT_EQ(TL.getPayment(),
            3 * 2500 + 1000 * 25 + 0.35 * 2100000 + 3700 * TL.getWorkTime());
}
TEST(StaffDemo, test9) {
  Cleaner c(13, "OlgaPrivolina", Position::Cleaner, 200);
  c.calc();
  EXPECT_EQ(c.getPayment(), 200 * c.getWorkTime());
}
TEST(StaffDemo, test10) {
  Project p(777, 100);
  EXPECT_EQ(100, p.getBudget());
}
TEST(StaffDemo, test11) {
  Project p(777, 100);
  EXPECT_EQ(100, p.getBudget());
}
TEST(StaffDemo, test12) {
  Driver d(11, "StepanFomin", Position::Driver, 250, 20);
  d.calc();
  EXPECT_EQ(d.getName(), "StepanFomin");
}
TEST(StaffDemo, test13) {
  Cleaner c(13, "OlgaPrivolina", Position::Cleaner, 200);
  c.calc();
  EXPECT_EQ(c.getPos(), Position::Cleaner);
}
TEST(StaffDemo, test14) {
  Factory F;
  std::vector<Employee *> staff = F.makeStaff("");
  EXPECT_EQ(0, staff.size());
}
TEST(StaffDemo, test15) {
  Project p(777, 100);
  EXPECT_EQ(777, p.getId());
}
