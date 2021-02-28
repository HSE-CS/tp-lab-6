// copyright 2021 Toliman

#include "../include/Factory.h"
#include "Manager.h"


typedef Project *pProject;

void Factory::__debug_pwd() {
    int code;
    code = system("pwd");
    code = system("echo %cd%");
}

std::string Factory::__find_info_path(std::string fileName) {
    std::ifstream s1((fileName).c_str());
    if (s1.good()) {
        s1.close();
        return fileName;
    }
    std::ifstream s2(("../" + fileName).c_str());
    if (s2.good()) {
        s2.close();
        return fileName;
    }
    std::ifstream s3(("../../" + fileName).c_str());
    if (s3.good()) {
        s3.close();
        return fileName;
    }
    return fileName;
}

std::vector<Employee *> Factory::getEmployees(const std::string &fileName,
    Project *startProject) {
    std::vector<Employee *> result;
    std::ifstream input(Factory::__find_info_path(fileName).c_str());
    std::string buffer;
    input >> buffer;
    while (buffer[0] == '&') {
        input >> buffer;
    }
    int count = std::atol(buffer.c_str());
    for (int i = 0; i < count; ++i) {
        input >> buffer;
        if (buffer[0] == '&') {
            i--;
            continue;
        }
        auto info = Factory::split(buffer);
        int profession = std::atol(info[1].c_str());
        int salary = std::atol(info[2].c_str());

        if (profession == CLEANER) {
            auto newEmployee = new Cleaner(info[0],
                8, startProject, profession, salary);
            result.push_back(newEmployee);
        } else if (profession == DRIVER) {
            auto newEmployee = new Driver(info[0],
                8, startProject, profession, salary);
            result.push_back(newEmployee);
        } else if (profession == PROGRAMMER) {
            auto newEmployee = new Programmer(info[0],
                8, startProject, profession, salary);
            result.push_back(newEmployee);
        } else if (profession == TESTER) {
            auto newEmployee = new Tester(info[0],
                8, startProject, profession, salary);
            result.push_back(newEmployee);
        } else if (profession == PROJECTMANAGER) {
            std::vector<Employee *> e;
            auto newEmployee = new ProjectManager(info[0],
                8, startProject, profession, e);
        } else if (profession == SENIORMANAGER) {
            std::vector<Employee *> e;
            auto newEmployee = new SeniorManager(info[0],
                8, startProject, profession, e);
        } else if (profession == TEAMLEADER) {
            std::vector<Employee *> e;
            auto newEmployee = new TeamLeader(info[0],
                8, startProject, profession, salary, &e);
        }
    }
    return result;
}

std::vector<std::string> Factory::split(const std::string &s) {
    std::vector<std::string> result;
    std::string buf;
    for (auto x : s) {
        if (x == ',') {
            result.push_back(buf);
            buf = "";
        } else {
            buf += x;
        }
    }
    if (buf.length() > 0) {
        result.push_back(buf);
    }
    return result;
}
