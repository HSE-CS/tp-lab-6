// Copyright 2021 FOM
#include"Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"
#include <fstream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

Position getPosinitiontoread(const std::string str) {
    if (str == "Driver") {
        return Position::DRIVER;
    }
    else if (str == "Cleaner") {
        return Position::CLEANER;
    }
    else if (str == "Tester") {
        return Position::TESTER;
    }
    else if (str == "Programmer") {
        return Position::PROGRAMMER;
    }
    else if (str == "TeamLeader") {
        return Position::TEAMLEADER;
    }
    else if (str == "ProjectManager") {
        return Position::PROJECTMANAGER;
    }
    else if (str == "SeniorManager") {
        return Position::SENIORMANAGER;
    }
}

std::vector<Employee*> Factory::makeStaff(const std::string dir) {
    std::ifstream file(dir);
    if (file) {
        std::string str;
        while (getline(file, str)) {
            std::stringstream stream(str);
            unsigned int person_id, numProjects, person_salary{ 0 }, person_worktime{ 0 }, person_payment{ 0 }, subord{ 0 };
            double person_part{ 0 };
            std::string person_name, file_position;
            std::vector<Project*> projects;
            stream >> person_id >> person_name >> file_position;
            Position porision_{ getPosinitiontoread(file_position) };
            if (porision_ == Position::CLEANER) {
                stream >> person_worktime;
                stream >> person_payment;
            }
            if (porision_ == Position::DRIVER) {
                stream >> person_worktime;
                stream >> person_payment;
            }
            if (porision_ == Position::PROGRAMMER) {
                stream >> person_salary;
                stream >> person_worktime;
                int project_id, project_budget;
                std::string project_name;
                while (stream >> project_id) {
                    stream >> project_name;
                    stream >> project_budget;
                    Project* ptr = new Project(project_id, project_name, project_budget);
                    projects.push_back(ptr);
                }
                stream >> person_part;}
            if (porision_ == Position::TEAMLEADER) {
                stream >> person_salary;
                stream >> person_worktime;
                int project_id, project_budget;
                std::string project_name;
                while (stream >> project_id) {
                    stream >> project_name;
                    stream >> project_budget;
                    Project* ptr = new Project(project_id, project_name, project_budget);
                    projects.push_back(ptr);
                }
                stream >> person_part;
            }
            if (porision_ == Position::TESTER) {
                stream >> person_salary;
                stream >> person_worktime;
                int project_id, project_budget;
                std::string project_name;
                while (stream >> project_id) {
                    stream >> project_name;
                    stream >> project_budget;
                    Project* ptr = new Project(project_id, project_name, project_budget);
                    projects.push_back(ptr);
                }
                stream >> person_part;
            }
            if (porision_ == Position::PROJECTMANAGER) {
                stream >> numProjects;
                stream >> person_payment;
                stream >> person_worktime;
                int project_id, project_budget;
                std::string project_name;
                while (stream >> project_id) {
                    stream >> project_name;
                    stream >> project_budget;
                    Project* ptr = new Project(project_id, project_name, project_budget);
                    projects.push_back(ptr);
                }
            }
            if (porision_ == Position::SENIORMANAGER) {
                stream >> numProjects;
                stream >> person_payment;
                stream >> person_worktime;
                int project_id, project_budget;
                std::string project_name;
                while (stream >> project_id) {
                    stream >> project_name;
                    stream >> project_budget;
                    Project* ptr = new Project(project_id, project_name, project_budget);
                    projects.push_back(ptr);
                }
            }
            Employee* emp;
            switch (porision_) {
            case Position::CLEANER:
                emp = new Cleaner(person_id, person_name, file_position, person_worktime, person_salary);
                break;
            case Position::DRIVER:
                emp = new Driver(person_id, person_name, file_position, person_worktime,person_salary);
                break;
            case Position::PROJECTMANAGER:
                emp = new ProjectManager(person_id, person_name, file_position, numProjects,
                    person_worktime, person_salary,projects);
                break;
            case Position::SENIORMANAGER:
                emp = new SeniorManager(person_id, person_name, file_position, numProjects,
                    person_worktime, person_salary, projects);
                break;
            case Position::PROGRAMMER:
                emp = new Programmer(person_id, person_name, file_position,
                    person_salary,person_worktime,projects[0],person_part);
                break;
            case Position::TESTER:
                emp = new Tester(person_id, person_name, file_position,
                    person_salary, person_worktime, projects[0], person_part);
                break;
            case Position::TEAMLEADER:
                emp = new TeamLeader(person_id, person_name, file_position,
                    person_salary, person_worktime, projects[0], person_part);
            }
            this->staff.push_back(emp);
        }
    }
    return staff;
}
