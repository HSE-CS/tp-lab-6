// Copyright 2021 Artyom Lavrov


#include <Manager.h>


int ProjectManager::calcHeads() {
    this->payment += 30000;
    return 30000;
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * budget);
}

int ProjectManager::calcProAdditions() {
    return 0;
}

void ProjectManager::calc() {
    this->payment = ProjectManager
        ::calcBudgetPart(0.2f,
            this->projects[0]->GetBudget());
}

ProjectManager::ProjectManager(std::string id,
    std::string name,
    POSITION position,
    std::vector<Project*> projects) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->position = position;
    this->projects = projects;
}
void ProjectManager::printInfo() {
}

const std::vector<Project*>& ProjectManager::GetProjects() const {
    return projects;
}

void ProjectManager::SetProjects(const std::vector<Project*>& projects) {
    ProjectManager::projects = projects;
}

void SeniorManager::calc() {
    this->payment = 0;
    for (int i = 0; i < this->projects.size(); ++i) {
        this->payment +=
            ProjectManager::calcBudgetPart(0.2f,
                this->projects[i]->GetBudget());
        ProjectManager::calcHeads();
    }
}

SeniorManager::SeniorManager(std::string id,
    std::string name,
    POSITION position,
    std::vector<Project*> projects)
    : ProjectManager(id, name, position, projects) {
}
