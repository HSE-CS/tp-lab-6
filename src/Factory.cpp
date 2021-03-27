// Copyright 2021 asma
#include "Factory.h"

StaffFactory::StaffFactory(std::string emp, std::string proj) {
    emp_filename = emp;
    proj_filename = proj;
}

std::vector<Employee*> StaffFactory::ReadEmployees() {
    std::ifstream emp_input(emp_filename);
    std::ifstream proj_input(proj_filename);
    std::vector<Employee*> emp;
    std::vector<Project*> projects;
    int project_id = 0;
    int budget = 0;
    int senior_id = 0;
    while (proj_input >> project_id) {
        proj_input >> budget >> senior_id;
        Project* project = new Project(project_id, budget, senior_id);
        projects.push_back(project);
    }
    int id = 0;
    int salary = 0;
    double part = 0;
    std::string name, surname, position;
    while (emp_input >> id) {
        emp_input >> surname >> name >>
            position >> salary >> project_id >> part;
        if (position == "Programmer") {
            for (auto p : projects) {
                if (p->id == project_id) {
                    Programmer* employee = new Programmer(id, surname + " " +
                        name, Position::PROGRAMMER, salary, p, part);
                    emp.push_back(employee);
                }
            }
        }
        if (position == "Tester") {
            for (auto p : projects) {
                if (p->id == project_id) {
                    Tester* employee = new Tester(id, surname + " " + name,
                        Position::TESTER, salary, p, part);
                    emp.push_back(employee);
                }
            }
        }
        if (position == "Engineer") {
            for (auto p : projects) {
                if (p->id == project_id) {
                    Engineer* employee = new Engineer(id, surname + " " + name,
                        Position::ENGINEER, salary, p, part);
                    emp.push_back(employee);
                }
            }
        }
        if (position == "TeamLeader") {
            for (auto p : projects) {
                if (p->id == project_id) {
                    TeamLeader* employee = new TeamLeader(id, surname + " " +
                        name, Position::TEAMLEADER, salary, p, part);
                    emp.push_back(employee);
                }
            }
        }
        if (position == "ProjectManager") {
            for (auto p : projects) {
                if (p->id == project_id) {
                    ProjectManager* employee = new ProjectManager(id,
                        surname + " " + name,
                            Position::PROJECTMANAGER, p, part);
                    emp.push_back(employee);
                }
            }
        }
        if (position == "SeniorManager") {
            std::vector<Project*> senior_projects;
            for (auto p : projects) {
                if (p->senior_id == id) {
                    senior_projects.push_back(p);
                }
            }
            SeniorManager* employee = new SeniorManager(id, surname + " " +
                name, Position::SENIORMANAGER, senior_projects);
            emp.push_back(employee);
        }
        if (position == "Driver") {
            Driver* employee = new Driver(id, surname + " " + name,
                Position::DRIVER, salary);
            emp.push_back(employee);
        }
        if (position == "Cleaner") {
            Cleaner* employee = new Cleaner(id, surname + " " + name,
                Position::CLEANER, salary);
            emp.push_back(employee);
        }
    }
    emp_input.close();
    proj_input.close();
    return emp;
}
