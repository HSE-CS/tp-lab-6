// copyright 2021 Toliman

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include <string>

#include "Employee.h"
#include "Interfaces.h"
#include "Engineer.h"


class ProjectManager : public Heading,
                       public Project,
                       public Employee {
 protected:
    std::vector<Employee *> projectWorkers;
    int employees;
    std::vector<Project *> projects;

 public:
    explicit ProjectManager(std::string name1,
                            int worktime1,
                            Project *project1,
                            int position1,
                            std::vector<Employee *> projectWorkers1);

    virtual int calcHeads();

    virtual void calc(int emp);

    virtual void printInfo();

    void setProjectWorkersVector(std::vector<Employee *> projectWorkers);
};

class SeniorManager : public ProjectManager {
 protected:
    std::vector<Employee *> *workers;

 public:
    explicit SeniorManager(std::string name1,
                           int worktime1,
                           Project *project1,
                           int position1,
                           std::vector<Employee *> workers1);

    virtual int calcHeads();

    virtual void calc();

    virtual void printInfo();
};

class TeamLeader : public Heading,
                   public Programmer {
 protected:
    std::vector<Employee *> *workers;

 public:
    explicit TeamLeader(std::string name1,
        int worktime1,
        Project *project1,
        int position1,
        int salary1,
        std::vector<Employee *> *workers);

    virtual int calcHeads();

    int calcProgrammers();

    virtual void calc();

    virtual void printInfo();

    void setWorkersVector(std::vector<Employee *> *workers);
};


#endif  // INCLUDE_MANAGER_H_
