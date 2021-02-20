// Copyright 2021 Arina Simonova

#include "Factory.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
  string proj = "G:\\GitHubTasks\\lab-6\\Development-Template\\projects.txt";
  string myStaff = "G:\\GitHubTasks\\lab-6\\Development-Template\\MyStaff.txt";
  srand(time(NULL));
 vector<Employee *> staff = makeStaff(&myStaff[0], &proj[0]);
  string surname[] {"Иванов", "Петров", "Сидоров", "Смирнов" };
  string name[] {"Иван", "Николай", "Глеб", "Андрей" };
  string position[]{ "Senior Manager", "Project Manager", "Engineer", "Cleaner",
    "Driver", "Programmer", "Tester", "Team Lead", "Personal" };
  /*
  ofstream out;
  out.open("G:\\GitHubTasks\\lab-6\\Development-Template\\MyStaff.txt", ios::out);
  if (out.is_open()) {
    int i;
    for (i = 0; i < 50; ++i) {
      cout << to_string(150 + (rand() % 100)) << endl;
      out << to_string(i) + "," +
        name[rand() % 4] + " " +
        surname[rand() % 4] + "," +
        position[rand() % 9] + "," +
        to_string(150 + (rand() % 1000)) + "," +
        to_string(rand() % 2) << endl;
    }
  }
  */
  for (int i = 0; i < 50; ++i) {
    staff[i]->SetWorkTime(20 + rand() % 35);
    staff[i]->Calc();
    staff[i]->PrintInfo();
  }

}
