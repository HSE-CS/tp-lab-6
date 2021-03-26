// Copyright 2020 Uskova

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"
#include "Project.h"

int main() {
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
    workers[i]->printinfo();
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "----------------------------------" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
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
    workers[i]->printinfo();
  }
}
