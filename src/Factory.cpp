// Copyright 2021
#include "Factory.h"
#include <string>
#include <sstream>
#include <fstream>
#include "Employee.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Programmer.h"
#include "TeamLeader.h"
#include "Tester.h"
#include "ProjectManager.h"
#include "SeniorManager.h"
#include "Engineer.h" 

void Factory::makeStaff(std::string filename) {
    std::ifstream emp(filename);

    std::string str;

    while(std::getline(emp,str)) {
        int i = 0;
        std::string temp[5];
        std::stringstream stream(str);
        std::string emploee;
        while (std::getline(stream,emploee, ',')) {
            temp[i] = emploee;
            i++;
        }
        int id = std::stoi(temp[0]);
        int salary = 0;
        if (temp[3] != "") {
            salary = std::stoi(temp[3]);
        }
        Project* project = getProject(temp[4]);
        if (temp[2] == "project manager") {
            staff.push_back(new ProjectManager(id, temp[1], temp[2], 
                project));
            project->AddMember();
        }
        else if (temp[2] == "senior manager") {
            staff.push_back(new SeniorManager(id, temp[1], temp[2], projects));
        }
        else if (temp[2] == "programmer") {
            staff.push_back(new Programmer(id, temp[1], temp[2], salary,
                project));
            project->AddMember();
            project->AddProgrammer();
        }
        else if (temp[2] == "tester") {
            staff.push_back(new Tester(id, temp[1], temp[2], salary,
                project));
            project->AddMember();
        }
        else if (temp[2] == "driver") {
            staff.push_back(new Driver(id, temp[1], temp[2], salary));
        }
        else if (temp[2] == "cleaner") {
            staff.push_back(new Cleaner(id, temp[1], temp[2], salary));
        }
        else if (temp[2] == "team leader") {
            staff.push_back(new TeamLeader(id, temp[1], temp[2], salary, project));
            project->AddMember();

        }
    }
}


void Factory::setAllWorkTime() {
    for (int i = 0; i < staff.size(); i++) {
        staff[i]->setWorkTime();
    }
}

void Factory::calcPayment() {
    for (int i = 0; i < staff.size(); i++) {
        staff[i]->calc();
    }
}

void Factory::printAllInfo()
{
    for (int i = 0; i < staff.size(); i++) {
        staff[i]->printInfo();
    }
}

Project* Factory::getProject(std::string name) {
    for (int i = 0; i < projects.size(); i++) {
        if (projects[i]->getName() == name) {
            return projects[i];
        }
    }
    return NULL;
}
