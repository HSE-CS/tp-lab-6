// Copyright 2021 Dev-will-work
#include "Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"
#include <fstream>
#include <set>
#include <map>
#include <utility>

class BadGroupSize {};

bool operator<(const Project& a, const Project& b ) {
  if (a.budget < b.budget) return true;
  else
    return false;
}

void addToEmployerGroup(std::map<uint64_t, std::map<std::string, size_t>>* map,
  uint64_t project_id, const std::string& specialty) {
  auto projectPtr = map->find(project_id);
  if (projectPtr != map->end()) {
    auto specialtyPtr = projectPtr->second.find(specialty);
    if (specialtyPtr != projectPtr->second.end()) {
      specialtyPtr->second++;
    } else {
      projectPtr->second.insert(std::make_pair(specialty, 1));
    }
  } else {
    std::map<std::string, size_t> cc;
    cc.insert(std::make_pair(specialty, 1));
    map->insert(std::make_pair(project_id, cc));
  }
}

bool isFreePosition(
  const std::map<uint64_t, std::map<std::string, size_t>>& map,
  uint64_t project_id, const std::string& specialty, size_t count) {
  auto projectPtr = map.find(project_id);
  if (projectPtr != map.end()) {
    auto specialtyPtr = projectPtr->second.find(specialty);
    if (specialtyPtr != projectPtr->second.end()) {
      if (specialtyPtr->second < count) return true;
      else
        return false;
    } else {
      return true;
    }
  } else {
    return true;
  }
}

void addToProject(std::map<uint64_t, size_t>* map, uint64_t project_id) {
  auto projectPtr = map->find(project_id);
  if (projectPtr != map->end()) projectPtr->second++;
  else
    map->insert(std::make_pair(project_id, 1));
}

std::vector<Employee*> StaffFactory::makeStaff() {
  std::vector<Employee*> employees;
  std::vector<Employee*> leads;
  std::ifstream fin(this->filename);
  std::string specialty, fio;
  std::string name, surname, patronymic;
  int salary;
  uint64_t project_id = 0;
  int budget = 0;
  int group_size = 0;
  std::set<Project> projects;
  std::map<uint64_t, size_t> members_group;
  std::map<uint64_t, std::map<std::string, size_t>> projectsAndSpecs;
  size_t all_members = 0;
  size_t limit_positions = 0;
  bool is_senior = false;
  std::string senior_fio;
  int file_line = 1;

  while (fin >> specialty >> group_size) {
    if (group_size <= 0) {
      std::cerr << "Bad group size \"" << group_size <<
        "\" in input file on the string " << file_line << "!\n";
      return employees;
    }
    file_line++;
    for (size_t i = 0; i < group_size; i++) {
      fin >> name >> surname >> patronymic;
      fio = name + ' ' + surname + ' ' + patronymic;
      Employee* c;
      if (specialty == "C" || specialty == "D" || specialty == "P" ||
        specialty == "T" || specialty == "TL" ) {
        fin >> salary;
        if (specialty == "C") {
          c = new Cleaner(salary, fio, Position::CLEANER);
        } else if (specialty == "D") {
          c = new Driver(salary, fio, Position::DRIVER);
        } else if (specialty == "P" || specialty == "T" || specialty == "TL") {
          fin >> project_id >> budget;
          if (specialty == "TL") {
            limit_positions = 1;
          } else {
            limit_positions = 5;
          }
          if (isFreePosition(projectsAndSpecs, project_id,
              specialty, limit_positions)) {
            Project proj{project_id, budget};
            addToEmployerGroup(&projectsAndSpecs, project_id, specialty);
            addToProject(&members_group, project_id);
            all_members++;
            projects.insert(proj);
            if (specialty == "P") {
              c = new Programmer(proj, salary, fio, Position::PROGRAMMER);
            } else if (specialty == "T") {
              c = new Tester(proj, salary, fio, Position::TESTER);
            } else if (specialty == "TL") {
              c = new TeamLeader(proj, salary, fio, Position::TEAMLEADER);
              leads.push_back(c);
            }
          } else {
            std::cerr << "There are not free " << specialty << " positions!\n";
            continue;
          }
        }
      } else if (specialty == "PM") {
        fin >> project_id >> budget;
        if (isFreePosition(projectsAndSpecs, project_id, specialty, 1)) {
          Project* proj = new Project{project_id, budget};
          addToEmployerGroup(&projectsAndSpecs, project_id, specialty);
          all_members++;
          projects.insert(*proj);
          c = new ProjectManager(proj, fio, Position::PROJECT_MANAGER);
          leads.push_back(c);
        } else {
          std::cerr << "There are not free PM positions!\n";
          continue;
        }
      } else if (specialty == "SM") {
        if (!is_senior) {
          senior_fio = fio;
          is_senior = true;
          continue;
        } else {
          std::cerr << "There are not free SM positions!\n";
          continue;
        }
      } else {
        std::cerr << "Unknown specialty: " << specialty << " on line " <<
          file_line << "!\n";
        return employees;
      }
      employees.push_back(c);
      file_line++;
    }
  }
  fin.close();
  if (is_senior) {
    int index = 0;
    Project* all_projects = new Project[projects.size()]{0};
    for (auto project = projects.begin(); project != projects.end();
      ++project) {
      all_projects[index++] = *project;
    }
    Employee* c = new SeniorManager(all_projects, senior_fio,
      Position::SENIOR_MANAGER, projects.size());
    leads.push_back(c);
    employees.push_back(c);
  }
  for (size_t i = 0; i < leads.size(); i++) {
    if (leads[i]->getPosition() == Position::PROJECT_MANAGER) {
      leads[i]->setSubordCount(members_group.at(
        dynamic_cast<ProjectManager*>(leads[i])->getProject()->id));
    } else if (leads[i]->getPosition() == Position::SENIOR_MANAGER) {
      leads[i]->setSubordCount(all_members);
    } else if (leads[i]->getPosition() == Position::TEAMLEADER) {
      leads[i]->setSubordCount(projectsAndSpecs.at(
        dynamic_cast<TeamLeader*>(leads[i])->getProject().id).at("P"));
    }
  }
  return employees;
}

StaffFactory::StaffFactory(std::string filename, FileFormat format) {
  this->filename = filename;
  this->format = format;
}

StaffFactory::~StaffFactory() {
}
