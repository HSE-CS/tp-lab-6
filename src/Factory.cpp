// Copyright 2021 Shatilov Victor

#include <fstream>
#include <iostream>

#include <Manager.h>
#include <Engineer.h>
#include <Factory.h>

Employee *makeWorker(int id, const std::string &name,  int workTime,
                     int salary, Positions position,
                     std::vector<Project*> projects) {
    switch (position) {
        case PROJECT_MANAGER:
            return new ProjectManager(id, name, workTime,
                                      position, std::move(projects));
        case TEAM_LEADER:
            return new TeamLeader(id, name, workTime, salary,
                                  position, projects[0]);
        case TESTER:
            return new Tester(id, name, workTime, salary,
                              position, projects[0]);
        case PROGRAMMER:
            return new Programmer(id, name, workTime, salary,
                                  position, projects[0]);
        case SENIOR_MANAGER:
            return new SeniorManager(id, name, workTime,
                                     position, projects);
        case DRIVER:
            return new Driver(id, name, workTime, salary,
                              position);
        case CLEANER:
            return new Cleaner(id, name, workTime, salary,
                               position);
        default:
            return nullptr;
    }
}

Project* getByName(const std::vector<Project *>& projects, const std::string& project_name) {
    for ( auto p: projects ) {
        if (p->getName() == project_name)
            return p;
    }
    return nullptr;
}

std::vector<Employee *> Factory::makeStaff() {
    std::ifstream projects_file(
            "/home/victor/CLionProjects/tp-lab-6/projects.csv");
    std::vector<Project *> projects;
    int project_id, count_workers, budget = 0;
    std::string project_name;

    std::ifstream workers_file(
            "/home/victor/CLionProjects/tp-lab-6/workers.csv");
    std::vector<Employee *> workers;
    int worker_id, work_time, salary = 0;
    Positions position;
    std::string worker_name, pos;

    if (!projects_file.is_open() || !workers_file.is_open())
        throw "Cannot open some of files";

    std::string line;
    while (!projects_file.eof()) {
        getline(projects_file, line);
        if (!line.empty()) {
            project_id = std::stoi(line.substr(0, line.find(';')));
            line = line.substr(line.find(';')+1);
            project_name = line.substr(0, line.find(';'));
            line = line.substr(line.find(';')+1);
            count_workers = std::stoi(line.substr(0, line.find(';')));
            line = line.substr(line.find(';')+1);
            budget = std::stoi(line);
            projects.push_back(new Project(project_id, project_name, budget, count_workers));
        }
    }
    auto *em = new Engineer(1, "test", 1, 400, ENGINEER, nullptr);
    std::cout << std::endl;
    while (!workers_file.eof()) {
        getline(workers_file, line);
        if (!line.empty()) {
            worker_id = std::stoi(line.substr(0, line.find(';')));
            line = line.substr(line.find(';')+1);
            worker_name = line.substr(0, line.find(';'));
            line = line.substr(line.find(';')+1);
            work_time = std::stoi(line.substr(0, line.find(';')));
            line = line.substr(line.find(';')+1);
            pos = line.substr(0, line.find(';'));
            position = em->getPositionAsEnum(pos);
            line = line.substr(line.find(';')+1);
            salary = std::stoi(line.substr(0, line.find(';')));
            line = line.substr(line.find(';')+1);
            Project* project = getByName(projects, line);
            std::vector<Project*> ps = {project};
            workers.push_back(
                    makeWorker(worker_id, worker_name, work_time, salary, position, ps));
        }
    }
    return workers;
}
