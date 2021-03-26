#ifndef TP_LAB_6_MANAGER_H
#define TP_LAB_6_MANAGER_H

#include <vector>
#include "Employee.h"
#include "Interfaces.h"
#include <iostream>

class Project {
protected:
    unsigned int id;
    unsigned int budget;
    unsigned int people = 0;
public:
    Project(unsigned int id, unsigned int budget);

    [[nodiscard]] unsigned int getId() const;

    void setId(unsigned int id);

    [[nodiscard]] unsigned int getBudget() const;

    void setBudget(unsigned int budget);

    [[nodiscard]] unsigned int getPeople() const;

    void setPeople(unsigned int people);
};

class ProjectManager : public Employee, public ProjectBudget, public Heading {
protected:
    Project project;
public:
    ProjectManager(unsigned int id, std::string name, Project project);

    unsigned int calcHeads() override;

    void calc() override;

    void printInfo() override;

    const Project &getProject() const;

    void setProject(const Project &project);

    unsigned int calcBudgetPart(float part) override;

    unsigned int calcProAdditions() override;
};

class SeniorManager : public ProjectManager {
private:
    std::vector<Project> projects;
public:
    SeniorManager(unsigned int id, const std::string &name, std::vector<Project> projects);

    SeniorManager(unsigned int id, const std::string &name, Project project);

    unsigned int calcHeads() override;

    void calc() override;

    void printInfo() override;

    unsigned int calcBudgetPart(float part) override;
};

#endif //TP_LAB_6_MANAGER_H
