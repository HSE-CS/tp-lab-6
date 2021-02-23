//// Copyright 2021 Dmitry Vargin

#include "Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"

Project::Project(int id, double budget) {
    this->id = id;
    this->budget = budget;
}
Project::~Project() = default;;

void Project::setId(int id) { this->id = id; }
void Project::setBudget(double budget) { this->budget = budget; }

int Project::getId() { return this->id; }
double Project::getBudget() { return this->budget; }

std::vector<Employee*> readData(std::string file_name) {
    /*
    std::string path = std::filesystem::current_path().string();
    path = path.substr(0, path.rfind('/')).
            substr(0, path.rfind('/'));
    path = path.substr(0, path.rfind('/'))
            + "/data/" + file_name;
    std::ifstream file(path);
     */
    std::ifstream file(file_name);
    if (file.is_open()) {
        std::cout << "File was opened\n";
        std::vector<Employee*> employee;
        std::string tmp = "";
        getline(file, tmp);
        int num = std::stoi(tmp);
        int counter = 0;
        for (int i = 0; i < num; ++i) {
            tmp.clear();
            std::string id, name, worktime, position, salary;
            getline(file, id, ' ');
            getline(file, name, ' ');
            getline(file, worktime, ' ');
            getline(file, position, ' ');
            getline(file, salary, '\n');

            if (position == "programmer") {
                Project *project = new Project(counter++, 0);
                employee.push_back(
                        new Programmer(stoi(id), name, position,
                                       stoi(salary),
                                       stoi(worktime),
                                       project, 0.2));
            } else if (position == "tester") {
                Project *project = new Project(counter++, 0);
                employee.push_back(
                        new Tester(stoi(id), name, position,
                                   stoi(salary),
                                   stoi(worktime),
                                   project, 0.2));
            } else if (position == "teamLeader") {
                Project *project = new Project(counter++, 0);
                employee.push_back(new TeamLeader(stoi(id), name, position,
                                                  stoi(salary),
                                                  stoi(worktime),
                                                  project, 0.2));
            } else if (position == "cleaner") {
                employee.push_back(
                        new Cleaner(stoi(id), name,
                                    position,
                                    std::stoi(salary) / 4,
                                    stoi(worktime)));
            } else if (position == "driver") {
                employee.push_back(new Driver(stoi(id), name,
                                              position,
                                              std::stoi(salary) / 4,
                                              stoi(worktime)));
            } else if (position == "projectManager") {
                Project *project = new Project(counter++, 0);
                employee.push_back(
                        new ProjectManager(stoi(id), name,
                                           position,
                                           project));
            } else if (position == "seniorManager") {
                std::vector <Project*> projects;
                employee.push_back(
                        new SeniorManager(stoi(id), name,
                                          position, projects));
            }
        }
        return employee;
    } else {
        throw "File was not opened";
    }
}
