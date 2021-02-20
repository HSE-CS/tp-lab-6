// Copyright 2021 soda
#include "Interfaces.h"

#include "Company.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "json.hpp"


using json = nlohmann::json;


Company::Company() {
    this->all_projects = new std::vector<Project*>;
    this->all_employee = new std::vector<Employee*>;
}

void Company::create_all_projects() {
    std::ifstream i("projects.json");
    json json_projects;
    i >> json_projects;
    i.close();
    auto projects_json = json_projects.get<std::vector<json>>();
    for (const auto& index : projects_json) {
        auto Id = index["Id"].get<std::string>();
        auto Name = index["Name"].get<std::string>();
        auto Budget = index["Budget"].get<std::string>();
        
        auto project = new Project(atoi(Id.c_str()),
            atoi(Budget.c_str()), Name);

        this->all_projects->push_back(project);
    }
}

void Company::create_all_employee() {
    std::ifstream i("employee.json");
    json json_employee;
    i >> json_employee;
    i.close();
    auto groups_json = json_employee.get<std::vector<json>>();
    for (const auto& index : groups_json) {

        auto Id = index["Id"].get<std::string>();
        auto Name = index["Name"].get<std::string>();
        auto WorkTime = index["WorkTime"].get<std::string>();
        auto Position = index["Position"].get<std::string>();

        if (Position == "DRIVER") {
            auto Salary = index["Salary"].get<std::string>();
            size_t pos = DRIVER;
            auto* driver = new Driver(atoi((Id.c_str())), Name,
                atoi((WorkTime.c_str())), pos, atoi((Salary.c_str())));

            this->all_employee->push_back(driver);

        } else if (Position == "CLEANER") {
            auto Salary = index["Salary"].get<std::string>();
            size_t pos = CLEANER;
            auto* cleaner = new Cleaner(atoi((Id.c_str())), Name,
                atoi((WorkTime.c_str())), pos, atoi((Salary.c_str())));

            this->all_employee->push_back(cleaner);

        } else if (Position == "SECURITY") {
            auto Salary = index["Salary"].get<std::string>();
            auto Killed = index["Killed"].get<std::string>();
            size_t pos = SECURITY;
            auto* security = new Security(atoi((Id.c_str())), Name,
                atoi((WorkTime.c_str())), pos, atoi((Salary.c_str())),
                atoi((Killed.c_str())));

            this->all_employee->push_back(security);

        } else if (Position == "ENGINEER") {
            auto Salary = index["Salary"].get<std::string>();
            auto ProjectId = index["Project"].get<std::string>();
            size_t pos = ENGINEER;
            Project* proj =
                this->getProject((size_t)(atoi((ProjectId.c_str()))));
            auto* engineer = new Engineer(atoi((Id.c_str())), Name,
                atoi((WorkTime.c_str())), pos, proj, atoi((Salary.c_str())));

            this->all_employee->push_back(engineer);

        } else if (Position == "PROGRAMMER") {

        } else if (Position == "TESTER") {

        } else if (Position == "TEAMLEADER") {

        } else if (Position == "MANAGER") {

        } else if (Position == "SENIORMANAGER") {

        } else {
            throw(1);
        }
        
    }
}

Project* Company::getProject(size_t id) {
    return this->all_projects->at(id - 1);
}

Employee* getEmployee(size_t);
void print_all_info();
