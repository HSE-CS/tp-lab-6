// Copyright 2021 Dev-will-work
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"

enum class FileFormat {
  TXT, JSON, XML
};

class StaffFactory {
 public:
  explicit StaffFactory(std::string filename = "input.txt",
    FileFormat format = FileFormat::TXT);
  ~StaffFactory();
  std::vector<Employee*> makeStaff();

 private:
  std::string filename = "input.txt";
  FileFormat format = FileFormat::TXT;
};
#endif  // INCLUDE_FACTORY_H_
