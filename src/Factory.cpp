//// Copyright 2021 Ozhiganova Polina
#include "Factory.h"

Project *getProj(const std::string &projName,
                 const std::vector<Project *>
                 &projects) {
  for (auto &proj : projects) {
    if (proj->id == projName) {
      return proj;
    }
  }
  return nullptr;
}

std::vector<Employee *> Factory::makeStaff(const json &file) {
  std::vector<Project *> projects;
  std::vector<Employee *> employees;
  for (auto &[key, value] : file.items()) {
    if (key == "PROJECTS") {
      for (auto &proj : value) {
        std::string id = proj["id"];
        int budget = proj["budget"];
        Project *project = new Project(id, budget);
        projects.push_back(project);
      }
    } else if (key == "STUFF") {
      for (auto &stuff : value) {
        Employee *employee;
        Project *proj;
        int id = stuff["id"];
        std::string name = stuff["name_surname"];
        std::string pos = stuff["position"];
        if (pos == "cleaner") {
          int payment = stuff["payment"];
          employee = new Cleaner(id, name, pos, payment);
        } else if (pos == "driver") {
          int payment = stuff["payment"];
          employee = new Driver(id, name, pos, payment);
        } else if (pos == "tester") {
          std::string projName = stuff["project"];
          proj = getProj(projName, projects);
          int mistakes = stuff["mistakes"];
          int payment = stuff["payment"];
          employee = new Tester(id, name, pos, payment, proj, mistakes);
        } else if (pos == "programmer") {
          std::string projName = stuff["project"];
          proj = getProj(projName, projects);
          int payment = stuff["payment"];
          employee = new Programmer(id, name, pos, payment, proj);
        } else if (pos == "team leader") {
          std::string projName = stuff["project"];
          proj = getProj(projName, projects);
          int payment = stuff["payment"];
          employee = new TeamLeader(id, name, pos, payment, proj);
        } else if (pos == "project manager") {
          std::string projName = stuff["project"];
          proj = getProj(projName, projects);
          employee = new ProjManager(id, name, pos, proj);
        } else if (pos == "senior manager") {
          employee = new SeniorManager(id, name, pos, projects);
        }
        employees.push_back(employee);
      }
    }
  }
  return employees;
}
