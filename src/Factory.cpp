// Copyright 2021 Danyaev Artem
#include "Factory.h"

std::vector<Employee*> Factory::makeStaff(std::string projectsPath,
    std::string staffPath) {
    std::vector<Project*> projects;
    std::ifstream fin(projectsPath);
    std::string line;
    std::getline(fin, line);
    while (line != "") {
        unsigned int id = std::stoi(line.substr(0, line.find(';')));
        std::string name =
            line.substr(line.find(';') + 1,
                line.rfind(';') - line.find(';') - 1);
        int budget = std::stoi(line.substr(line.rfind(';') + 1));
        projects.push_back(new Project(id, name, budget));
        std::getline(fin, line);
    }
    fin.close();
    std::vector<Employee*> employees;
    fin = std::ifstream(staffPath);
    std::getline(fin, line);
    while (line != "") {
        int pos = line.find(';');
        unsigned int id = std::stoi(line.substr(0, pos));
        int npos = line.find(';', pos + 1);
        std::string name = line.substr(pos + 1, npos - pos - 1);
        pos = npos;
        npos = line.find(';', pos + 1);
        std::string position = line.substr(pos + 1, npos - pos - 1);
        if (position == "DRIVER") {
            int salary = std::stoi(line.substr(npos + 1));
            employees.push_back(new Driver(id, name, DRIVER, salary));
        } else if (position == "CLEANER") {
            int salary = std::stoi(line.substr(npos + 1));
            employees.push_back(new Cleaner(id, name, CLEANER, salary));
        } else if (position == "TESTER") {
            pos = npos + 1;
            npos = line.find(';', pos);
            int salary = std::stoi(line.substr(pos, npos - pos));
            std::string project_name = line.substr(npos + 1);
            Project* proj_pointer = nullptr;
            for (Project* p : projects) {
                if (p->getName() == project_name) {
                    proj_pointer = p;
                    p->numOfWorkers++;
                    break;
                }
            }
            employees.push_back(new Tester(id, name, TESTER,
                  salary, proj_pointer));
        } else if (position == "PROGRAMMER") {
            pos = npos + 1;
            npos = line.find(';', pos);
            int salary = std::stoi(line.substr(pos, npos - pos));
            std::string project_name = line.substr(npos + 1);
            Project* proj_pointer = nullptr;
            for (Project* p : projects) {
                if (p->getName() == project_name) {
                    proj_pointer = p;
                    p->numOfWorkers++;
                    break;
                }
            }
            employees.push_back(
                new Programmer(id, name, PROGRAMMER, salary, proj_pointer));
        } else if (position == "TEAM_LEADER") {
            pos = npos + 1;
            npos = line.find(';', pos);
            int salary = std::stoi(line.substr(pos, npos - pos));
            std::string project_name = line.substr(npos + 1);
            Project* proj_pointer = nullptr;
            for (Project* p : projects) {
                if (p->getName() == project_name) {
                    proj_pointer = p;
                    p->numOfWorkers++;
                    break;
                }
            }
            employees.push_back(
                new TeamLeader(id, name, TEAM_LEADER, salary, proj_pointer));
        } else if (position == "PROJECT_MANAGER") {
            std::string project_name = line.substr(npos + 1);
            Project* proj_pointer = nullptr;
            for (Project* p : projects) {
                if (p->getName() == project_name) {
                    proj_pointer = p;
                    p->numOfWorkers++;
                    break;
                }
            }
            employees.push_back(
                new ProjectManager(id, name, PROJECT_MANAGER, proj_pointer));
        } else if (position == "SENIOR_MANAGER") {
            for (Project* p : projects) {
                p->numOfWorkers++;
            }
            employees.push_back(
                new SeniorManager(id, name, PROJECT_MANAGER, projects));
        }
        std::getline(fin, line);
    }
    fin.close();

    return employees;
}
