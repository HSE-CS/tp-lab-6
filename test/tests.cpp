// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Interfaces.h"

TEST(Test, test_1) {
     std::string name = "Ivan";
     Cleaner test(0, name, 8, 2, 500);
     EXPECT_EQ(0, test.getId());
 }

 TEST(Test, test_2) {
     std::string name = "Ivan";
     Cleaner test(10, name, 8, 2, 500);
     EXPECT_EQ(10, test.getId());
 }

 TEST(Test, test_3) {
     std::string name = "Ivan";
     Cleaner test(225, name, 8, 2, 500);
     EXPECT_EQ(225, test.getId());
 }

 TEST(Test, test_4) {
     std::string name = "Ivan";
     Cleaner test(0, name, 8, 2, 500);
     EXPECT_EQ(name, test.getName());
 }

 TEST(Test, test_5) {
     std::string name = "Ivan";
     Cleaner test(0, name, 8, 2, 500);
     EXPECT_EQ(8, test.getWorktime());
 }

  TEST(Test, test_6) {
     std::string name = "Ivan";
     Cleaner test(0, name, 8, 2, 500);
     EXPECT_EQ(500, test.getPayment());
 }

  TEST(Test, test_7) {
     std::string name = "Ivan";
     Cleaner test(0, name, 8, 2, 500);
     EXPECT_EQ("CLEANER", test.getPosition());
 }

   TEST(Test, test_8) {
     std::string name = "Ivan";
     Driver test(0, name, 8, 2, 500);
     EXPECT_EQ("DRIVER", test.getPosition());
 }

 TEST(ProjectTest, test_9) {
     Project test(15, 1000000);
     EXPECT_EQ(15, test.getId());
 }

  TEST(ProjectTest, test_10) {
     Project test(15, 1000000);
     EXPECT_EQ(1000000, test.getBudget());
 }


 TEST(ProjectTest, test_11) {
     std::string name = "Ivan";
     Project testP();
     Programmer test(11, name, 8, &proj, 100000, 0,5);
     EXPECT_EQ(0,5, test.getPart());
 }

  TEST(ProjectTest, test_12) {
     std::string name = "Ivan";
     Project testP();
     Programmer test(11, name, 8, &proj, 100000, 0,5);
     EXPECT_EQ(0, proj.getProjectId());
 }

 TEST(ProjectTest, test_12) {
     std::string name = "Ivan";
     Driver test(11, name, 8, 5);
     EXPECT_EQ(40, test.calcBase());
 }

  TEST(ProjectTest, test_13) {
     std::string name = "Ivan";
     Driver test(11, name, 0, 1000);
     EXPECT_EQ(0, test.calcBase());
 }
