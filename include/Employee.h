//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <string>

class Project {
 public:
  explicit Project(std::string id, int budget);
  std::string id;
  int budget;
};

class Employee {
 public:
  explicit Employee(int id, std::string name,
                    std::string position, int payment);
  Employee(int id, const std::string& name,
           const std::string& position);
  ~Employee();
  Employee(const Employee& newE);
  /* Setters */
  void setWorkTime(int workTime);
  void setSalary(int sal);
  /* Virtual funcs */
  virtual int calc() = 0;
  virtual void printInfo() = 0;
  /* Getters */
  [[nodiscard]] int getWorkTime() const;
  [[nodiscard]] int getPayment() const;
  [[nodiscard]] int getId() const;
  std::string &getName();
  std::string &getPosition();
  [[nodiscard]] int getSalary() const;

 private:
  int id;
  std::string name;
  std::string position;
  int worktime = 0;
  int payment = 0;
  int salary = 0;
};

#endif  //  INCLUDE_EMPLOYEE_H_
