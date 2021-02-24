#include"Personal.h"
unsigned int Personal::calcBase() {
  return this->salary * this->worktime;
}
void Cleaner::calc() { this->payment = calcBase(); }
unsigned int Driver::calcBonus() { return bonusToMoney * bonus; }
void Driver::calc() { this->payment = calcBase() + calcBonus(); }
void Cleaner::printInfo() {
  Employee::printInfo();
  std::cout << "+-------------------------+" << std::endl;
}
void Driver::printInfo() {
  Employee::printInfo();
  unsigned int setw1{10}, setw2{15};
  std::cout << std::setw(setw1) << "|Bonus " << std::setw(setw2) << this->bonus
            << " |" << std::endl;
  std::cout << "+-------------------------+" << std::endl;
}
