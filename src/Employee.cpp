// Copyright NikDemoShow 2021
#include"Employee.h"
void Employee::printInfo() {
  unsigned int setw1{10}, setw2{15};
  std::cout << "+-------------------------+" << std::endl;
  std::cout << std::setiosflags(std::ios::left);
  std::cout << std::setw(setw1) << "|ID "
            << std::setw(setw2) << this->id
            << " |" << std::endl;
  std::cout << std::setw(setw1) << "|Name " << std::setw(setw2) << this->name
            << " |" << std::endl;
  switch (this->position) {
    case Position::Cleaner:
      std::cout << std::setw(setw1) << "|Position " << std::setw(setw2)
                << "Cleaner"
                << " |" << std::endl;
      break;
    case Position::Driver:
      std::cout << std::setw(setw1) << "|Position " << std::setw(setw2)
                << "Driver"
                << " |" << std::endl;
      break;
    case Position::Programmer:
      std::cout << std::setw(setw1) << "|Position " << std::setw(setw2)
                << "Programmer"
                << " |" << std::endl;
      break;
    case Position::ProjectManager:
      std::cout << std::setw(setw1) << "|Position " << std::setw(setw2)
                << "ProjectManager"
                << " |" << std::endl;
      break;
    case Position::SeniorManager:
      std::cout << std::setw(setw1) << "|Position " << std::setw(setw2)
                << "SeniorManager "
                << " |" << std::endl;
      break;
    case Position::TeamLeader:
      std::cout << std::setw(setw1) << "|Position " << std::setw(setw2)
                << "TeamLeader"
                << " |" << std::endl;
      break;
    case Position::Tester:
      std::cout << std::setw(setw1) << "|Position " << std::setw(setw2)
                << "Tester"
                << " |" << std::endl;
      break;
  }
  std::cout << std::setw(setw1) << "|WorkTime " << std::setw(setw2)
            << this->worktime << " |" << std::endl;
  std::cout << std::setw(setw1) << "|Payment " << std::setw(setw2)
            << this->payment << " |" << std::endl;
}
void Employee::setWorkTime() {
  this->worktime = std::rand() % 60 + 100;
}
unsigned int Employee::getWorkTime() const { return this->worktime; }
unsigned int Employee::getPayment() const { return this->payment; }
std::string Employee::getName() const { return this->name; }
Position Employee::getPos() const { return this->position; }
unsigned int Project::getId() const { return this->id; }
unsigned int Project::getBudget() const { return this->budget; }
