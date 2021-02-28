// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Personal.h"
#include "../include/Engineer.h"
#include "../include/Manager.h"

TEST(staffTest, test1) {
Cleaner cleaner1(0,
                 "Алексеев Ярослав Сергеевич",
                 150);
EXPECT_EQ(0, cleaner1.getId());
}

TEST(staffTest, test2) {
Cleaner cleaner1(0,
                 "Алексеев Ярослав Сергеевич",
                 150);
EXPECT_EQ(150, cleaner1.getSalary());
}

TEST(staffTest, test3) {
Cleaner cleaner1(0,
                 "Алексеев Ярослав Сергеевич",
                 150);
cleaner1.setWorkTime(22)
EXPECT_EQ(22, cleaner1.getWorkTime());
}

TEST(staffTest, test4) {
Cleaner cleaner1(0,
                 "Алексеев Ярослав Сергеевич",
                 150);
EXPECT_EQ(0, cleaner1.getPosition());
}

TEST(staffTest, test5) {
Driver driver1(0,
               "Леонов Давид Тимурович",
               150);
EXPECT_EQ(1, driver1.getPosition());
}

TEST(staffTest, test6) {
Programmer programmer1(0,
                       "Алексеев Ярослав Сергеевич",
                       150,
                       new Project(1, 3000000));
EXPECT_EQ(2, programmer1.getPosition());
}

TEST(staffTest, test7) {
Programmer programmer1(0,
                       "Алексеев Ярослав Сергеевич",
                       150,
                       new Project(1, 3000000));
EXPECT_EQ("Алексеев Ярослав Сергеевич", programmer1.getName());
}

TEST(staffTest, test8) {
Programmer programmer1(0,
                       "Алексеев Ярослав Сергеевич",
                       150,
                       new Project(1, 3000000));
EXPECT_EQ(1, programmer1.getProject()->getId());
}

TEST(staffTest, test9) {
Project* project = new Project(1,
                               3000000);
EXPECT_EQ(0, project->getNumOfWorkers());
}

TEST(staffTest, test10) {
Project* project = new Project(1,
                               3000000);
Programmer programmer1(0,
                       "Алексеев Ярослав Сергеевич",
                       200,
                       project);
programmer1.setWorkTime(10);
programmer1.calcProAdditions();
programmer1.calc();
EXPECT_EQ(3025555, programmer1.getPayment());
}

TEST(staffTest, test11) {
std::vector<Project*> projects;
projects.push_back(new Project(1,
                               3000000));
Programmer programmer1(0,
                       "Алексеев Ярослав Сергеевич",
                       200,
                       projects[0]);
Tester tester1(1,
               "Павлов Никита Андреевич",
               200,
               projects[0]);
ProjectManager projectManager1(2,
                               "Леонов Давид Тимурович",
                               projects);
EXPECT_EQ(3, projects[0]->getNumOfWorkers());
}

TEST(staffTest, test12) {
std::vector<Project*> projects;
projects.push_back(new Project(1,
                               3000000));
Programmer programmer1(0,
                       "Алексеев Ярослав Сергеевич",
                       200,
                       projects[0]);
ProjectManager projectManager1(1,
                               "Леонов Давид Тимурович",
                               projects);
projectManager1.calc()
EXPECT_EQ(152600, projectManager1.getPayment());
}

TEST(staffTest, test13) {
std::vector<Project*> projects;
projects.push_back(new Project(1,
                               3000000));
projects.push_back(new Project(2,
                               3000000));
std::vector<Project*> projects1;
projects1.push_back(projects[0]);
std::vector<Project*> projects2;
projects1.push_back(projects[1]);
Programmer programmer1(0,
                       "Алексеев Ярослав Сергеевич",
                       200,
                       projects[0]);
Programmer programmer2(1,
                       "Никифоров Петр Петрович",
                       200,
                       projects[1]);
ProjectManager projectManager1(2,
                               "Леонов Давид Тимурович",
                               projects1);
ProjectManager projectManager2(3,
                               "Ярошенко Александр Леонович",
                               projects2);
SeniorManager seniorManager1(4,
                             "Иванов Иван Иванович",
                             projects);
int numOfPositions = projects[0]->getNumOfWorkers() + projects[2]->getNumOfWorkers();
EXPECT_EQ(6, numOfPositions);
}

TEST(staffTest, test14) {
std::vector<Project*> projects;
projects.push_back(new Project(1,
3000000));
projects.push_back(new Project(2,
3000000));
std::vector<Project*> projects1;
projects1.push_back(projects[0]);
std::vector<Project*> projects2;
projects1.push_back(projects[1]);
Programmer programmer1(0,
                       "Алексеев Ярослав Сергеевич",
                       200,
                       projects[0]);
Programmer programmer2(1,
                       "Никифоров Петр Петрович",
                       200,
                       projects[1]);
ProjectManager projectManager1(2,
                               "Леонов Давид Тимурович",
                               projects1);
ProjectManager projectManager2(3,
                               "Ярошенко Александр Леонович",
                               projects2);
SeniorManager seniorManager1(4,
                             "Иванов Иван Иванович",
                             projects);
seniorManager1.calc();
EXPECT_EQ(2006500, seniorManager1.getPayment());
}

TEST(staffTest, test15) {
std::vector<Project*> projects;
projects.push_back(new Project(1,
3000000));
projects.push_back(new Project(2,
3000000));
std::vector<Project*> projects1;
projects1.push_back(projects[0]);
std::vector<Project*> projects2;
projects1.push_back(projects[1]);
Programmer programmer1(0,
                       "Алексеев Ярослав Сергеевич",
                       200,
                       projects[0]);
Programmer programmer2(1,
                       "Никифоров Петр Петрович",
                       200,
                       projects[1]);
ProjectManager projectManager1(2,
                               "Леонов Давид Тимурович",
                               projects1);
ProjectManager projectManager2(3,
                               "Ярошенко Александр Леонович",
                               projects2);
SeniorManager seniorManager1(4,
                             "Иванов Иван Иванович",
                             projects);
seniorManager1.calc();

EXPECT_EQ(projects, seniorManager1.getProjects());
}
