// Copyright 2020 GHA Test Team
#include "Factory.h"


StaffFactory::StaffFactory() {
  file_name = "";
}

StaffFactory::StaffFactory(std::string file_name) {
  this->file_name = file_name;
}

void StaffFactory::readData() {
  std::ifstream in(file_name);
  std::string line;
  if (in.is_open()) {
    while (getline(in, line)) {
      data.push_back(line);
    }
  }
}

std::vector<std::string> getProjectInfo(std::string project_info_str) {
  std::string _temp;
  std::istringstream _line(project_info_str);
  std::vector<std::string> project_tokens;
  while (getline(_line, _temp, ' ')) {
    project_tokens.push_back(_temp);
  }
  return project_tokens;
}

Project* StaffFactory::createProject(std::vector<std::string> project_tokens) {
  Project* project = new Project();
  project->id = project_tokens[0];
  project->budget = atoi(project_tokens[1].c_str());
  project->workers_num = atoi(project_tokens[2].c_str());
  return project;
}

Project* StaffFactory::createProject(std::string name,
  int budget, int workers_num) {
  Project* project = new Project();
  project->id = name;
  project->budget = budget;
  project->workers_num = workers_num;
  return project;
}

std::vector<Employee*> StaffFactory::makeStaff() {
  readData();
  std::vector<Employee*> staff;
  unsigned size = data.size();
  for (unsigned i = 0; i < size; i++) {
    std::string temp;
    std::istringstream line(data[i]);
    std::vector<std::string> tokens;
    while (getline(line, temp, ',')) {
      tokens.push_back(temp);
    }
    int id = std::stoi(tokens[0]);
    std::string name = tokens[1];
    std::string position = tokens[2];
    if (position == "DRIVER") {
      Driver* driver = new Driver(id, name, std::stoi(tokens[3]));
      staff.push_back(driver);
    } else if (position == "CLEANER") {
      Cleaner* cleaner = new Cleaner(id, name, std::stoi(tokens[3]));
      staff.push_back(cleaner);
    } else if (position == "PROJECT_MANAGER") {
      Project* project = createProject(getProjectInfo(tokens[4]));
      ProjectManager* project_manager = new ProjectManager(id, name, project);
      staff.push_back(project_manager);
    } else if (position == "SENIOR_MANAGER") {
      unsigned size = tokens.size();
      int projects_num = size - 4;
      Project** projects = new Project*[size - 4];
      for (unsigned j = 4; j < size; j++) {
        projects[j - 4] = createProject(getProjectInfo(tokens[j]));
      }
      SeniorManager* senior_manager =
        new SeniorManager(id, name, projects, projects_num);
      staff.push_back(senior_manager);
    } else if (position == "TESTER") {
      Project* project = createProject(getProjectInfo(tokens[4]));
      Tester* tester = new Tester(id, name, std::stoi(tokens[3]), project);
      staff.push_back(tester);
    } else if (position == "PROGRAMMER") {
      Project* project = createProject(getProjectInfo(tokens[4]));
      Programmer* programmer =
        new Programmer(id, name, std::stoi(tokens[3]), project);
      staff.push_back(programmer);
    } else if (position == "TEAM_LEADER") {
      Project* project = createProject(getProjectInfo(tokens[4]));
      TeamLeader* team_leader =
        new TeamLeader(id, name, std::stoi(tokens[3]), project);
      staff.push_back(team_leader);
    }
  }
  return staff;
}
