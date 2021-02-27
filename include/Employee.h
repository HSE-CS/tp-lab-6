// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 08.02.2021.
//

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

typedef uint64_t id_type;

enum class Position {
  Driver,
  Cleaner,
  Tester,
  Programmer,
  TeamLeader,
  ProjectManager,
  SeniorManager
};


struct Project {
  std::string _id;
  int _budget;
};


class Employee {
 public:
  Employee(id_type id, const std::string& name);
  virtual ~Employee() = default;

  void set_worktime(unsigned int wt);

  virtual void calc() = 0;
  virtual void print_info() = 0;

  friend class StaffFactory;

 protected:
  id_type _id;
  std::string _name;
  Position _position;
  unsigned int _payment;
  unsigned int _worktime;
};

#endif  // INCLUDE_EMPLOYEE_H_
