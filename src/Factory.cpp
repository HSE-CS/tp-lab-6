//  Copyright 2021 Nikita Naumov

#include "Factory.h"

std::vector<Employee*> makeStaffVector(std::string pathFile) {
    unsigned number = 0;
    std::ifstream FileIn;
    FileIn.open(pathFile);
    if (!FileIn.is_open()) {
        std::cout << "File wasn't opened" << std::endl;
        throw -1;
    }
    std::vector<Employee*> vector;
    std::string fullname;
    std::string tmp1, tmp2;
    while (!FileIn.eof()) {
        FileIn >> tmp1 >> tmp2;
        fullname += tmp1 + " " + tmp2;
        tmp1.clear();
        tmp2.clear();
        std::vector<int> quantity(7);
        int randomClass = std::rand()%7;
        switch (randomClass) {
            case 0:
                if (quantity[0] < 10) {
                    vector.push_back(new Cleaner(number, fullname));
                    quantity[0]++;
                    break;
                }
            case 1:
                if (quantity[1] < 20) {
                    vector.push_back(new Driver(number, fullname));
                    quantity[1]++;
                    break;
                }
            case 2:
                if (quantity[2] < 15) {
                    vector.push_back(new ProjectManager(number, fullname));
                    quantity[2]++;
                    break;
                }
            case 3:
                vector.push_back(new Programmer(number, fullname));
                quantity[3]++;
                break;
            case 4:
                if (quantity[4]) {
                    vector.push_back(new SeniorManager(number, fullname));
                    quantity[4]++;
                    break;
                }
            case 5:
                if (quantity[5] < 15) {
                    vector.push_back(new TeamLeader(number, fullname));
                    quantity[5]++;
                    break;
                }
            case 6:
                vector.push_back(new Tester(number, fullname));
                quantity[6]++;
                break;
            default:
                break;
        }
        fullname.clear();
        number++;
    }
    return vector;
}
