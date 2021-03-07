#include "Interfaces.h"
#include "Employee.h"

Employee::Employee(int a, std::string s, std::string d, int b,int c) {
  id = a ;
  name = s;
  position = d;
  payment = b;
  worktime = c
}
void Employee::set_id(int a) {
    id = a;
}
void Employee::set_name(std::string& s) {
    name = s;
}
void Employee::set_worktime(int a) {
    worktime = a;
}
void Employee::set_position(std::string& s) {
  if ((s != "Engineer") && (s != "Cleaner") &&
      (s != "Driver") && (s != "Programmer") &&
      (s != "Tester") && (s != "TeamLeader") &&
      (s != "ProjectManager") && (s != "SeniorManager")) {
    std::cout << "Such a profession does not exist! Try again";
  } else {
    position = s;
  }
}
void Employee::set_payment(int a) {
    payment = a;
}
int Employee::get_id() {
    return id;
}
std::string& Employee::get_name() {
    return name;
}
int Employee::get_worktime() {
    return worktime;
}
std::string Employee::get_position() {
  return position;
}
int Employee::get_payment() {
    return payment;
}

