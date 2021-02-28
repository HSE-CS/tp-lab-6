//  Copyright 2021 GHA created by Klykov Anton

#include "Factory.h"
#include <istream>
#include <fstream>

using json = nlohmann::json;
Project* StaffFactory::parseProjects(std::map<std::string, int> inf_project) {
  temp_proj = new Project(inf_project["id"], inf_project["budget"]);
  return temp_proj;
}
void StaffFactory::readProjectFile() {
  std::ifstream fin("projects.json");
  int amountProjects{5};
  std::string cont;
  json j = json::parse(fin);
  for (int i = 0; i < amountProjects; ++i) {
    cont = "project";
    cont += std::to_string(i+1);
    j[cont].get_to<std::map<std::string, int>>(this->project_json);
    MakeProjects.push_back(parseProjects(project_json));
  }
  fin.close();
}
void StaffFactory::readStaffFile() {
  std::ifstream sin("staff.json");
  int amountStaff{64};
  std::string cont;
  json j = json::parse(sin);
  for (int i = 0; i < amountStaff; ++i) {
    cont = "person";
    cont += std::to_string(i + 1);
    j[cont].get_to<std::map<std::string, std::string>>(this->staff);
    MakeStaff.push_back(parseStaff(staff));
  }
  sin.close();
}
Employee* StaffFactory::parseStaff(std::map<std::string,
                                   std::string> inf_staff) {
  if (inf_staff["position"] == "Cleaner") {
    int t_id = std::stoi(inf_staff["id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    temp_employee = new Cleaner(t_id, inf_staff["FIO"],
                                inf_staff["position"], t_salary);
    return temp_employee;
  } else if (inf_staff["position"] == "Driver") {
    int t_id = std::stoi(inf_staff["id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    temp_employee = new Driver(t_id, inf_staff["FIO"],
                               inf_staff["position"], t_salary);
    return temp_employee;
  } else if (inf_staff["position"] == "Engineer") {
    int t_id = std::stoi(inf_staff["id"]);
    int project_id = std::stoi(inf_staff["project_id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    float t_part = std::stof(inf_staff["part"]);
    Project* t_project = MakeProjects[project_id];
    temp_employee = new Engineer(t_id, inf_staff["FIO"],
                                 inf_staff["position"], t_salary,
                                 t_project, t_part);
    return temp_employee;
  } else if (inf_staff["position"] == "Programmer") {
    int t_id = std::stoi(inf_staff["id"]);
    int project_id = std::stoi(inf_staff["project_id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    float t_part = std::stof(inf_staff["part"]);
    Project* t_project = MakeProjects[project_id];
    temp_employee = new Programmer(t_id, inf_staff["FIO"],
                                   inf_staff["position"], t_salary,
                                   t_project, t_part);
    return temp_employee;
  } else if (inf_staff["position"] == "Tester") {
    int t_id = std::stoi(inf_staff["id"]);
    int project_id = std::stoi(inf_staff["project_id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    float t_part = std::stof(inf_staff["part"]);
    Project* t_project = MakeProjects[project_id];
    temp_employee = new Tester(t_id, inf_staff["FIO"],
                               inf_staff["position"], t_salary,
                               t_project, t_part);
    return temp_employee;
  } else if (inf_staff["position"] == "TeamLeader") {
    int t_id = std::stoi(inf_staff["id"]);
    int project_id = std::stoi(inf_staff["project_id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    float t_part = std::stof(inf_staff["part"]);
    Project* t_project = MakeProjects[project_id];
    temp_employee = new Tester(t_id, inf_staff["FIO"],
                               inf_staff["position"], t_salary,
                               t_project, t_part);
    return temp_employee;
  } else if (inf_staff["position"] == "ProjectManager") {
    int t_id = std::stoi(inf_staff["id"]);
    int project_id = std::stoi(inf_staff["project_id"]);
    float t_part = std::stof(inf_staff["part"]);
    Project* t_project = MakeProjects[project_id];
    temp_employee = new ProjectManager(t_id, inf_staff["FIO"],
                                       inf_staff["position"],
                                       t_project, t_part);
    return temp_employee;
  } else if (inf_staff["position"] == "SeniorManager") {
    int t_id = std::stoi(inf_staff["id"]);
    int project_id = std::stoi(inf_staff["project_id"]);
    float t_part = std::stof(inf_staff["part"]);
    Project* t_project = MakeProjects[project_id];
    temp_employee = new SeniorManager(t_id, inf_staff["FIO"],
                                      inf_staff["position"], t_project,
                                      t_part, MakeProjects);
    return temp_employee;
  }
  return nullptr;
}
std::vector<Employee *> StaffFactory::getStaff() {
  readProjectFile();
  readStaffFile();
  return MakeStaff;
}

