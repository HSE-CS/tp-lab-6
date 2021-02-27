// Copyright [2021] <Roman Balayan>

#include "Factory.h"

Factory::Factory(std::string filename) : filename(filename) {
}

std::vector<Employee* > Factory::getEmployees() {
    std::vector<Employee* > employees;
    std::ifstream in(this->filename);
    auto rows = this->getNextLineAndSplitIntoTokens(in);
    int projectsID = 0;  // it could be done better but idc
    for (auto row : rows) {
        auto id = std::atoi(row[0].c_str());
        auto name = row[1];
        auto position = row[2];
        auto worktime = std::atoi(row[3].c_str());
        if (position == "Cleaner") {
            auto salary = std::atoi(row[4].c_str());
            Employee* emp = new Cleaner(id, name, worktime, 0, salary);
            employees.push_back(emp);
        } else if (position == "Driver") {
            auto salary = std::atoi(row[4].c_str());
            Employee* emp = new Driver(id, name, worktime, 0, salary);
            employees.push_back(emp);
        } else if (position == "Programmer") {
            auto salary = std::atoi(row[4].c_str());
            auto projTitle = row[5];
            int projID = projectsID++;
            auto projBudget = std::atoi(row[6].c_str());
            std::shared_ptr<Project> proj = std::make_shared<Project>
                                    (projID, projBudget, projTitle);
            Employee* emp = new Programmer(id,
                                            name,
                                            Position::Programmer,
                                            worktime,
                                            0,
                                            salary,
                                            proj);
            employees.push_back(emp);
        } else if (position == "Tester") {
            auto salary = std::atoi(row[4].c_str());
            auto projTitle = row[5];
            int projID = projectsID++;
            auto projBudget = std::atoi(row[6].c_str());
            std::shared_ptr<Project> proj = std::make_shared<Project>
                                        (projID, projBudget, projTitle);
            Employee* emp = new Tester(id,
                                        name,
                                        Position::Tester,
                                        worktime,
                                        0,
                                        salary,
                                        proj);
            employees.push_back(emp);
        } else if (position == "ProjectManager") {
        } else if (position == "SeniorManager") {
        } else if (position == "TeamLeader") {
        }

        for (auto cell : row)
            std::cout << cell << ' ';
        std::cout << '\n';
    }

    return employees;
}

std::vector<std::vector<std::string> > Factory::getNextLineAndSplitIntoTokens(std::istream& str) {
    std::vector<std::vector<std::string> > result;
    std::string line;

    std::string cell;
    std::vector<std::string > row;
    while (std::getline(str, cell, ':')) {
        if (cell == "end") {
            result.push_back(row);
            row.clear();
            continue;
        }
        row.push_back(cell);
    }

    return result;
}
