// Copyright 2021 Kartseva Masha
#pragma once
#define MANAGER_H
#ifdef MANAGER_H
#include <string>
#include "Employee.h"
#include "Interfaces.h"


class Manager : public Employee, public ProjectBudget {
 public:
    Manager(std::string name, unsigned int id, std::string position, 
        std::string project, float contribution);
    float getPaymentbyProject() override;
    float getPayment() override;
 protected:
    float contribution;
    std::string position;
    std::string project;
};
class ProjectManager : public Manager, public Heading {
 public:
    ProjectManager(std::string name, unsigned int id, std::string position, 
        std::string project, float contribution, unsigned int subordinates);
    float getPaymentbyHeading() override;
    float getPayment() override;
 private:
    unsigned int subordinates;
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(std::string name, unsigned int id, std::string position, 
        std::string project, float contribution, unsigned int subordinates);
};
#endif  // MANAGER_H
