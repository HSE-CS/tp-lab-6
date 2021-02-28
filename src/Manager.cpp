// copyright 2021 Toliman

#include "../include/Manager.h"

#include <utility>

int ProjectManager::calcHeads() {
    int result = 0;
    for (Employee *worker : this->projectWorkers) {
        if (worker->getProject() == this->project) {
            result++;
        }
    }
    return result;
}

void ProjectManager::calc(int emp) {
    this->payment += this->employees * 1000;
}

ProjectManager::ProjectManager(std::string name1,
                               int worktime1,
                               Project *project1,
                               int position1,
                               std::vector<Employee *>
                                   projectWorkers1) : Employee(
                                       std::move(name1),
                                       worktime1, project1,
                                       position1) {
    this->projectWorkers = std::move(projectWorkers1);
    this->employees = this->projectWorkers.size();
    std::vector<Project *> p;
    p.push_back(project1);
    this->projects = std::move(p);
}

void ProjectManager::printInfo() {
    toStringForm(this->name,
        this->id,
        this->position,
        this->project);
}

void ProjectManager::setProjectWorkersVector(
    std::vector<Employee *> projectWorkers1) {
    this->projectWorkers = std::move(projectWorkers1);
}

int SeniorManager::calcHeads() {
    int result = 0;
    for (Project *p : this->projects) {
        result += p->getWorkersCount();
    }
    return result;
}

void SeniorManager::calc() {
    this->payment += this->calcHeads() * 1000;
}

SeniorManager::SeniorManager(std::string name1,
                             int worktime1,
                             Project *project1,
                             int position1,
                             std::vector<Employee *> workers1) :
                             ProjectManager(
                                 std::move(name1), worktime1,
                                 project1, position1,
                                 std::move(workers1)) {
    this->workers = &workers1;
}

void SeniorManager::printInfo() {
    ProjectManager::printInfo();
}

int TeamLeader::calcProgrammers() {
    int result = 0;
    for (Employee *worker : *(this->workers)) {
        if (worker->getPosition() == PROGRAMMER) {
            result++;
        }
    }
    return result;
}

int TeamLeader::calcHeads() {
    return this->calcProgrammers();
}

void TeamLeader::calc() {
    this->payment += this->calcHeads() * 1000;
}

TeamLeader::TeamLeader(std::string name1,
                       int worktime1,
                       Project *project1,
                       int position1,
                       int salary1,
                       std::vector<Employee *> *workers) :
                       Programmer(std::move(name1),
                           worktime1,
                           project1,
                           position1,
                           salary1) {
    this->workers = workers;
}

void TeamLeader::printInfo() {
    Programmer::printInfo();
}

void TeamLeader::setWorkersVector(std::vector<Employee *> *workers1) {
    this->workers = workers1;
}
