// Copyright 2021 valvarl

#include <fstream>
#include <nlohmann/json.hpp>
#include <Engineer.h>
#include <Manager.h>

std::vector<Employee *> StaffFactory::makeStaff() {
    std::vector<Project*> projects;
    std::string p = R"(projects.json)";
    std::ifstream ip(p);
    nlohmann::json jp;
    ip >> jp;
    ip.close();
    auto proj = jp["projects"].get<std::vector<nlohmann::json>>();
    for (const auto& v : proj) {
        auto _id = v["id"].get<int>();
        auto name = v["name"].get<std::string>();
        auto budget = v["budget"].get<int>();
        projects.push_back(new Project{_id, name, budget});
    }
    int id = 0;
    std::vector<Employee*> staff;
    std::string e = R"(employees.json)";
    std::ifstream ie(e);
    nlohmann::json je;
    ie >> je;
    ie.close();
    auto employees = je["employees"].get<std::vector<nlohmann::json>>();
    for (const auto& v : employees) {
        auto position = v["position"].get<std::string>();
        auto name = v["name"].get<std::string>();
        Position pos;
        if (position == "project_manager" ||
            position == "senior_manager") {
            auto project = v["project"].get<std::vector<int>>();
            auto part = v["part"].get<float>() / 100;
            if (position == "project_manager") {
                pos = Position(PROJECT_MANAGER);
                std::vector<Project*> prj;
                prj.push_back(projects[project[0]]);
                staff.push_back(new ProjectManager{
                        id++, name, pos, 1, prj, part});
            } else {
                pos = Position(SENIOR_MANAGER);
                staff.push_back(new SeniorManager{
                        id++, name, pos, static_cast<int>(projects.size()),
                        projects, part});
            }
        } else if (position == "cleaner" || position == "driver") {
            auto salary = v["salary"].get<int>();
            if (position == "cleaner") {
                pos = Position(CLEANER);
                staff.push_back(new Cleaner{
                        id++, name, pos, salary});
            } else {
                pos = Position(DRIVER);
                staff.push_back(
                        new Driver{id++, name, pos, salary});
            }
        } else if (position == "programmer" || position == "tester" ||
                   position == "team_leader") {
            auto salary = v["salary"].get<int>();
            auto project = v["project"].get<int>();
            auto part = v["part"].get<int>();
            if (position == "programmer") {
                pos = Position(PROGRAMMER);
                staff.push_back(new Programmer{
                        id++, name, pos, salary,
                        projects[project], (float)part});
            } else if (position == "tester") {
                pos = Position(TESTER);
                staff.push_back(new Tester{
                        id++, name, pos, salary,
                        projects[project],(float) part});
            } else {
                pos = Position(TEAM_LEADER);
                staff.push_back(new TeamLeader{
                        id++, name, pos, salary,
                        projects[project],(float) part});
            }
        }
    }
    return staff;
}
