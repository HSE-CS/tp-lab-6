// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

TEST(TestStaff, Test1) {
  Project* pr = new Project{ 12214, 100000 };
  Engineer* emp = new Engineer(1,
    "Lukyanov Michail Igorevich", "tester", 40, 500, pr);
  EXPECT_EQ(pr, emp->getProject());
}

TEST(TestStaff, Test2) {
  Project* pr = new Project{ 12214, 100000 };
  Employee* emp = new Engineer(1,
    "Lukyanov Michail Igorevich", "tester", 40, 500, pr);
  EXPECT_EQ("tester", emp->getPosition());
}

TEST(TestStaff, Test3) {
  Project* pr = new Project{ 12214, 100000 };
  Employee* emp = new Engineer(1,
    "Lukyanov Michail Igorevich", "tester", 40, 500, pr);
  EXPECT_EQ("Lukyanov Michail Igorevich", emp->getName());
}

TEST(TestStaff, Test4) {
  Project* pr = new Project{ 12214, 100000 };
  Employee* emp = new Engineer(1,
    "Lukyanov Michail Igorevich", "tester", 40, 500, pr);
  EXPECT_EQ(1, emp->getId());
}

TEST(TestStaff, Test5) {
  Project* pr = new Project{ 12214, 100000 };
  Employee* emp = new Engineer(1,
    "Lukyanov Michail Igorevich", "tester", 40, 500, pr);
  EXPECT_EQ(40, emp->getWorkTime());
}

TEST(TestStaff, Test6) {
  Project* pr = new Project{ 12214, 100000 };
  Employee* emp = new Engineer(1,
    "Lukyanov Michail Igorevich", "tester", 40, 500, pr);
  EXPECT_EQ(500, emp->getPayment());
}

TEST(TestStaff, Test7) {
  Project* pr = new Project{ 12214, 100000 };
  Employee* emp = new Engineer(1,
    "Lukyanov Michail Igorevich", "tester", 40, 500, pr);
  EXPECT_EQ(0, emp->calc());
}

TEST(TestStaff, Test8) {
  Cleaner* emp = new Cleaner(1,
    "Lukyanov Michail Igorevich", "cleaner", 40, 500);
  EXPECT_EQ(20000, emp->calc());
}

TEST(TestStaff, Test9) {
  Project* pr = new Project{ 12214, 100000 };
  Driver* emp = new Driver(1,
    "Lukyanov Michail Igorevich", "driver", 40, 500);
  EXPECT_EQ(20000, emp->calc());
}
TEST(TestStaff, Test10) {
  Project* pr = new Project{ 12214, 100000 };
  Programmer* emp = new Programmer(1,
    "Lukyanov Michail Igorevich", "driver", 40, 500, pr);
  EXPECT_EQ(0, emp->calcProAdditions());
}

TEST(TestStaff, Test11) {
  Cleaner* emp = new Cleaner(1,
    "Lukyanov Michail Igorevich", "cleaner", 40, 500);
  emp->setWorkTime(45);
  EXPECT_EQ(22500, emp->calc());
}

TEST(TestStaff, Test12) {
  Cleaner* emp = new Cleaner(1,
    "Lukyanov Michail Igorevich", "cleaner", 40, 500);
  emp->setWorkTime(45);
  EXPECT_EQ("Lukyanov Michail Igorevich", emp->getName());
}



