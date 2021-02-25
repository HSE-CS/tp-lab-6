// Copyright 2021 by Fatin Maxim
#include "Factory.h"
#include <iostream>

std::vector<Employee*> makeStaff() {
    std::ifstream data_file("data.csv");
    std::vector<Employee*> employee;
    if (data_file.is_open()) {
        std::string str = "";
        getline(data_file, str, '\n');
        while (data_file.good()) {
            str.clear();
            std::string id, name, position, project, salary;
            getline(data_file, id, ';');
            getline(data_file, name, ';');
            getline(data_file, position, ';');
            getline(data_file, salary, ';');
            getline(data_file, project, '\n');
            if (position == "driver") {
                employee.push_back(new Driver(stoi(id), name,
                    Position::DRIVER, stoi(salary)));
            }
            else if (position == "cleaner") {
                employee.push_back(new Cleaner(stoi(id), name,
                    Position::CLEANER, stoi(salary)));
            }
            else if (position == "project manager") {
                employee.push_back(new ProjectManager(stoi(id),
                    name, Position::PROJECT_MANAGER, project));
            }
            else if (position == "senior manager") {
                employee.push_back(new SeniorManager(stoi(id),
                    name, Position::SENIOR_MANAGER, project));
            }
            else if (position == "engineer") {
                employee.push_back(new Engineer(stoi(id), name,
                    Position::ENGINEER, project, stoi(salary)));
            }
            else if (position == "tester") {
                employee.push_back(new Tester(stoi(id), name,
                    Position::ENGINEER, project, stoi(salary)));
            }
            else if (position == "programmer") {
                employee.push_back(new Programmer(stoi(id), name,
                    Position::PROGRAMMER, project, stoi(salary)));
            }
            else if (position == "team lead") {
                employee.push_back(new TeamLead(stoi(id), name,
                    Position::TEAM_LEAD, project, stoi(salary)));
            }
            else {
                std::cout << "Something wrong!";
            }
        }
    }
    data_file.close();
    return employee;
}
