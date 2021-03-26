// Copyright 2021 Ziganshin Nikita

#ifndef TP_LAB_6_FACTORY_H_
#define TP_LAB_6_FACTORY_H_

#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"
#include <fstream>
#include <string>
#include <vector>

class StaffFactory {
 public:
    static std::vector<Employee*> makeStaff(const std::string& path);
};

#endif  // TP_LAB_6_FACTORY_H_
