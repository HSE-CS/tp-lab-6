#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "Engineer.h"
#include "Manager.h"
#include "Staff.h"

std::vector<std::unique_ptr<Employee>> makeStaff() {
  std::fstream file("staff.txt");
  std::vector<std::unique_ptr<Employee>> output;
  while (!file.eof()) {
    std::string job, firstname, surname;
    uint32_t id;
    file >> id >> job >> firstname >> surname;
    if (job == "Janitor") {
      Janitor e(id, firstname, surname);
      std::unique_ptr<Employee> ptr(&e);
      output.push_back(ptr);
    } else if (job == "Driver") {
      Driver e(id, firstname, surname);
      std::unique_ptr<Employee> ptr(&e);
      output.push_back(ptr);
    } else if (job == "Programmer") {
      Programmer e(id, firstname, surname);
      std::unique_ptr<Employee> ptr(&e);
      output.push_back(ptr);
    } else if (job == "Tester") {
      Tester e(id, firstname, surname);
      std::unique_ptr<Employee> ptr(&e);
      output.push_back(ptr);
    } else if (job == "ProjectManager") {
      ProjectManager e(id, firstname, surname);
      std::unique_ptr<Employee> ptr(&e);
      output.push_back(ptr);
    } else if (job == "SeniorManager") {
      SeniorManager e(id, firstname, surname);
      std::unique_ptr<Employee> ptr(&e);
      output.push_back(ptr);
    } else if (job == "TeamLeader") {
      TeamLeader e(id, firstname, surname);
      std::unique_ptr<Employee> ptr(&e);
      output.push_back(ptr);
    }
  }
}

int main() {
  // создание штата сотрудников на основе файла
  std::vector<std::unique_ptr<Employee>> staff = makeStaff();

  // присвоение отработанного времени
  for (auto& emp : staff) {
    emp->setWorkTime(100);
  }

  // расчет зарплаты
  for (auto& emp : staff) {
    emp->calc();
  }

  // вывод данных о зарплате
  for (auto& emp : staff) {
    emp->printInfo();
  }
  return 0;
}
