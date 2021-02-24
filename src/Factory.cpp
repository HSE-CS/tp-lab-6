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
                        new Programmer(
                                std::stoi(id),
                                std::stoi(worktime),

                                std::stoi(salary) /
                                std::stoi(worktime),

                                std::stoi(salary),
                                name, position,
                                project, 0.2));
            } else if (position == "tester") {
                Project *project = new Project(counter++, 0);
                employee.push_back(
                        new Tester(
                                std::stoi(id),
                                std::stoi(worktime),

                                std::stoi(salary) /
                                std::stoi(worktime),

                                std::stoi(salary),
                                name, position,
                                project, 0.2));
            } else if (position == "teamLeader") {
                Project *project = new Project(counter++, 0);
                employee.push_back(
                        new TeamLeader(
                                std::stoi(id),
                                std::stoi(worktime),

                                std::stoi(salary) /
                                std::stoi(worktime),

                                std::stoi(salary),
                                name, position,
                                project, 0.2));
            } else if (position == "cleaner") {
                employee.push_back(
                        new Cleaner(std::stoi(id),
                                    std::stoi(worktime),
                                    std::stoi(salary) /
                                    std::stoi(worktime),

                                    std::stoi(salary),
                                    name, position));
            } else if (position == "driver") {
                employee.push_back(
                        new Driver(std::stoi(id),
                                   std::stoi(worktime),
                                   std::stoi(salary) /
                                   std::stoi(worktime),

                                   std::stoi(salary),
                                   name, position));
            } else if (position == "projectManager") {
                Project *project = new Project(counter++, 0);
                employee.push_back(
                        new ProjectManager(std::stoi(id),
                                           std::stoi(worktime),
                                           std::stoi(salary) /
                                           std::stoi(worktime),

                                           std::stoi(salary),
                                           name, position,
                                           project));
            } else if (position == "seniorManager") {
                std::vector <Project*> projects;
                employee.push_back(
                        new SeniorManager(std::stoi(id),
                                          std::stoi(worktime),
                                          std::stoi(salary) /
                                          std::stoi(worktime),

                                          std::stoi(salary),
                                          name, position,
                                          projects));
            }
        }
        return employee;
    } else {
        throw "File was not opened";
    }
}
