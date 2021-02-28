//
// Created by Данил on 28.02.2021.
//

#include "../include/Engineer.h"

#include <utility>

void Engineer::calc(int hours) {
    this->payment += calcBase(this->salary, hours);
}

int Engineer::calcBudgetPart(float projectPart, int budget) {
    return static_cast<int>(static_cast<float>(budget) * projectPart);
}

Engineer::Engineer(std::string name1, int worktime1, Project *project1,
                   int position1, int salary1) : Personal(std::move(name1),
                                                          worktime1,
                                                          project1,
                                                          position1,
                                                          salary1) {

}

int Programmer::calcProAdditions(int extraCode) {
    return extraCode * this->salary;
}

Programmer::Programmer(std::string name1,
                       int worktime1,
                       Project *project1,
                       int position1,
                       int salary1) : Engineer(std::move(name1),
                                               worktime1,
                                               project1,
                                               position1,
                                               salary1) {

}

void Programmer::printInfo() {
    toStringForm(this->name, this->id, this->position, this->project);
}

void Programmer::calc(int hours) {
    Engineer::calc(hours);
}

void Programmer::calcBonus(int times) {
    this->payment += Personal::calcBase(this->salary, times);
}

int Tester::calcProAdditions(int foundMistakes) {
    return foundMistakes * this->salary;
}

Tester::Tester(std::string name1,
               int worktime1,
               Project *project1,
               int position1,
               int salary1) : Engineer(std::move(name1),
                                       worktime1,
                                       project1,
                                       position1,
                                       salary1) {

}

void Tester::printInfo() {
    toStringForm(this->name, this->id, this->position, this->project);
}

void Tester::calc(int hours) {
    Engineer::calc(hours);
}

void Tester::calcBonus(int times) {
    this->payment += Personal::calcBase(this->salary, times);
}
