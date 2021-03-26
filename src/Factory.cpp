// Copyright 2021 Ziganshin Nikita

#include "Factory.h"

std::vector<Employee*> StaffFactory::makeStaff(const std::string& path) {
    std::ifstream in(path);
    std::vector<Employee*> staff;
    int id = 0, salary = 0;
    std::string name, position;
    while (in >> id >> name >> position >> salary) {
        if (position == "Driver") {
            Driver driver1(id, name, salary);
            staff.emplace_back(&driver1);
        } else if (position == "Cleaner") {
            Cleaner cleaner1(id, name, salary);
            staff.emplace_back(&cleaner1);
        } else if (position == "Programmer") {
            Programmer programmer1(id, name, salary);
            staff.emplace_back(&programmer1);
        } else if (position == "Tester") {
            Tester tester1(id, name, salary);
            staff.emplace_back(&tester1);
        } else if (position == "TeamLeader") {
            TeamLeader teamLeader1(id, name, salary);
            staff.emplace_back(&teamLeader1);
        } else if (position == "ProjectManager") {
            Project project(0, 0);
            ProjectManager projectManager1(id, name, project);
            staff.emplace_back(&projectManager1);
        } else if (position == "SeniorManager") {
            Project project(0, 0);
            SeniorManager seniorManager1(id, name, project);
            staff.emplace_back(&seniorManager1);
        }
    }
    in.close();
    return staff;
}
