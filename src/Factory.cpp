// Copyright 2021 Stolbov Yaroslav

#include <Factory.h>
#include <fstream>
#include <string>
#include <Personal.h>
#include <Engineer.h>


std::vector<Project> Factory::createProjects() {
    std::vector<Project> projects;
    std::vector<std::string> arguments;
    std::string line;
    std::string word;
    std::ifstream in;
    in.open(R"(C:\Users\stoja\CLionProjects\tp-lab-6\src\listProjects.txt)");
    if (in.is_open()) {
        while (getline(in, line)) {
            int startWord = 0;
            int endWord = 0;
            for (int i = 0; i <= line.size(); i++) {
                if (line[i] == ' ' || i == line.size() - 0) {
                    endWord = i - 1;
                    word = line.substr(startWord, endWord - startWord + 1);
                    arguments.push_back(word);
                    startWord = i + 1;
                }
            }
            Project project = Project(std::stoi(arguments[0]), arguments[1]);
            if (arguments.size() == 3) {
                project.setBudget(std::stol(arguments[2]));
            }
            arguments.clear();
            projects.emplace_back(project);
        }
    }
    in.close();

    return projects;
}

std::vector<Employee *> Factory::createWorkers() {
    std::vector<Employee *> employees;
    std::vector<std::string> arguments;
    std::string line;
    std::string word;
    std::ifstream in;
    in.open(R"(C:\Users\stoja\CLionProjects\tp-lab-6\src\listEmployees.txt)");

    if (in.is_open()) {
        while (getline(in, line)) {
            int startWord = 0;
            int endWord = 0;
            for (int i = 0; i <= line.size(); i++) {
                if (line[i] == ' ' || i == line.size() - 0) {
                    endWord = i - 1;
                    word = line.substr(startWord, endWord - startWord + 1);
                    arguments.push_back(word);
                    startWord = i + 1;
                }
            }
            if (arguments[2] == "driver") {
                Driver driver =
                        Driver(std::stoi(arguments[0]), arguments[1],
                               DRIVER, std::stoi(arguments[3]));
                employees.emplace_back(&driver);
            } else if (arguments[2] == "cleaner") {
                Cleaner cleaner =
                        Cleaner(std::stoi(arguments[0]), arguments[1],
                                CLEANER, std::stoi(arguments[3]));
                employees.emplace_back(&cleaner);
            } else if (arguments[2] == "tester") {
                Tester tester =
                        Tester(std::stoi(arguments[0]), arguments[1],
                               TESTER, std::stoi(arguments[3]));
                employees.emplace_back(&tester);
            } else if (arguments[2] == "programmer") {
                Programmer programmer =
                        Programmer(std::stoi(arguments[0]), arguments[1],
                                   PROGRAMMER,
                                   std::stoi(arguments[3]));
                employees.emplace_back(&programmer);
            } else if (arguments[2] == "lead") {
                TeamLeader teamLeader =
                        TeamLeader(std::stoi(arguments[0]), arguments[1],
                                   TEAM_LEADER,
                                   std::stoi(arguments[3]));
                employees.emplace_back(&teamLeader);
            } else if (arguments[2] == "manager") {
                ProjectManager projectManager =
                        ProjectManager(std::stoi(arguments[0]), arguments[1],
                                       PROJECT_MANAGER);
                employees.emplace_back(&projectManager);
            } else if (arguments[2] == "smanager") {
                SeniorManager seniorManager =
                        SeniorManager(std::stoi(arguments[0]), arguments[1],
                                      SENIOR_MANAGER);
                employees.emplace_back(&seniorManager);
            }
            arguments.clear();
        }
    }
    in.close();

    return employees;
}

