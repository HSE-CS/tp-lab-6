//
// Created by Данил on 28.02.2021.
//

#include "../include/Factory.h"


void Factory::__debug_pwd() {
    int code;
    code = system("pwd");
    code = system("echo %cd%");
}

std::string Factory::__find_info_path(std::string fileName) {
    std::ifstream s1((fileName).c_str());
    if (s1.good())
        return fileName;
    std::ifstream s2(("../" + fileName).c_str());
    if (s2.good())
        return fileName;
    std::ifstream s3(("../../" + fileName).c_str());
    if (s3.good())
        return fileName;
    return fileName;
}

std::vector<Employee *> Factory::getEmployees(const std::string& fileName) {
    return std::vector<Employee *>();
}
