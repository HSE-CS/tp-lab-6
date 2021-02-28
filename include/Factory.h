//
// Created by Данил on 28.02.2021.
//

#ifndef TP_LAB_6_FACTORY_H
#define TP_LAB_6_FACTORY_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Employee;

class Factory {
public:
    static void __debug_pwd();

    static std::string __find_info_path(std::string fileName);

    static std::vector<Employee *> getEmployees(const std::string &fileName);
};


#endif //TP_LAB_6_FACTORY_H
