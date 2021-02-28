#include "Personal.h"


int Personal::calcBase(int salary. int wtime) {
    return salary * wtime;
  };


int Cleaner::calcBonus(){
    return 10;
  };

  void Cleaner::calc(){
      return calcBase(salary,worktime) + calcBonus();
  };

  void Cleaner::printInfo(){
      std::cout << "id : " << this.id << std::endl;
      std::cout << "name : " << this.name << std::endl;
      std::cout << "position : " << this.position << std::endl;
      std::cout << "salary : " << salary << std::endl;
      std::cout << "worktime : " << worktime << std::endl;
      std::cout << "payment : " << payment << std::endl;

  };


  int Driver::calcBonus(){
      return 15;
  };

  void calc(){
  };
