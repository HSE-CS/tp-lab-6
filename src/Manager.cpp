#include "Manager.h"

ProjectManager::ProjectManager(unsigned int id,
                               std::string name,
                               Position position,
                               unsigned int worktime,
                               unsigned int payment,
                               std::vector<std::shared_ptr<Project>>& projects)
    : Employee(id, name, position, worktime, payment)
    , projects(projects) {

}

int ProjectManager::calcHeads() {
    return 100;  // there is no instruction, so just 100
}

void ProjectManager::calc() {
    this->payment = (this->projects.size() > 0 ?
                    this->projects[0]->budget * 0.05 : 0) +
                    calcHeads();
}

void ProjectManager::printInfo() {
    std::cout << "ProjectManager info";
}

SeniorManager::SeniorManager(unsigned int id,
    std::string name,
    unsigned int worktime,
    unsigned int payment,
    std::vector<std::shared_ptr<Project>>& projects)
    : ProjectManager(id,
                    name,
                    Position::SeniorManager,
                    worktime,
                    payment,
                    projects) {

}

void SeniorManager::calc() {
    for (auto it = this->projects.begin(); it != this->projects.end(); ++it) {
        this->payment += (*it)->budget * 0.05;
    }
    this->payment += this->projects.size() * calcHeads();
}

void SeniorManager::printInfo() {
    std::cout << "SeniorManager info:\n";
}
