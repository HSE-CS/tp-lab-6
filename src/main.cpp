#include <iostream>

#include "Manager.h"
#include "Factory.h"

static const std::string file("EmployeeList.txt");


signed main() {
    // id генерируется автоматически, поэтому в файле не нужен
    Factory::__debug_pwd();

    Project proj;
    proj.setBudget(10000);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("Mark 2");
    Programmer p1("Mark Wolf", 8, &proj, PROGRAMMER, 128000);
    Programmer p2("Steve Rambo", 12, &proj, TESTER, 128000);
    p1.printInfo();
    p2.printInfo();

    return 0;
}
