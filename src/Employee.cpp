// Copyright DB 2021
#include "Employee.h"
#include <utility>

void Employee::setWorkTime(int workTime) {
    Employee::workTime = workTime; 
}

std::string Employee::getPosition() const {
  std::string result;
  if (position == cleaner)
    result = "cleaner";
  else if (position == driver)
    result = "driver";
  else if (position == programmer)
    result = "programmer";
  else if (position == tester)
    result = "tester";
  else if (position == Team_Leader)
    result = "teamleader";
  else if (position == Project_Manager)
    result = "projectmanager";
  else if (position == Senior_Manager)
    result = "seniormanager";
  return result;
}
int Employee::getPayment() const {
    return payment; 
}