//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Personal.h"
#include "Programmer.h"
#include "TeamLeader.h"
#include "Manager.h"
#include "Tester.h"
#include "Project.h"

std::vector <Employee*> makeStaffVector(std::string pathFile);


#endif  //  INCLUDE_FACTORY_H_
