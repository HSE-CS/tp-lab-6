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

    this->create_all_projects();
    this->create_all_employee();
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
    auto employee_json = json_employee.get<std::vector<json>>();
    for (const auto& index : employee_json) {

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
            auto Salary = index["Salary"].get<std::string>();
            auto ProjectId = index["Project"].get<std::string>();
            size_t pos = PROGRAMMER;
            Project* proj =
                this->getProject((size_t)(atoi((ProjectId.c_str()))));
            auto* programmer = new Programmer(atoi((Id.c_str())), Name,
                atoi((WorkTime.c_str())), pos, proj, atoi((Salary.c_str())));

            this->all_employee->push_back(programmer);

        } else if (Position == "TESTER") {
            auto Salary = index["Salary"].get<std::string>();
            auto ProjectId = index["Project"].get<std::string>();
            size_t pos = TESTER;
            Project* proj =
                this->getProject((size_t)(atoi((ProjectId.c_str()))));
            auto* tester = new Tester(atoi((Id.c_str())), Name,
                atoi((WorkTime.c_str())), pos, proj, atoi((Salary.c_str())));

            this->all_employee->push_back(tester);

        } else if (Position == "TEAMLEADER") {
            auto Salary = index["Salary"].get<std::string>();
            auto ProjectId = index["Project"].get<std::string>();
            size_t pos = TEAMLEADER;
            Project* proj =
                this->getProject((size_t)(atoi((ProjectId.c_str()))));
            auto* teamleader = new TeamLeader(atoi((Id.c_str())), Name,
                atoi((WorkTime.c_str())), pos, proj, atoi((Salary.c_str())));

            this->all_employee->push_back(teamleader);

        } else if (Position == "MANAGER") {
            auto ProjectId = index["Project"].get<std::string>();
            size_t pos = MANAGER;
            Project* proj =
                this->getProject((size_t)(atoi((ProjectId.c_str()))));
            auto* manager = new ProjectManager(atoi((Id.c_str())), Name,
                atoi((WorkTime.c_str())), pos, proj);

            this->all_employee->push_back(manager);

        } else if (Position == "SENIORMANAGER") {
            size_t pos = SENIORMANAGER;
            auto* senior = new SeniorManager(atoi((Id.c_str())), Name,
                atoi((WorkTime.c_str())), pos, this->all_projects);

            this->all_employee->push_back(senior);

        } else {
            throw(1);
        }
        
    }
}

Project* Company::getProject(size_t id) {
    return this->all_projects->at(id - 1);
}

Employee* Company::getEmployee(size_t id) {
    return this->all_employee->at(id - 1);
}

size_t Company::getEmployeeNum() {
    return (this->all_employee->size());
}
size_t Company::getProjectNum() {
    return (this->all_projects->size());
}

void Company::set_all_payment() {
    for (auto index : *(this->all_employee)) {
        index->setPayment(index->calc());
    }
}

uint64_t Company::avarage_payment() {
    uint64_t pay = 0;
    for (auto index : *(this->all_employee)) {
        pay += index->getPayment();
    }
    return (pay / this->getEmployeeNum());
}

void Company::print_all_info() {
    std::cout << "Information about company!" << std::endl;
    std::cout << "We have - " << this->getProjectNum() << " projects:"
        << std::endl;
    for (auto index : *(this->all_projects)) {
        std::cout << index->getId() << ". " << index->getName()
            << "; Budget = " << index->getBudget() << "; Employee = "
            << index->getNumWorker() << ";" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "We have - " << this->getEmployeeNum() << " employee:"
        << std::endl;
    for (auto index : *(this->all_employee)) {
        index->printInfo();
    }
    std::cout << std::endl;

    std::cout << "Avarage Payment = " << this->avarage_payment()
        << ";" << std::endl;
    std::cout << "Thanks for your attention!" << std::endl;
    std::cout << std::endl;
}
