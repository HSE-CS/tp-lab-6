// Copyright 2021 BekusovMikhail

#include <iostream>
#include "Factory.h"

std::vector<Employee *> Factory::makeStaff() {
    std::vector<Employee *> workers;
    std::string ln;
    std::ifstream input(R"(C:\Users\1314135\CLionProjects\KPO-lab6\emp.txt)");
    if (input.is_open()) {
        while (getline(input, ln)) {
            std::string id, na, po, wt, sa;
            int i = 0;
            while (ln[i] != ':' && ln[i] != ';') {
                id.push_back(ln[i]);
                ++i;
            }
            ++i;
            while (ln[i] != ':' && ln[i] != ';') {
                na.push_back(ln[i]);
                ++i;
            }
            ++i;
            while (ln[i] != ':' && ln[i] != ';') {
                po.push_back(ln[i]);
                ++i;
            }
            ++i;
            if ("Programmer" == po) {
                while (ln[i] != ':' && ln[i] != ';') {
                    sa.push_back(ln[i]);
                    ++i;
                }
                ++i;
                std::string proj;
                while (ln[i] != ':' && ln[i] != ';') {
                    proj.push_back(ln[i]);
                    ++i;
                }
                workers.push_back(new Programmer(id, na, PROG, std::stoi(sa),
                                                 new Project(proj, 250000)));
            } else if ("ProjectManager" == po) {
                std::string proj;
                std::vector<Project *> projs;
                while (ln[i] != ':' && ln[i] != ';') {
                    proj.push_back(ln[i]);
                    ++i;
                }
                projs.push_back(new Project(proj, 250000));
                workers.push_back(new ProjectManager(id, na, PRMA, projs));
            } else if ("SeniorManager" == po) {
                std::vector<Project *> projs;
                while (ln[i + 1] != ';') {
                    std::string proj;
                    while (ln[i] != ':') {
                        proj.push_back(ln[i]);
                        ++i;
                    }
                    i += 2;
                    projs.push_back(new Project(proj, 250000));
                }
                workers.push_back(new SeniorManager(id, na, SEMA, projs));
            } else if ("TeamLeader" == po) {
                while (ln[i] != ':' && ln[i] != ';') {
                    sa.push_back(ln[i]);
                    ++i;
                }
                ++i;
                std::string proj;
                while (ln[i] != ':' && ln[i] != ';') {
                    proj.push_back(ln[i]);
                    ++i;
                }
                workers.push_back(new TeamLeader(id, na, TELE, std::stoi(sa),
                                                 new Project(proj, 250000)));
            } else if ("Tester" == po) {
                while (ln[i] != ':' && ln[i] != ';') {
                    sa.push_back(ln[i]);
                    ++i;
                }
                ++i;
                std::string proj;
                while (ln[i] != ':' && ln[i] != ';') {
                    proj.push_back(ln[i]);
                    ++i;
                }
                workers.push_back(new Tester(id, na, TEST, std::stoi(sa),
                                             new Project(proj, 250000)));
            } else if ("Driver" == po) {
                while (ln[i] != ':' && ln[i] != ';') {
                    sa.push_back(ln[i]);
                    ++i;
                }
                workers.push_back(new Driver(id, na, DRIV, std::stoi(sa)));
            } else if ("Cleaner" == po) {
                while (ln[i] != ':' && ln[i] != ';') {
                    sa.push_back(ln[i]);
                    ++i;
                }
                workers.push_back(new Cleaner(id, na, CLEA, std::stoi(sa)));
            }
        }
    } else {
        std::cout << "Cannot open file" << std::endl;
    }
    input.close();
    return workers;
}


