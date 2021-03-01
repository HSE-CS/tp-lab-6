// Copyright 2021 Bekina Svetlana
#include "Factory.h"

StaffFactory::StaffFactory() {}

StaffFactory::StaffFactory(std::string new_staff_file,
    std::string new_projects_file) {
    name_file_staff = new_staff_file;
    name_file_projects = new_projects_file;
}

std::vector<Employee*> StaffFactory::makeStaff() {
    std::vector<Employee*> staff;
    std::string line;
    std::ifstream data_staff(name_file_staff);
    std::ifstream data_projects(name_file_projects);
    if (data_projects.is_open() && data_staff.is_open()) {
        std::map<std::string, Project> projects;
        std::string name_p;
        int budget = 0;
        while (data_projects >> budget) {
            getline(data_projects, name_p);
            name_p.erase(0, 1);
            projects[name_p] = { name_p, budget };
        }
        size_t index = 0;
        std::vector<std::string> positions = { "Cleaner", "Driver", "Engineer",
            "Programmer", "Tester", "TeamLeader",
            "ProjectManager", "SeniorManager" };
        std::vector<Project> pr;
        std::string name_pr, name, second_name;
        int salary = 0;
        Employee* person;
        while (data_staff >> line) {
            bool isPosition = false;
            for (size_t i = 0; i < positions.size(); i++) {
                if (positions[i] == line) {
                    index = i;
                    isPosition = true;
                    break;
                }
            }
            if (!isPosition) {
                name = line;
            } else {
                data_staff >> name;
            }
            data_staff >> second_name;
            if (index > 5) {
                srand(time(0));
				int seed = 54321;
                salary = 1000 + rand_r(&seed) % 10000;
            } else {
                data_staff >> salary;
            }

            std::string id = std::to_string(salary) + name[0] + second_name[0]
                + std::to_string(staff.size() + 1);
            size_t n = id.size();
            for (int i = 0; i < 10 - n; i++) {
                id = '0' + id;
            }
            switch (index) {
            case 0:
                person = new Cleaner(id, name + ' ' + second_name,
                    positions[index], salary);
                break;
            case 1:
                person = new Driver(id, name + ' ' + second_name,
                    positions[index], salary);
                break;
            case 2:
                getline(data_staff, name_p);
                name_p.erase(0, 1);
                person = new Engineer(id, name + ' ' + second_name,
                    positions[index], salary, projects[name_p]);
                break;
            case 3:
                getline(data_staff, name_p);
                name_p.erase(0, 1);
                person = new Programmer(id, name + ' ' + second_name,
                    positions[index], salary, projects[name_p]);
                break;
            case 4:
                getline(data_staff, name_p);
                name_p.erase(0, 1);
                person = new Tester(id, name + ' ' + second_name,
                    positions[index], salary, projects[name_p]);
                break;
            case 5:
                getline(data_staff, name_p);
                name_p.erase(0, 1);
                person = new TeamLeader(id, name + ' ' + second_name,
                    positions[index], salary, projects[name_p]);
                break;
            case 6:
                pr.clear();
                name_pr.clear();
                getline(data_staff, name_p);
                name_p.erase(0, 1);
                for (int i = 0; i < name_p.size(); i++) {
                    if (name_p[i] != ',' && name_p[i] != '\0') {
                        name_pr += name_p[i];
                    } else {
                        pr.push_back(projects[name_pr]);
                        name_pr.clear();
                    }
                }
                person = new ProjectManager(id, name + ' ' + second_name,
                    positions[index], pr);
                break;
            case 7:
                pr.clear();
                for (auto name_p : projects) {
                    pr.push_back(name_p.second);
                }
                person = new SeniorManager(id, name + ' ' + second_name,
                    positions[index], pr);
                break;
            default:
                break;
            }
            staff.push_back(person);
        }
    }
    data_projects.close();
    data_staff.close();
    return staff;
}
