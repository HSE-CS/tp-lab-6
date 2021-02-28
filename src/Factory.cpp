// Copyright 2021 Kris

#include "Factory.h"

std::vector<Employee*> makeStaff(std::string staffList,
    std::string projectsList) {
    std::vector<Employee*> res;
    std::vector<Project> allProjects;
    std::string read, elem, arr[5];
    unsigned int i = 0;
    std::ifstream staff(staffList), projects(projectsList);
    while (getline(projects, read)) {
        i = 0;
        std::stringstream strStream(read);
        while (getline(strStream, elem, ' ')) arr[i++] = elem;
        allProjects.push_back(Project(stoi(arr[0]), stoi(arr[1])));
    }
    projects.close();
    while (getline(staff, read)) {
        i = 0;
        std::stringstream strStream(read);
        while (getline(strStream, elem, ' ')) {
            arr[i++] = elem;
        }
        int id = std::stoi(arr[0]), payment = std::stoi(arr[3]),
            projectId = std::stoi(arr[4]);
        std::string name = arr[1], position = arr[2];
        int projectBudget = 0;
        for (i = 0; i < allProjects.size(); ++i) {
            if (allProjects[i].getId() == projectId) {
                projectBudget = allProjects[i].getBudget();
                break;
            }
        }
        Project currentProject(projectId, projectBudget);
        Employee* newEmployee;
        if (position == "Personal")
            newEmployee = new Personal(id, name, position, payment);
        else if (position == "Driver")
            newEmployee = new Driver(id, name, position, payment);
        else if (position == "Cleaner")
            newEmployee = new Cleaner(id, name, position, payment);
        else if (position == "Engineer")
            newEmployee = new Engineer(id, name, position, payment,
                currentProject);
        else if (position == "Programmer")
            newEmployee = new Programmer(id, name, position, payment,
                currentProject);
        else if (position == "Tester")
            newEmployee = new Tester(id, name, position, payment,
                currentProject);
        else if (position == "TeamLeader")
            newEmployee = new TeamLeader(id, name, position, payment,
                currentProject);
        else if (position == "ProjectManager")
            newEmployee = new ProjectManager(id, name, position, payment,
                currentProject);
        else if (position == "SeniorManager")
            newEmployee = new SeniorManager(id, name, position, payment,
                allProjects);
        res.push_back(newEmployee);
    }
    staff.close();
    return res;
}
