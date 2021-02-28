// Copyright 2021 Galex

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/Manager.h"
#include "../include/Personal.h"
#include "../include/Project.h"
#include "../include/Engineer.h"
#include "../include/Factory.h"

void Factory::runFactory() {
  std::vector<Project *> projects;
  std::vector<Employee *> personal;
  projects.push_back(new Project(1, 3000000));

  std::fstream staffList;
  staffList.open(R"(../../data/staff.txt)");
  std::string input;
  std::getline(staffList, input);
  int numOfStaff = std::stoi(input);
  for (int i = 0; i < numOfStaff; ++i) {
    std::getline(staffList, input);
    std::string tmp;
    std::stringstream ss(input);
    std::vector<std::string> words;
    while (getline(ss, tmp, ' ')) {
      words.push_back(tmp);
    }
    if (words[0] == "cleaner") {
      personal.push_back(new Cleaner(i,
                                     words[1] + " " + words[2] + " " + words[3],
                                     std::stoi(words[4])));
    } else if (words[0] == "driver") {
      personal.push_back(new Driver(i,
                                    words[1] + " " + words[2] + " " + words[3],
                                    std::stoi(words[4])));
    } else if (words[0] == "programmer") {
      personal.push_back(new Programmer(i,
                                        words[1] + " " +
                                            words[2] + " " + words[3],
                                        std::stoi(words[4]),
                                        projects[std::stoi(words[5])]));
    } else if (words[0] == "tester") {
      personal.push_back(new Tester(i,
                                    words[1] + " " + words[2] + " " + words[3],
                                    std::stoi(words[4]),
                                    projects[std::stoi(words[5])]));
    } else if (words[0] == "team_leader") {
      personal.push_back(new TeamLeader(i,
                                        words[1] + " " +
                                            words[2] + " " + words[3],
                                        std::stoi(words[4]),
                                        projects[std::stoi(words[5])]));
    } else if (words[0] == "project_manager") {
      std::vector<Project *> project;
      project.push_back(projects[std::stoi(words[4])]);
      personal.push_back(new ProjectManager(i,
                                            words[1] + " " +
                                            words[2] + " "+
                                            words[3], project));
    } else if (words[0] == "senior_manager") {
      std::vector<Project *> project;
      int numOfProjects = std::stoi(words[4]);
      for (int j = 0; j < numOfProjects; ++j) {
        project.push_back(projects[std::stoi(words[5 + j])]);
      }
      personal.push_back(new SeniorManager(i,
                                           words[1] + " " +
                                           words[2] + " " + words[3], project));
    }
  }
  staffList.close();
  for (int i = 0; i < personal.size(); ++i) {
    if (personal[i]->getPosition() < 5) {
      personal[i]->setWorkTime(45);
    }
    personal[i]->calc();
    personal[i]->printInfo();
  }
}
