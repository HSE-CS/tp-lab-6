//  Copyright 2021 GHA created by Klykov Anton

#include "Factory.h"
#include <istream>
#include <random>
#include <fstream>

using json = nlohmann::json;
Project* StaffFactory::parseProjects(std::map<std::string, int> inf_project) {
  temp_proj = new Project(inf_project["id"], inf_project["budget"]);
  return temp_proj;
}
void StaffFactory::readProjectFile() {
  std::ifstream fin("img/projects.json");
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
  std::ifstream sin("img/staff.json");
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
    std::random_device rd;
    std::mt19937 randomSquare(rd());
    int square = static_cast<int>((randomSquare() % 6) + 1);
    int t_id = std::stoi(inf_staff["id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    temp_employee = new Cleaner(t_id, inf_staff["FIO"],
                                inf_staff["position"],
                                t_salary, square);
    return temp_employee;
  } else if (inf_staff["position"] == "Driver") {
    std::random_device rd;
    std::mt19937 randomKilometers(rd());
    int km = static_cast<int>((randomKilometers() % 10) + 1);
    int t_id = std::stoi(inf_staff["id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    temp_employee = new Driver(t_id, inf_staff["FIO"],
                               inf_staff["position"],
                               t_salary, km);
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
    std::random_device rd;
    std::mt19937 CompleteTaskInDeadline(rd());  // 0 - нет, 1 - да
    bool Deadline = static_cast<bool>(CompleteTaskInDeadline() % 2);
    Project* t_project = MakeProjects[project_id];
    temp_employee = new Programmer(t_id, inf_staff["FIO"],
                                   inf_staff["position"], t_salary,
                                   t_project, t_part, Deadline);
    return temp_employee;
  } else if (inf_staff["position"] == "Tester") {
    int t_id = std::stoi(inf_staff["id"]);
    int project_id = std::stoi(inf_staff["project_id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    float t_part = std::stof(inf_staff["part"]);
    std::random_device rd;
    std::mt19937 CompleteTaskInDeadline(rd());  // 0 - нет, 1 - да
    bool Deadline = static_cast<bool>(CompleteTaskInDeadline() % 2);
    Project* t_project = MakeProjects[project_id];
    temp_employee = new Tester(t_id, inf_staff["FIO"],
                               inf_staff["position"], t_salary,
                               t_project, t_part, Deadline);
    return temp_employee;
  } else if (inf_staff["position"] == "TeamLeader") {
    int t_id = std::stoi(inf_staff["id"]);
    int project_id = std::stoi(inf_staff["project_id"]);
    int t_salary = std::stoi(inf_staff["salary"]);
    float t_part = std::stof(inf_staff["part"]);
    std::random_device rd;
    std::mt19937 CompleteTaskInDeadline(rd());  // 0 - нет, 1 - да
    bool Deadline = static_cast<bool>(CompleteTaskInDeadline() % 2);
    std::random_device rd_1;
    std::mt19937 amountPeople(rd_1());  // 0 - нет, 1 - да
    bool people = static_cast<bool>(amountPeople() % 2);
    Project* t_project = MakeProjects[project_id];
    temp_employee = new TeamLeader(t_id, inf_staff["FIO"],
                               inf_staff["position"], t_salary,
                               t_project, t_part, Deadline, people);
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

