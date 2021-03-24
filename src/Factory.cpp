// Copyright 2021 Stifeev Nikita

#include "Factory.h"
#include <fstream>
#include <sstream>
#include <string>


std::vector<Employee*> Factory::makeStaff(std::string fileName) {
    std::vector<Employee*> staff;
    std::ifstream in(fileName);
    if (in) {
        std::string line = "";
        std::vector<Project*> projects;
        getline(in, line);
        while (line.compare("SENIOR MANAGERS") != 0) {
            std::string id; int budget;
            std::istringstream iss(line);
            iss >> id >> budget;
            projects.push_back(new Project(id, budget));
            getline(in, line);
        }
        getline(in, line);
        while (line.compare("PROJECT MANAGERS") != 0) {
            int id; std::string name, token, proj_line;
            std::istringstream iss(line);
            getline(iss, token, ';');
            id = stoi(token);
            getline(iss, token, ';');
            name = token;
            Employee* sm = new SeniorManager(id, name);
            getline(in, proj_line);
            std::istringstream iss_proj(proj_line);
            while (getline(iss_proj, token, ';')) {
                for (Project* p : projects) {
                    if (p->getId().compare(token) == 0) {
                        reinterpret_cast<SeniorManager*>(sm)->
                            getProjects()->push_back(p);
                        break;
                    }
                }
            }
            staff.push_back(sm);
            getline(in, line);
        }
        getline(in, line);
        while (line.compare("TEAMLEADERS") != 0) {
            int id; std::string name, token;
            std::istringstream iss(line);
            getline(iss, token, ';');
            id = stoi(token);
            getline(iss, token, ';');
            name = token;
            Employee* pm = new ProjectManager(id, name);
            getline(in, token);
            for (Project* p : projects) {
                if (p->getId().compare(token) == 0) {
                    reinterpret_cast<ProjectManager*>(pm)->
                        getProjects()->push_back(p);
                    break;
                }
            }
            staff.push_back(pm);
            getline(in, line);
        }
        getline(in, line);
        while (line.compare("PROGRAMMERS") != 0) {
            int id, salary; std::string name, token;
            std::istringstream iss(line);
            getline(iss, token, ';');
            id = stoi(token);
            getline(iss, token, ';');
            name = token;
            getline(iss, token, ';');
            salary = stoi(token);
            getline(in, token);
            Project* pr = NULL;
            for (Project* p : projects) {
                if (p->getId().compare(token) == 0) {
                    pr = p;
                    break;
                }
            }
            Employee* tl = new TeamLeader(id, name, salary, pr);
            staff.push_back(tl);
            getline(in, line);
        }
        getline(in, line);
        while (line.compare("TESTERS") != 0) {
            int id, salary; std::string name, token;
            std::istringstream iss(line);
            getline(iss, token, ';');
            id = stoi(token);
            getline(iss, token, ';');
            name = token;
            getline(iss, token, ';');
            salary = stoi(token);
            getline(in, token);
            Project* pr = NULL;
            for (Project* p : projects) {
                if (p->getId().compare(token) == 0) {
                    pr = p;
                    break;
                }
            }
            Employee* programmer = new Programmer(id, name, salary, pr);
            staff.push_back(programmer);
            getline(in, line);
        }
        getline(in, line);
        while (line.compare("DRIVERS") != 0) {
            int id, salary; std::string name, token;
            std::istringstream iss(line);
            getline(iss, token, ';');
            id = stoi(token);
            getline(iss, token, ';');
            name = token;
            getline(iss, token, ';');
            salary = stoi(token);
            getline(in, token);
            Project* pr = NULL;
            for (Project* p : projects) {
                if (p->getId().compare(token) == 0) {
                    pr = p;
                    break;
                }
            }
            Employee* tester = new Tester(id, name, salary, pr);
            staff.push_back(tester);
            getline(in, line);
        }
        getline(in, line);
        while (line.compare("CLEANERS") != 0) {
            int id, salary; std::string name, token;
            std::istringstream iss(line);
            getline(iss, token, ';');
            id = stoi(token);
            getline(iss, token, ';');
            name = token;
            getline(iss, token, ';');
            salary = stoi(token);
            Employee* driver = new Driver(id, name, salary);
            staff.push_back(driver);
            getline(in, line);
        }
        getline(in, line);
        while (getline(in, line)) {
            int id, salary; std::string name, token;
            std::istringstream iss(line);
            getline(iss, token, ';');
            id = stoi(token);
            getline(iss, token, ';');
            name = token;
            getline(iss, token, ';');
            salary = stoi(token);
            Employee* cleaner = new Cleaner(id, name, salary);
            staff.push_back(cleaner);
            getline(in, line);
        }
        in.close();
    }
    return staff;
}
