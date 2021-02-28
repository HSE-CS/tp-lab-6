// Copyright 2021 me

#include "..\include\Factory.h"

unsigned Project::getProjectID() { return id; }

int Project::getTesters() { return testers.size(); }

int Project::getWorkers() { return workers.size(); }

int Project::getBudget() { return budget; }

void Project::addTester(Engineer* tester) { testers.push_back(tester); }

void Project::addWorker(Engineer* worker) { workers.push_back(worker); }

std::vector<Project*> makeProjects(std::string path) {
  std::vector<Project*> projectsList;
  if (path == "") return projectsList;
  std::ifstream read(path);
  nlohmann::json prList;
  read >> prList;
  auto p = prList.get<std::vector<nlohmann::json>>();
  for (const auto condidate : p) {
    Project* proj = new Project(condidate["id"].get<unsigned>(),
                                condidate["budget"].get<int>());
    projectsList.push_back(proj);
  }
  return projectsList;
}

Project* getProjectByID(std::vector<Project*> projectsList, unsigned id) {
    for (auto pr : projectsList) {
        if (pr->getProjectID() == id) {
           return pr;
        }
    }
    return nullptr;
}

std::vector<Employee*> makeStaff(std::string path,
                                 std::vector<Project*> projectsList) {
  std::vector<Employee*> comp;
  if (path == "") return comp;
  std::ifstream read(path);
  nlohmann::json employeeList;
  read >> employeeList;
  auto emp = employeeList.get<std::vector<nlohmann::json>>();
  for (const auto condidate : emp) {
    switch (condidate["position"].get<unsigned>()) {
      case 1:  // programmer
      {
        Project* pr = getProjectByID(projectsList,
                                     condidate["Project ID"].get<unsigned>());
        Engineer* _employee =
            new Programmer(condidate["id"].get<unsigned>(),
                           condidate["name"].get<std::string>(), Position(1),
                           condidate["salary"].get<int>(), pr);
        _employee->setWorkTime(condidate["Work Time"].get<int>());
        pr->addWorker(_employee);
        comp.push_back(_employee);
      } break;
      case 2:  // tester
      {
        Project* pr = getProjectByID(projectsList,
                                     condidate["Project ID"].get<unsigned>());
        Engineer* _employee =
            new Tester(condidate["id"].get<unsigned>(),
                       condidate["name"].get<std::string>(), Position(2),
                       condidate["salary"].get<int>(), pr);
        _employee->setWorkTime(condidate["Work Time"].get<int>());
        pr->addTester(_employee);
        comp.push_back(_employee);
      } break;
      case 3:  // team leader
      {
        Project* pr = getProjectByID(projectsList,
                                     condidate["Project ID"].get<unsigned>());
        Engineer* _employee =
            new TeamLeader(
            condidate["id"].get<unsigned>(),
            condidate["name"].get<std::string>(), Position(3),
            condidate["salary"].get<int>(),
            pr);
        _employee->setWorkTime(condidate["Work Time"].get<int>());
        pr->addWorker(_employee);
        comp.push_back(_employee);
      } break;
      case 4:  // project manager
      {
        Employee* _employee = new ProjectManager(
            condidate["id"].get<unsigned>(),
            condidate["name"].get<std::string>(), Position(4),
            getProjectByID(projectsList,
                           condidate["Project ID"].get<unsigned>()));
        _employee->setWorkTime(condidate["Work Time"].get<int>());
        comp.push_back(_employee);
      } break;
      case 5:  // senior manager
      {
        SeniorManager* _employee = new SeniorManager(
            condidate["id"].get<unsigned>(),
            condidate["name"].get<std::string>(), Position(5));
        auto projectList = condidate["Project ID"].get<std::vector<int>>();
        for (const auto pr : projectList) {
          _employee->addProject(getProjectByID(projectsList, pr));
        }
        _employee->setWorkTime(condidate["Work Time"].get<int>());
        comp.push_back(_employee);
      } break;
      case 6:  // driver
      {
        Employee* _employee = new Driver(
            condidate["id"].get<unsigned>(),
            condidate["name"].get<std::string>(), Position(6),
            condidate["salary"].get<int>(),
            condidate["extra time"].get<int>());
        _employee->setWorkTime(condidate["Work Time"].get<int>());
        comp.push_back(_employee);
      } break;
      case 7:  // cleaner
      {
        Employee* _employee = new Cleaner(
            condidate["id"].get<unsigned>(),
            condidate["name"].get<std::string>(), Position(7),
            condidate["salary"].get<int>());
        _employee->setWorkTime(condidate["Work Time"].get<int>());
        comp.push_back(_employee);
      } break;
      default:
        continue;
    }
  }
  return comp;
}
