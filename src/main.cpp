// Copyright 2021 me

#include "../include/Employee.h"
#include "../include/Engineer.h"
#include "../include/Factory.h"
#include "../include/Manager.h"
#include "../include/Personal.h"


int main() { 

      std::string pathToProjects = "../tp-lab-6/src/Projects.json";
      std::vector<Project*> Projects(makeProjects(pathToProjects));
      std::string pathToEmployees = "../tp-lab-6/src/Employees.json";
      
      std::vector<Employee*> Company(makeStaff(pathToEmployees, Projects));
      for (auto a : Company) {
        a->printInfo();
      }
   /*Driver a1(0, std::string ("Petya"), Position(6), 130, 1);
   a1.printInfo();

   Cleaner a2(1, std::string("Galina"), Position(7), 100);
   a2.setWorkTime(100);

   Project pro(1, 10000);
   Project pro1(2, 10000);

   Programmer a3(2, std::string("Vasya"), Position(1), 200, &pro);
   a3.setWorkTime(100);
   pro.addWorker(&a3);


   Tester a4(3, std::string("Georgiy"), Position(2), 100, &pro);
   a4.setWorkTime(100);
   pro.addTester(&a4);

   TeamLeader a5(4, std::string("San Sanych"), Position(3), 220, &pro);
   a5.setWorkTime(100);

    ProjectManager a6(5, std::string("Evgeniy"), Position(4), &pro);
   a6.setWorkTime(100);

   SeniorManager a7(6, std::string("Evgeniy"), Position(4));
   a7.addProject(&pro);
   a7.addProject(&pro1);
   a7.setWorkTime(100);

   Company.push_back(&a1);
   Company.push_back(&a2);
   Company.push_back(&a3);
   Company.push_back(&a4);
   Company.push_back(&a5);
   Company.push_back(&a6);
   Company.push_back(&a7);

   for (auto emp : Company) {
     emp->printInfo();
   }*/
    return 0; 
}
