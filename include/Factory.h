// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Engineer.h"

class Factory {
 private:
    std::string filename;
    std::string projects_file;
 public:
    Factory(std::string filename_, std::string projects_) {
        filename = filename_;
        projects_file = projects_;
    }
    int getPay(std::string buff);
    std::vector<std::string> read_data();
    std::vector<Project> read_projects();
    std::vector<Employee*> makeStaff();
    void write_data(std::string data);
    std::string getfio(std::string buff);
    int getid(std::string buff);
    int getWhours(std::string buff);
};
#endif  // INCLUDE_FACTORY_H_
