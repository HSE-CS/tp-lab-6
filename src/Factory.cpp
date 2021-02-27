// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 08.02.2021.
//
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Factory.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

std::vector<Employee*> StaffFactory::make_staff(const std::string& file) {
  std::vector<Employee*> res;
  std::ifstream in(file);

  if (in.is_open()) {
    while (!in.eof()) {
      std::string buf;
      std::getline(in, buf, '\n');

      std::stringstream ss(buf);
      id_type id;
      std::string position, name;
      ss >> id;
      ss >> position;
      for (int i = 0; i < 3; ++i) {
        std::string b;
        ss >> b;
        name += b += ' ';
      }

      if (position == "Cleaner") {
        unsigned int sal;
        ss >> sal;
        res.push_back(new Cleaner(id, name, sal));

      } else if (position == "Driver") {
        unsigned int sal;
        ss >> sal;
        res.push_back(new Driver(id, name, sal));

      } else if (position == "Tester") {
        unsigned int sal;
        std::string project;
        ss >> sal;
        ss >> project;
        res.push_back(new Tester(id, name, sal,
                         Project{project, 200000}));

      } else if (position == "Programmer") {
        unsigned int sal;
        std::string project;
        ss >> sal;
        ss >> project;
        res.push_back(new Programmer(id, name, sal,
                         Project{project, 200000}));

      } else if (position == "TeamLeader") {
        unsigned int sal;
        std::string project;
        ss >> sal;
        ss >> project;
        res.push_back(new TeamLeader(id, name, sal,
                         Project{project, 200000}));

      } else if (position == "PM") {
        std::string project;
        ss >> project;
        res.push_back(new ProjectManager(id, name,
                         Project{project, 200000}));

      } else if (position == "SM") {
        std::vector<Project> projects;
        std::string project;
        while (!ss.eof()) {
          ss >> project;
          projects.emplace_back(Project{project, 200000});
        }
        res.push_back(new SeniorManager(id, name, projects));
      }
    }

    in.close();
  }

  return res;
}

