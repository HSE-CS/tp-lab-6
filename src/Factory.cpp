// Copyright [2020] <Olesya Nikolaeva>

#include <stdlib.h>
#include "Factory.h"
#include "Manager.h"
#include "Engineer.h"
#include "Interfaces.h"

void Staff::makeStaff(std::ifstream file) {
    std::string str, id, name, sub, position, salary, project;
    while (getline(file, str)) {
        id = str.substr(0, str.find(" "));
        str.erase(0, str.find(" ") + 1);
        name = str.substr(0, str.find(" "));
        str.erase(0, str.find(" ") + 1);
        position = str.substr(0, str.find(" "));
        str.erase(0, str.find(" ") + 1);
        if (position == "manager" || position == "senior") {
            project = str;
            Project* newproject;
            if (this->findProject(str) == 0) {
                newproject = new Project(project, 100);
                projects.push_back(newproject);
            }
            else
                newproject = this->findProject(str);
            if (position == "manager") {
                staff.push_back(new ProjectManager(id, name, "manager", newproject));
            }
            else {
                staff.push_back(new SeniorManager(id, name, newproject));
            }
        }
        else if (position == "driver" || position == "cleaner") {
            salary = str;
            if (position == "driver") {
                //Driver * lead = new Driver(id, name, atoi(salary.c_str()));
                //lead->printInfo();
                staff.push_back(new Driver(id, name, atoi(salary.c_str())));
            }
            else {
                staff.push_back(new Cleaner(id, name, atoi(salary.c_str())));
            }
        }
        else {
            salary = str.substr(0, str.find(" "));
            str.erase(0, str.find(" ") + 1);
            project = str;
            Project* newproject;
            if (this->findProject(str) == 0) {
                newproject = new Project(project, 100);
                projects.push_back(newproject);
            }
            else
                newproject = this->findProject(str);
            newproject->addPerson();
            if (position == "engineer") {
                staff.push_back(new Engineer(id, name, "engineer", atoi(salary.c_str()), newproject));
            }
            else if (position == "programmer") {
                staff.push_back(new Programmer(id, name, "programmer", atoi(salary.c_str()), newproject));
            }
            else if (position == "tester") {
                staff.push_back(new Tester(id, name, atoi(salary.c_str()), newproject));
            }
            else {
                //TeamLeader * lead = new TeamLeader(id, name, atoi(salary.c_str()), newproject);
                //lead->printInfo();
                staff.push_back(new TeamLeader(id, name, atoi(salary.c_str()), newproject));
            }
        }
    }
}


void Staff::printStaff() {
    for (auto member : this->staff) {
        member->printInfo();
        puts("");
    }
}

void Staff::addTimeToAll(int time) {
    for (auto member : this->staff) {
        member->addWorkTime(time);
    }
}

void Staff::calcAll() {
    for (auto member : this->staff) {
        member->calc();
    }
}

void Staff::addMember(Employee* newmember) {
    staff.push_back(newmember);
}

int Staff::staffNumber() {
    return staff.size();
}

int Staff::projectsNumber() {
    return projects.size();
}

int Staff::returnPayment(std::string ID) {
    for (auto i : this->staff) {
        if (i->returnID() == ID) {
            return i->returnPayment();
        }
    }
    return 0;
}

Employee* Staff::findMember(std::string ID) {
    for (auto i : this->staff) {
        if (i->returnID() == ID) {
            return i;
        }
    }
    return 0;
}

Project* Staff::findProject(std::string name) {
    for (auto i : this->projects) {
        if (i->returnName() == name) {
            return i;
        }
    }
    return 0;
}
