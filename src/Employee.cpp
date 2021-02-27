// Copyright [2021] <Roman Balayan>

#include "Employee.h"

Employee::Employee(unsigned int id,
                    std::string name,
                    Position position,
                    unsigned int worktime,
                    unsigned int payment)
    : id(id)
    , name(name)
    , position(position)
    , worktime(worktime)
    , payment(payment) {

}

void Employee::setWorkTime(unsigned int worktime) {
    this->worktime = worktime;
}

void Employee::setPayment(unsigned int payment) {
    this->payment = payment;
}
