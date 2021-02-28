// Copyright 2021 dmitrycvetkov2000
#include "Factory.h"

#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"

#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

std::vector<Employee*> StaffFactory::makeStaff(
    const std::string& staffFile,
    const std::string& projFile) {
    std::ifstream projStream(projFile);
    int id;
    int budget;
    int managerId;
    while (projStream >> id) {
        projStream >> budget >> managerId;
        auto project = new Project;
        project->id = id;
        project->budget = budget;
        project->seniorManager = managerId;
        projects[id] = project;
    }

    std::vector<Employee*> staff;
    int salary, position, projectId;
    float projectPart;
    std::string name, lastName;
    projStream.close();

    std::ifstream staffStream(staffFile);
    bool isopen = staffStream.is_open();
    while (staffStream >> id) {
        staffStream >> name >> lastName >> position >> salary >>
            projectId >> projectPart;
        switch (static_cast<Position>(position)) {
        case Position::Driver:
        {
            auto emp = new Driver(id, name + " " + lastName, salary);
            staff.push_back(emp);
            break;
        }
        case Position::Cleaner:
        {
            auto emp = new Cleaner(id, name + " " + lastName, salary);
            staff.push_back(emp);
            break;
        }
        case Position::Engineer:
        {
            auto emp = new Engineer(id, name + " " + lastName, salary,
                Position::Engineer, projects[projectId], projectPart);
            staff.push_back(emp);
            break;
        }
        case Position::Programmer:
        {
            auto emp = new Programmer(id, name + " " + lastName, salary,
                projects[projectId], projectPart);
            staff.push_back(emp);
            break;
        }
        case Position::Tester:
        {
            auto emp = new Tester(id, name + " " + lastName, salary,
                projects[projectId], projectPart);
            staff.push_back(emp);
            break;
        }
        case Position::TeamLeader:
        {
            auto emp = new TeamLeader(id, name + " " + lastName, salary,
                projects[projectId], projectPart);
            staff.push_back(emp);
            break;
        }
        case Position::ProjectManager:
        {
            auto emp = new ProjectManager(id, name + " " + lastName,
                projects[projectId], projectPart);
            staff.push_back(emp);
            break;
        }
        case Position::SeniorManager:
        {
            std::unordered_set<Project*> managedProjects;
            for (const auto &[_, proj] : projects) {
                if (proj->seniorManager == id) {
                    managedProjects.insert(proj);
                }
            }
            auto emp = new SeniorManager(id, name + " " + lastName,
                std::move(managedProjects));
            staff.push_back(emp);
            break;
        }
    }
    }
    staffStream.close();

    return staff;
}
