// Copyright 2021 MalininDmitry
#include <iostream>
#include <fstream>
#include "Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "nlohmann/json.hpp"

int Project::GetId() const {
    return id;
}

void Project::SetId(int id) {
    this->id = id;
}

int Project::GetBudget() const {
    return budget;
}

void Project::SetBudget(int budget) {
    this->budget = budget;
}

std::vector<Employee*> StaffFactory::makeStaff() {
    std::vector<Project*> proj;
    std::string pfile = R"(projects.json)";

    std::ifstream pfile2(pfile);
    nlohmann::json jsonProj;
    pfile2 >> jsonProj;
    pfile2.close();

    auto projectJson =
    jsonProj["projects"].get<std::vector<nlohmann::json>>();
    for (const auto& p : projectJson) {
        int id = p["id"].get<int>();
        int budget = p["budget"].get<int>();
        proj.push_back(new Project{id, budget});
    }
    std::vector<Employee*> empl;
    std::string efile = R"(employees.json)";

    std::ifstream efile2(efile);
    nlohmann::json jsonEmpl;
    efile2 >> jsonEmpl;
    efile2.close();
    int id = 0;
    auto employeeJson =
    jsonEmpl["employees"].get<std::vector<nlohmann::json>>();
    for (const auto& e : employeeJson) {
        std::string position = e["position"].get<std::string>();
        std::string name = e["name"].get<std::string>();
        if (position == "driver" || position == "cleaner") {
            int salary = e["salary"].get<int>();
            if (position == "driver") {
                empl.push_back(new
                        Driver(id++, name, position, salary));
            } else {
                empl.push_back(
                new Cleaner(id++, name, position, salary));
            }
        } else if (position == "programmer") {
            unsigned int salary = e["salary"].get<int>();
            int projectid = e["project"].get<int>();
            int part = e["part"].get<int>();
            empl.push_back(new Programmer(id++, name,
                    position, salary,
                    proj[projectid],
                    static_cast<float>(part)));
        } else if (position == "tester") {
            int salary = e["salary"].get<int>();
            int projectid = e["project"].get<int>();
            int part = e["part"].get<int>();
            empl.push_back(new Tester(id++, name,
            position, salary, proj[projectid],
            static_cast<float>(part)));
        } else if (position == "project_manager") {
            int salary = e["salary"].get<int>();
            std::vector<int> projects1 =
            e["project"].get<std::vector<int>>();
            int part = e["part"].get<int>();
            std::vector<Project *> projects2;
            projects2.push_back(proj[projects1[0]]);
            empl.push_back(new
                ProjectManager(id++,
                name, position, 1, projects2,
                static_cast<float>(part), salary));
        } else if (position == "senior_manager") {
            int salary = e["salary"].get<int>();
            int part = e["part"].get<int>();
            empl.push_back(new SeniorManager(id++,
            name, position, static_cast<int>(proj.size()),
            proj, static_cast<float>(part), salary));
        } else {
            int projects1 = e["project"].get<int>();
            int salary = e["salary"].get<int>();
            int part = e["part"].get<int>();
            empl.push_back(new TeamLeader(
            id++, name, position, salary,
            proj[projects1],
            static_cast<float>(part)));
        }
    }

    return empl;
}

