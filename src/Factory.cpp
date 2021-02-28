// Copyright 2021 Islam Osmanov


#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <cstdio>
#include "Factory.h"
#include "Interfaces.h"
#include "Employee.h"
#include "Manager.h"
#include "Engineer.h"
#include <stdlib.h>

std::vector<Employee*> Factory::create_staff(std::string name) {
    std::ifstream f(name);
    Project* proj1;
    if (f.is_open()) {
        std::vector<Employee*> employees;
        if (f.good()) {
            std::string proj_id, workers_num, proj_budget;
            std::getline(f, proj_id, ',');
            std::getline(f, workers_num, ',');
            std::getline(f, proj_budget, '\n');
            proj1 = new Project(std::stoi(proj_id), std::stoi(proj_budget));
            proj1->addWorkers(std::stoi(workers_num));
        }
        while (f.good()) {
            std::string name, id, position, worktime, salary;
            std::getline(f, name, ',');
            std::getline(f, id, ',');
            std::getline(f, position, ',');
            std::getline(f, worktime, ',');
            std::getline(f, salary, '\n');
            (position == "DRIVER") {
                Driver* dr = new Driver(std::stoi(id), std::stoi(salary),
                                       position, name);
                dr->setWorkTime(std::stoi(worktime));
                employees.push_back(dr);
            } else if (position == "PROGRAMMER") {
                Programmer* pr = new Programmer(std::stoi(id), position,
                                                name, std::stoi(salary), proj1);
                pr->setWorkTime(std::stoi(worktime));
                employees.push_back(pr);
            } else if (position == "CLEANER") {
                Cleaner* cl = new Cleaner(std::stoi(id), std::stoi(salary),
                                          position, name);
                cl->setWorkTime(std::stoi(worktime));
                employees.push_back(cl);
            } else if (position == "TESTER") {
                Tester* tr = new Tester(std::stoi(id), position,
                                        name, std::stoi(salary), proj1);
                tr->setWorkTime(std::stoi(worktime));
                tr->addErrors();
                tr->addErrors();
                employees.push_back(tr);
            } else if (position =="TEAMLEADER") {
                TeamLeader* tl = new TeamLeader(std::stoi(id), position,
                                                name, std::stoi(salary),
                                                proj1->getWorkersNum() -2,
                                                proj1);
                tl->setWorkTime(std::stoi(worktime));
                employees.push_back(tl);
            } else if (position == "SENIORMANAGER") {
                std::vector<Project*> projects;
                projects.push_back(proj1);
                SeniorManager* sm = new SeniorManager(std::stoi(id), position,
                                        name, projects,
                                        projects.back()->getWorkersNum(),
                                        std::stoi(salary));
                employees.push_back(sm);
            } else if (position =="PROJECTMANAGER") {
                ProjectManager* pm = new ProjectManager(std::stoi(id), position,
                                         name, proj1->getWorkersNum() - 1,
                                         proj1, std::stoi(salary));
                employees.push_back(pm);
            }
        }
        return employees;
    }
}
