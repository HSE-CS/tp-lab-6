#include "Employee.h"

// Employee::Employee(int _id, std::string _name, std::string _position, int
// _payment) {
//   id = _id;
//   name = _name;
//   position = _position;
//   payment = _payment;
// }

int Employee::getWorktime() { return worktime; }

int Employee::getPayment() { return payment; }

int Employee::getId() { return id; }

std::string Employee::getName() { return name; }

std::string Employee::getPosition() { return position; }
