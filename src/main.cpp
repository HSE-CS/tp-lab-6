// Copyright [2020] <Olesya Nikolaeva>

#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"
#include "Factory.h"


int main() { /*
    std::ifstream file("/Users/lesyanikolaeva/Documents/lab6/lab6/work.txt");
    Staff newteam;
    newteam.makeStaff(std::move(file));
    newteam.addTimeToAll(40);
    std::cout << newteam.staffNumber() << std::endl;
    std::cout << newteam.projectsNumber() << std::endl;
    newteam.calcAll();
    //newteam.printStaff();
    std::cout << newteam.returnPayment("107") << std::endl;
    SeniorManager * newone = new SeniorManager("113", "NikolayKrotov", newteam.findProject("Microsoft"));
    //newone->addProject(newteam.findProject("Oxford"));
    Employee * example = newone;
    example->addWorkTime(20);
    example->calc();
    newteam.addMember(example);
    newteam.printStaff(); */
    Tester example("101", "Ekaterina Stupina", 20, new Project("New", 30));
    example.addWorkTime(10);
    example.calc();
    std::cout << example.returnPayment() << std::endl;
    example.errors(50);
    example.calc();
    std::cout << example.returnPayment() << std::endl;
    return 0;
}
