// copyright 2021 Toliman

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Employee;
class Project;

class Factory {
 public:
    static void __debug_pwd();

    static std::string __find_info_path(std::string fileName);

    static std::vector<Employee *> getEmployees(const std::string &fileName,
        Project* startProject);

    static std::vector<std::string> split(const std::string &s);
};

#endif  // INCLUDE_FACTORY_H_
