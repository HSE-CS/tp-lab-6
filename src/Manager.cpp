// Copyright 2021 by mila

 #include "Manager.h"

 int ProjectManager::calcHeads () {
     int num = 0;
     for (auto &p : projects)
         num += p->team;
     return num;
 };

 int ProjectManager::calcBudgetPart (float part, int budget){
     return (int)((float)budget / part);
 };

 int ProjectManager::calcProAdditions (){
     return 35;
 };

 void ProjectManager::calc (){
     return 40
 };

 void ProjectManager::printInfo (){
     std::cout << "id : " << this.id << std::endl;
     std::cout << "name : " << this.name << std::endl;
     std::cout << "position : " << this.position << std::endl;
     std::cout << "salary : " << salary << std::endl;
     std::cout << "worktime : " << worktime << std::endl;
     std::cout << "payment : " << payment << std::endl;
 };

 // void SeniorManager::calc(){
 // };
