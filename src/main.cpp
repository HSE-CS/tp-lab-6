// Copyright [2020] <Olesya Nikolaeva>

#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"
#include "Factory.h"


int main() {
    std::ifstream file("work.txt");
    Staff newteam;
    newteam.makeStaff(std::move(file));
    newteam.addTimeToAll(40);
    std::cout << newteam.staffNumber() << std::endl;
    std::cout << newteam.projectsNumber() << std::endl;
    newteam.calcAll();
    std::cout << newteam.returnPayment("107") << std::endl;
    SeniorManager * newone = new SeniorManager("113", "NikolayKrotov",
                                               newteam.findProject("Microsoft"));
    Employee * example = newone;
    example->addWorkTime(20);
    example->calc();
    newteam.addMember(example);
    newteam.printStaff();
    return 0;
}
