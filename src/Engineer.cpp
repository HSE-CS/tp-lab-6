#include "Engineer.h"
#include <random>

int Engineer::calcBudjetPart(float part, int budjet) {
 return part * budjet;
}

void Engineer::calc() {
 this->payment = calcBudjetPart(project->budjet, project->partForEngineers) +
     calcBase(salary, worktime);
}

int Tester::calcProAdditions() {
 return rand() % 3000 + 2000;
}

int Programmer::calcProAdditions() {
 return rand() % 3000 + 2000;
}

int TeamLeader::calcHeads() {
 return 120000;
}

void TeamLeader::calc() {
    this->payment = this->calcBase(salary, worktime) +
        this->calcBudjetPart(project->budjet, project->partForEngineers)
        + this->calcHeads();
}

void Engineer::printinfo() {
    std::cout << this->id << "." << this->name << "\n"
        "position: " << "\t" << this->position << "\n"
        "projectID: " << "\t" << this->project->id << "\n"
        "salary: " << "\t" << this->salary << "\n"
        "worktime: " << "\t" << this->worktime << "\n"
        "payment: " << "\t" << this->payment << "\n" << std::endl;
}

int Engineer::calcBonus() {
    return rand() % 3000 + 2000;
}

int Engineer::calcProAdditions() {
    return rand() % 3000 + 2000;
}
