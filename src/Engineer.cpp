// Copyright 2021 Kris

#include "Engineer.h"

Engineer::Engineer(int _id, std::string _name, std::string _pos, int _payment, Project currentProject): Personal(_id, _name, _pos, _payment) {
    project = currentProject;
}

Programmer::Programmer(int _id, std::string _name, std::string _pos, int _payment, Project currentProject) : Engineer(_id, _name, _pos, _payment, currentProject) {
    
}

TeamLeader::TeamLeader(int _id, std::string _name, std::string _pos, int _payment, Project currentProject) : Programmer(_id, _name, _pos, _payment, currentProject) {

}
Tester::Tester(int _id, std::string _name, std::string _pos, int _payment, Project currentProject) : Engineer(_id, _name, _pos, _payment, currentProject) {

}

int Engineer::calcBudgetPart(double part, int budget) {
    return int(part * budget);
}

Project Engineer::getProject() {
    return project;
}

int Engineer::calc() {
    setsalary(calcBase() + calcProAdditions());
    return getsalary();
}

int Engineer::calcProAdditions() {
    return calcBudgetPart(0.15, project.getBudget());
}

int Programmer::calcProAdditions() {
    return calcBudgetPart(0.05, getProject().getBudget());
}

int Tester::calcProAdditions() {
    return calcBudgetPart(0.02, getProject().getBudget());
}

int TeamLeader::calcHeads() {
    return calcBudgetPart(0.2, getProject().getBudget());
}
int TeamLeader::calc() {
    setsalary(calcBase() + calcHeads() + calcProAdditions());
    return getsalary();
}