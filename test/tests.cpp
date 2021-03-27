// Copyright 2021 by Liza
#include <gtest/gtest.h>
#include <string>
#include"Factory.h"


TEST(Worktest, test1) {
std::vector<Employee*> staff = makeStaff("src/StaffList.txt", "src/ProjectsList.txt");
EXPECT_EQ(15, staff.size());}
TEST(Worktest, test2) {
Driver d(12, "Stepan", "Driver", 250);
d.setWorkTime(11);
EXPECT_EQ(d.calc(), 2700);}
TEST(Worktest, test3) {
Project p = Project(7, 2100000), p2 = Project(12, 1000000);
std::vector<Project> P{ p, p2 };
SeniorManager SM(1, "Liza", "SeniorManager", 400, P);
SM.calc();
EXPECT_EQ(SM.getsalary(), 1085000);}
TEST(Worktest, test4) {
Driver d(11, "Polina", "Tester", 300);
d.setWorkTime(20);
EXPECT_EQ(d.calcBase(), 6000);}
TEST(Worktest, test5) {
Driver d(4, "Mark", "Programmer", 350);
d.setWorkTime(15);
EXPECT_EQ(d.calcBase(), 5250);}
TEST(Worktest, test6) {
Project p(7, 2100000);
Tester c(4, "Mark", "Programmer", 400, p);
c.setWorkTime(80);
c.calc();
EXPECT_EQ(c.getsalary(), 347000);}
TEST(Worktest, test7) {
Project p(7, 2100000);
Tester c(4, "Mark", "Programmer", 400, p);
c.setWorkTime(80);
c.calc();
EXPECT_EQ(c.getworktime(), 80);}
TEST(Worktest, test8) {
Cleaner c(9, "Kolya", "Tester", 300);
c.setWorkTime(11);
c.calc();
EXPECT_EQ(c.getworktime(), 11);}
TEST(Worktest, test9) {
Cleaner c(13, "Karina", "Driver", 250);
c.setWorkTime(20);
c.calc();
EXPECT_EQ(c.getsalary(), 5000);}
TEST(Worktest, test10) {
Project p(111, 100);
EXPECT_EQ(100, p.getBudget());}
TEST(Worktest, test11) {
Project p(178, 100);
EXPECT_EQ(178, p.getId());}
TEST(Worktest, test12) {
Driver d(15, "Oleg", "SeniorManager", 200);
d.calc();
EXPECT_EQ(d.getname(), "Oleg");}
TEST(Worktest, test13) {
Cleaner c(2, "Max", "ProjectManager", 300);
c.calc();
EXPECT_EQ(c.getposition(), "ProjectManager");}
TEST(Worktest, test14) {
std::vector<Employee *> staff = makeStaff("", "");
EXPECT_EQ(0, staff.size());}
TEST(Worktest, test15) {
Driver d(12, "Stepan", "Driver", 250);
d.setWorkTime(15);
d.setnight(5, 300);
EXPECT_EQ(d.calc(), 5250);}
