// Copyright 2021 Igumnova Natasha
#include "Factory.h"
#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"
#include <fstream>
#include <string>
#include <cmath>

std::vector<std::string> Factory::read_data() {
    std::string line;
    std::vector<std::string> buff;
    std::ifstream fin(filename);
    while (getline(fin, line)) {
        buff.push_back(line);
    }
    fin.close();
    return buff;
}
std::vector<Project> Factory::read_projects() {
    std::string line;
    std::vector<Project> buff;
    std::ifstream fin(projects_file);
    while (getline(fin, line)) {
        int ind = line.find(" ");
        Project pr = { std::stoi(line.substr(0, ind)), std::stoi(line.substr(ind + 1, line.size() - ind - 1)) };
        buff.push_back(pr);
    }
    fin.close();
    return buff;
}
int Factory::getWhours(std::string buff) {
    int i = buff.find(',');
    return (std::stoi(buff.substr(i + 1, buff.size()-i-1)));
}

int Factory::getPay(std::string buff) {
    int i = buff.find(',');
    int ind = buff.find(" - ");
    return  (std::stoi(buff.substr(ind+2, i-ind-2)));
}
std::string Factory::getfio(std::string buff) {
    std::string fio;
    int ind = buff.find(" - ");
    fio = buff.substr(2, ind - 2);
    return fio;
}
int Factory::getid(std::string buff) {
    std::string id;
    int ind = 0;
    for (int i = 0; i < buff.size(); i++) {
        if (isspace(buff[i])) {
            ind = i;
            break;
        }
    }
    id = buff.substr(0, ind);
    return (std::stoi(id));
}
void Factory::write_data(std::string data) {
    std::ofstream out;
    out.open(filename);
    if (out.is_open()) {
        out << data << std::endl;
    }
}

std::vector<Employee*> Factory::makeStaff() {
    std::vector<Employee*> res;
    std::vector<std::string> names = { "Driver"
                                       "Clener",
                                       "Senior Manager",
                                       "Project Manager",
                                       "Tester",
                                       "Programmer",
                                       "Team Leader"};
    std::vector<std::string> data = read_data();
    Employee* emp;
    std::string pos_;
    std::vector<Project> projects = read_projects();
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i];
        if (std::find(names.begin(), names.end(), data[i]) != names.end()) {
            pos_ = data[i];
        } else {
            int id_ = getid(data[i]);
            std::string name_ = getfio(data[i]);
            int payment_ = getPay(data[i]);
            int worktime_ = getWhours(data[i]);
            int ind_proj = rand() % projects.size();
            std::cout << id_ << name_ << worktime_ << pos_ << std::endl;
            if (pos_ == "Driver")
                emp = new Driver(id_, name_, pos_, worktime_, payment_);
            else if (pos_ == "Clener")
                emp = new Clener(id_, name_, pos_, worktime_, payment_);
            else if (pos_ == "Tester")
                emp = new Tester(id_, name_, pos_, worktime_, payment_, projects[ind_proj]);
            else if (pos_ == "Programmer")
                emp = new Programmer(id_, name_, pos_, worktime_, payment_, projects[ind_proj]);
            else if (pos_ == "Team Leader")
                emp = new TeamLeader(id_, name_, pos_, worktime_, payment_, projects[ind_proj]);
            else if (pos_ == "Project Manager")
                emp = new ProjectManager(id_, name_, pos_, worktime_, payment_, projects);
            else if (pos_ == "Senior Manager")
                emp = new SeniorManager(id_, name_, pos_, worktime_, payment_, projects);
            res.push_back(emp);
        }
    }
    return res;
}
