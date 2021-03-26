// Copyright 2020 Uskova

#include <gtest/gtest.h>
#include <string>
#include "Personal.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Project.h"


TEST(Tests, Test1) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  Tester* emp =
      new Tester(687755, "April Nelson", Position::Tester, 40, 400, 0, pr1);
  EXPECT_EQ(687755, emp->getId());
}

TEST(Tests, Test2) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  Tester* emp =
      new Tester(687755, "April Nelson", Position::Tester, 40, 400, 0, pr1);
  EXPECT_EQ("April Nelson", emp->getName());
}

TEST(Tests, Test3) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  Tester* emp =
      new Tester(687755, "April Nelson", Position::Tester, 40, 400, 0, pr1);
  EXPECT_EQ(Position::Tester, emp->getPosition());
}

TEST(Tests, Test4) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  Tester* emp =
      new Tester(687755, "April Nelson", Position::Tester, 40, 400, 0, pr1);
  EXPECT_EQ(160, emp->getWorktime());
}

TEST(Tests, Test5) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  Tester* emp =
      new Tester(687755, "April Nelson", Position::Tester, 40, 400, 0, pr1);
  EXPECT_EQ(pr1, emp->getProject());
}

TEST(Tests, Test6) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  std::vector<Employee*> workers = readWorkers("file.txt", pr1);
  for (int i = 0; i < workers.size(); i++) {
    if (workers[i]->getPosition() == Position::ProjectManager ||
        workers[i]->getPosition() == Position::SeniorManager ||
        workers[i]->getPosition() == Position::Programmer ||
        workers[i]->getPosition() == Position::Tester ||
        workers[i]->getPosition() == Position::TeamLeader) {
      pr1->addWorker();
    }
  }
  ProjectManager* emp = static_cast<ProjectManager*>(workers[7]);
  emp->calc();
  EXPECT_EQ(345000, emp->getPayment());
}


TEST(Tests, Test7) {
  Cleaner* emp =
      new Cleaner(214563, "Steve Tate", Position::Cleaner, 40, 200);
  emp->calc();
  EXPECT_EQ(32000, emp->getPayment());
}

TEST(Tests, Test8) {
  Driver* emp =
      new Driver(961245, "Adam Wadeh", Position::Driver, 34, 250, 5);
  EXPECT_EQ(5, emp->getExtraTime());
}
TEST(Tests, Test9) {
  Project* pr = new Project{656912, "SecretBox", 500000};
  Programmer* emp =
      new Programmer(894515, "Anita West", Position::Programmer,
          40, 400, 1, pr);
  EXPECT_EQ(6000, emp->calcProAdditions());
}

TEST(Tests, Test10) {
  Cleaner* emp =
      new Cleaner(476528, "Vera Hernandez", Position::Cleaner, 38, 200);
  emp->setWorkTime(180);
  emp->calc();
  EXPECT_EQ(36000, emp->getPayment());
}

TEST(Tests, Test11) {
  Cleaner* emp =
      new Cleaner(778544, "Mildred Jacob", Position::Cleaner, 35, 200);
  EXPECT_EQ("Mildred Jacob", emp->getName());
}


TEST(Tests, Test12) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  std::vector<Employee*> workers = readWorkers("file.txt", pr1);
  for (int i = 0; i < workers.size(); i++) {
    if (workers[i]->getPosition() == Position::ProjectManager ||
        workers[i]->getPosition() == Position::SeniorManager ||
        workers[i]->getPosition() == Position::Programmer ||
        workers[i]->getPosition() == Position::Tester ||
        workers[i]->getPosition() == Position::TeamLeader) {
      pr1->addWorker();
    }
  }
  ProjectManager* emp = static_cast<ProjectManager*>(workers[7]);
  EXPECT_EQ("Lester Howard", emp->getName());
}

TEST(Tests, Test13) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  std::vector<Employee*> workers = readWorkers("file.txt", pr1);
  for (int i = 0; i < workers.size(); i++) {
    if (workers[i]->getPosition() == Position::ProjectManager ||
        workers[i]->getPosition() == Position::SeniorManager ||
        workers[i]->getPosition() == Position::Programmer ||
        workers[i]->getPosition() == Position::Tester ||
        workers[i]->getPosition() == Position::TeamLeader) {
      pr1->addWorker();
    }
  }
  SeniorManager* emp = static_cast<SeniorManager*>(workers[15]);
  emp->calc();
  EXPECT_EQ(43527, emp->getPayment());
}

TEST(Tests, Test14) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  std::vector<Employee*> workers = readWorkers("file.txt", pr1);
  for (int i = 0; i < workers.size(); i++) {
    if (workers[i]->getPosition() == Position::ProjectManager ||
        workers[i]->getPosition() == Position::SeniorManager ||
        workers[i]->getPosition() == Position::Programmer ||
        workers[i]->getPosition() == Position::Tester ||
        workers[i]->getPosition() == Position::TeamLeader) {
      pr1->addWorker();
    }
  }
  SeniorManager* emp = static_cast<SeniorManager*>(workers[9]);
  EXPECT_EQ(111, emp->calcWorkers());
}

TEST(Tests, Test15) {
  Project* pr1 = new Project(656912, "SecretBox", 500000);
  std::vector<Employee*> workers = readWorkers("file.txt", pr1);
  for (int i = 0; i < workers.size(); i++) {
    if (workers[i]->getPosition() == Position::ProjectManager ||
        workers[i]->getPosition() == Position::SeniorManager ||
        workers[i]->getPosition() == Position::Programmer ||
        workers[i]->getPosition() == Position::Tester ||
        workers[i]->getPosition() == Position::TeamLeader) {
      pr1->addWorker();
    }
  }
  for (int i = 0; i < workers.size(); i++) {
    workers[i]->calc();
  }
  Project* pr2 = new Project(656925, "MyPhone", 700000);
  for (int i = 0; i < workers.size(); i++) {
    if ((workers[i]->getPosition() == Position::ProjectManager ||
         workers[i]->getPosition() == Position::SeniorManager ||
         workers[i]->getPosition() == Position::Programmer ||
         workers[i]->getPosition() == Position::Tester ||
         workers[i]->getPosition() == Position::TeamLeader) &&
        (i % 2 == 0)) {
      pr2->addWorker();
      workers[i] = apdate(workers[i], pr2);
    }
  }
  for (int i = 0; i < workers.size(); i++) {
    workers[i]->calc();
  }
  ProjectManager* emp = static_cast<ProjectManager*>(workers[8]);
  EXPECT_EQ(pr2, emp->getProject());
}
