#include <fstream>
#include <cmath>
#include <string>
#include "Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"
#include "Interfaces.h"

int id = 1;

bool SettingProject(Employee* emp, std::vector<Project*> Projects, Project* proj) {
 if (emp->getPosition() == "ProjectManager") {
  dynamic_cast<ProjectManager*>(emp)->setProject(Projects);
  return true;
 }
 else if ((emp->getPosition() == "SeniorManager")&&(dynamic_cast<SeniorManager*>(emp)->getProject()->id == 0)) {
  dynamic_cast<SeniorManager*>(emp)->setProject(proj);
  return true;
 }
 else if ((emp->getPosition() == "Engineer") && (dynamic_cast<Engineer*>(emp)->getProject()->id == 0)) {
  dynamic_cast<Engineer*>(emp)->setProject(proj);
  return true;
 }
 return false;
}

int StringToInt(std::string buf) {
 int a = atoi(buf.c_str());
 return a;
}

void makeStaffForProject(Resource* a, std::vector<Project*> Projects, std::vector<Employee*> Staff) {
    std::ifstream fin((*a).readpath);
    std::string buf;
    std::getline(fin, buf);
    Project projectbuf(0, 0);
    while (!fin.eof()) {
        int i = 0;
        while ((buf[buf.length() - i - 1] >= '0') && (buf[buf.length() - i - 1] <= '9')) {
            ++i;
        }
        projectbuf.id = StringToInt(buf.substr(buf.length() - i, buf.length() - 1));
        i = 0;
        std::getline(fin, buf);
        while ((buf[buf.length() - i - 1] >= '0') && (buf[buf.length() - i - 1] <= '9')) {
            ++i;
        }
        bool flag = 0;
        projectbuf.budjet = StringToInt(buf.substr(buf.length() - i, buf.length() - 1));
        Project* proj = new Project(projectbuf);
        std::getline(fin, buf);
        Projects.push_back(proj);
        std::getline(fin, buf);
        while ((buf.length()) && (!fin.eof())) {
            for (Employee* emp : Staff) {
                if (buf == emp->getPosition()) {
                    if (SettingProject(emp, Projects, proj))
                        break;
                }
            }
            std::getline(fin, buf);
        }
        if (fin.eof())
            break;
        std::getline(fin, buf);
    }
}


std::vector<Employee*> makeStaff(Resource* a) {
    std::vector<Employee*> Staff;
    std::ifstream fin((*a).readpath);
    std::string buf;
    std::getline(fin, buf);
    FactorySalaries salaries;
    std::getline(fin, buf);
    while (buf.length()) {
        if (buf == "Engineer") {
            std::getline(fin, buf);
            salaries.Engineer = StringToInt(buf);
        }
        else if (buf == "Programmer") {
            std::getline(fin, buf);
            salaries.Programmer = StringToInt(buf);
        }
        else if (buf == "Tester") {
            std::getline(fin, buf);
            salaries.Tester = StringToInt(buf);
        }
        else if (buf == "TeamLeader") {
            std::getline(fin, buf);
            salaries.TeamLeader = StringToInt(buf);
        }
        else if (buf == "Driver") {
            std::getline(fin, buf);
            salaries.Driver = StringToInt(buf);
        }
        else {
            std::getline(fin, buf);
            salaries.Cleaner = StringToInt(buf);
        }
        std::getline(fin, buf);
    }
    std::string name;
    std::string pos;
    Project* emptyproject = new Project(0, 0);
    std::vector<Project*> emptyVectorProject;
    while (!fin.eof()) {
        Employee* newEmp;
        std::getline(fin, pos);
        std::getline(fin, name);
        if (pos == "ProjectManager") {
            newEmp = new ProjectManager(emptyVectorProject, id, pos, name, 0, 0);
        }
        else if (pos == "SeniorManager") {
            newEmp = new SeniorManager(emptyproject, emptyVectorProject, id, pos, name, 0, 0);
        }
        else if (pos == "Engineer") {
            newEmp = new Engineer(emptyproject, id, pos, name, 0, 0, salaries.Engineer);
        }
        else if (pos == "Programmer") {
            newEmp = new Programmer(emptyproject, id, pos, name, 0, 0, salaries.Programmer);
        }
        else if (pos == "Tester") {
            newEmp = new Tester(emptyproject, id, pos, name, 0, 0, salaries.Tester);
        }
        else if (pos == "TeamLeader") {
            newEmp = new TeamLeader(emptyproject, id, pos, name, 0, 0, salaries.TeamLeader);
        }
        else if (pos == "Driver") {
            newEmp = new Driver(id, pos, name, 0, 0, salaries.Driver);
        }
        else if (pos == "Cleaner") {
            newEmp = new Cleaner(id, pos, name, 0, 0, salaries.Cleaner);
        }
        Staff.push_back(newEmp);
        ++id;
    }
    return Staff;
}