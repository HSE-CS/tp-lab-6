// Copyright 2021 Dumarevskya

#include <gtest/gtest.h>
#include <string>
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

std::string return_string(Position position) {
  if (position == PROGRAMMER) {
    return "Programmer";
  } else if (position == TESTER) {
    return "Tester";
  } else if (position == DRIVER) {
    return "Driver";
  } else if (position == CLEANER) {
    return "Cleaner";
  } else if (position == ENGINEER) {
    return "Engineer";
  } else if (position == SENIOR_MANAGER) {
    return "Senior Manager";
  } else if (position == PROJECT_MANAGER) {
    return "Project Manager";
  } else if (position == TEAM_LEADER) {
    return "Teamleader";
  }
}

TEST(Test, test1) {
  Cleaner* temp = new Cleaner("23", "tamara", 200.0, Position(CLEANER));
  EXPECT_EQ("23", temp->getId());
}

TEST(Test, test2) {
  Cleaner* temp = new Cleaner("23", "tamara", 200.0, Position(CLEANER));
  EXPECT_EQ("tamara", temp->getName());
}

TEST(Test, test3) {
  Cleaner* temp = new Cleaner("23", "tamara", 200.0, Position(CLEANER));
  EXPECT_EQ("Cleaner", return_string(temp->getPosition()));
}

TEST(Test, test4) {
  Cleaner* temp = new Cleaner("23", "tamara", 200.0, Position(CLEANER));
  EXPECT_EQ(0, temp->calcBonus());
}

TEST(Test, test5) {
  Project* pr = new Project("G4", 10000);
  Programmer* temp = new Programmer("23", "tamara",
    200.0, Position(CLEANER), pr);
  temp->setWorkTime(30);
  EXPECT_EQ(6000, temp->calcBase(200.0, 30));
}

TEST(Test, test6) {
  Project* pr = new Project("G4", 10000);
  Programmer* temp = new Programmer("23", "tamara",
    200.0, Position(CLEANER), pr);
  temp->setWorkTime(30);
  EXPECT_EQ(1000, temp->calcBonus());
}

TEST(Test, test7) {
  Project* pr = new Project("G4", 10000);
  Programmer* temp = new Programmer("23", "tamara",
    200.0, Position(CLEANER), pr);
  temp->setWorkTime(30);
  EXPECT_EQ(1000, temp->calcProAdditions());
}

TEST(Test, test8) {
  Project* pr = new Project("G4", 10000);
  Programmer* temp = new Programmer("23", "tamara",
    200.0, Position(CLEANER), pr);
  temp->setWorkTime(30);
  temp->calc();
  EXPECT_EQ(11000, temp->getPayment());
}

TEST(Test, test9) {
  Cleaner* temp = new Cleaner("23", "tamara",
    200.0, Position(CLEANER));
  temp->setWorkTime(20);
  EXPECT_EQ(4000, temp->getPayment());
}

TEST(Test, test10) {
  Driver* temp = new Driver("23", "tamara", 200.0, Position(CLEANER));
  temp->setWorkTime(20);
  EXPECT_EQ(4300, temp->getPayment());
}

TEST(Test, test11) {
  Project* pr = new Project("G4", 10000);
  TeamLeader* temp = new TeamLeader("23", "tamara",
    200.0, Position(CLEANER), pr);
  temp->setWorkTime(30);
  temp->calc();
  EXPECT_EQ(13500, temp->getPayment());
}
