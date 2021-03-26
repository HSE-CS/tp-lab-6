#ifndef TP_LAB_6_FACTORY_H
#define TP_LAB_6_FACTORY_H

#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"
#include <fstream>

class StaffFactory
{
public:
    static std::vector<Employee*> makeStaff(const std::string& path);
};

#endif //TP_LAB_6_FACTORY_H
