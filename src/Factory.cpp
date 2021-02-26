// Copyright 2021 Khoroshavina Ekaterina
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iostream>
#include "Factory.h"
#include "Manager.h"
#include "Employee.h"
#include "Engineer.h"

std::vector<Employee*> makeStaff(std::string input) {
    std::ifstream file(input);
    if (file.is_open()) {
        std::vector<Employee*> employee;
        std::string buf = "";
        if (file.good()) {
            getline(file, buf, '\n');
        }
        while (file.good()) {
            buf.clear();
            std::string id, fio, position, payment;
            std::string project_id, project_budget;
            getline(file, id, ';');
            getline(file, fio, ';');
            getline(file, position, ';');
            getline(file, payment, ';');
            getline(file, project_id, ';');
            getline(file, project_budget, '\n');

            if (position == "tester") {
                Project* project = new Project(stoi(project_id),
                                    stoi(project_budget));
                employee.push_back(new Tester(stoi(id), fio,
                    position, stoi(payment), project));
            } else if (position == "programmer") {
                Project* project = new Project(stoi(project_id),
                                    stoi(project_budget));
                employee.push_back(new Programmer(stoi(id), fio,
                    position, stoi(payment), project));
            } else if (position == "teamleader") {
                Project* project = new Project(stoi(project_id),
                                     stoi(project_budget));
                employee.push_back(new TeamLeader(stoi(id), fio,
                    position, stoi(payment), project));
            } else if (position == "cleaner") {
                employee.push_back(new Cleaner(stoi(id), fio,
                    position, stoi(payment)));
            } else if (position == "driver") {
                employee.push_back(new Driver(stoi(id), fio,
                    position, (stoi(payment)));
            } else if (position == "project manager") {
                Project* project = new Project(stoi(project_id),
                                      stoi(project_budget));
                employee.push_back(new ProjectManager(stoi(id), fio,
                    position, (stoi(payment), project));
            } else if (position == "senior manager") {
                std::vector <Project*> projects;
                employee.push_back(new SeniorManager(stoi(id), fio,
                    position, stoi(payment), projects));
            }
        }
        return employee;
    } else {
        throw "file error";
    }
}
