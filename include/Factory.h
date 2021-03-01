// Copyright 2021 Bekina Svetlana
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <map>
#include <fstream>
#include <ctime>
#include "Manager.h"
#include "Engineer.h"

class StaffFactory {
 public:
    explicit StaffFactory();
    explicit StaffFactory(std::string, std::string);
    std::vector<Employee*> makeStaff();

 private:
    std::string name_file_staff = "staff.txt";
    std::string name_file_projects = "projects.txt";
};
#endif  // INCLUDE_FACTORY_H_
