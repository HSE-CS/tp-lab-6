
#include "Engineer.h"


  int Engineer::calcBudgetPart(float part, int budget) {

  };

  void Engineer::calc() {
      payment = calcBase(salary, worktime) + calcProAdditions() + calcBonus();
  };


  int Programmer::calcProAdditions(){
      //return 
  };
  int Programmer::calcBonus(){
      return 20;

  };


  int TeamLeader::calcHeads(){
  };
  //calc();
  int TeamLeader::calcBonus(){
      return 25;
  };



  int Tester::calcProAdditions(){
  };
  int Tester::calcBonus(){
      return 21;
  };
  void Tester::calc(){
      payment = calcBase(salary, worktime) + calcProAdditions() + calcBonus();
  };
