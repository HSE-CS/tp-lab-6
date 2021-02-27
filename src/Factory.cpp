// Copyright 2021 Andrey Bakurskii

#include "Factory.h"

Factory::Factory(std::string path2projects, std::string path2employees) {
  this->path2projects = path2projects;
  this->path2employees = path2employees;
}

void Factory::makeStaff() {
  std::ifstream file(this->path2employees);
  std::string line;
  if (file.is_open()) {
    while (getline(file, line)) {
      std::stringstream info(line);
      std::string name, position;
      int id, payment, worktime, id_project;
      info >> id >> name >> position;

      if (position == "Personal" || position == "Cleaner" ||
          position == "Driver") {
        info >> worktime >> payment;

        if (position == "Personal") {
          Emploeey* employee =
              new Personal(id, name, position, worktime, payment);
          this->employees.push_back(employee);
          continue;
        }

        if (position == "Cleaner") {
          Emploeey* employee =
              new Cleaner(id, name, position, worktime, payment);
          this->employees.push_back(employee);
          continue;
        }

        if (position == "Driver") {
          Emploeey* employee =
              new Driver(id, name, position, worktime, payment);
          this->employees.push_back(employee);
          continue;
        }
      }

      if (position == "Programmer" || position == "Tester" ||
          position == "Engineer" || position == "TeamLeader") {
        info >> worktime >> payment >> id_project;
        Project* project = getProject(id_project);
        if (project) {
          if (position == "Engineer") {
            Emploeey* employee =
                new Engineer(id, name, position, worktime, payment, project);
            this->employees.push_back(employee);
            continue;
          }

          if (position == "Programmer") {
            Emploeey* employee =
                new Programmer(id, name, position, worktime, payment, project);
            this->employees.push_back(employee);
            continue;
          }

          if (position == "Tester") {
            Emploeey* employee =
                new Tester(id, name, position, worktime, payment, project);
            this->employees.push_back(employee);
            continue;
          }

          if (position == "TeamLeader") {
            Emploeey* employee =
                new TeamLeader(id, name, position, worktime, payment, project);
            this->employees.push_back(employee);
            continue;
          }
        } else {
          continue;
        }
      }
      if (position == "ProjectManager" || position == "SeniorManager") {
        if (position == "ProjectManager") {
          int amount_projects;
          std::vector<Project*> projects_manager;
          info >> worktime >> payment >> amount_projects;
          for (int i = 0; i < amount_projects; i++) {
            info >> id_project;
            Project* project = getProject(id_project);
            if (project) {
              projects_manager.push_back(project);
            } else {
              continue;
            }
          }
          Emploeey* employee = new ProjectManager(
              id, name, position, worktime, payment, projects_manager);
          this->employees.push_back(employee);
          continue;
        }

        if (position == "SeniorManager") {
          int amount_projects;
          std::vector<Project*> projects_manager;
          info >> worktime >> payment >> amount_projects;
          for (int i = 0; i < amount_projects; i++) {
            info >> id_project;
            Project* project = getProject(id_project);
            if (project) {
              projects_manager.push_back(project);
            } else {
              continue;
            }
          }

          info >> id_project;
          Project* project = getProject(id_project);
          if (project) {
            Emploeey* employee =
                new SeniorManager(id, name, position, worktime, payment,
                                  projects_manager, id_project);
            this->employees.push_back(employee);
            continue;
          } else {
            continue;
          }
        }
      }
    }
  }
}

void Factory::makeProjects() {
  std::ifstream file(this->path2projects);
  std::string line;

  if (file.is_open()) {
    while (getline(file, line)) {
      std::stringstream info(line);
      int id_project, budget;
      info >> id_project >> budget;
      this->projects.push_back(new Project(id_project, budget));
    }
  }
}

Project* Factory::getProject(int id_project) {
  for (size_t i = 0; i < this->projects.size(); i++) {
    if (this->projects[i]->id == id_project) {
      return this->projects[i];
    }
  }
  return nullptr;
}
