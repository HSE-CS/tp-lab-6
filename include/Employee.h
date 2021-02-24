//// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include "iostream"
#include "string"

class Employee{
 protected:
    int id;
    int worktime = 0;
    double payment = 0;
    double salary = 0;
    std::string name;
    std::string position;

 public:
    Employee();
    Employee(int id, std::string name, std::string position);
    Employee(int id, int worktime, double payment, double salary,
             std::string name, std::string position);
    Employee(const Employee& employee);

    ~Employee();

    void setPayment(double payment);
    void setSalary(double salary);
    void setWorktime(int worktime);
    void setPosition(std::string position);

    [[nodiscard]] int getId() const;
    [[nodiscard]] int getWorktime() const;
    [[nodiscard]] double getSalary() const;
    [[nodiscard]] double getPayment() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getPosition() const;

    virtual int calc() = 0;
    virtual void printInfo() = 0;
};

#endif  //  INCLUDE_EMPLOYEE_H_
