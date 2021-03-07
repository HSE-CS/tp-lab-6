// Copyright 2021 Tatsenko Alexey
#include "Engineer.h"

Engineer::Engineer(int id, std::string fi, Position position,
                   int salary_per_hour, Project* project, float part)
    : project(project),
      part(part),
      Personal(id, fi, position, salary_per_hour) {
  this->project->add_student(this);
}

float Engineer::get_part() { return this->part; }

int Engineer::calc_budjet_part(float part, int budjet) {
  return static_cast<int>(budjet * part);
}
int Engineer::calc_pro_additions() {
  if (this->part > 0.11) {
    return static_cast<int>(300 * this->get_part());
  } else {
    return 0;
  }
}
void Engineer::calc() {
  this->set_payment(
      this->salary_per_hour * this->get_work_time() +
      this->calc_budjet_part(this->get_part(), this->project->get_budjet()) +
      this->calc_pro_additions());
}

Tester::Tester(int id, std::string fi, Position position, int salary_per_hour,
               Project* project, float part, int number_find_errors)
    : Engineer(id, fi, position, salary_per_hour, project, part) {
  this->number_find_errors = number_find_errors;
}

int Tester::calc_pro_additions() { return 100 * this->number_find_errors; }

Programmer::Programmer(int id, std::string fi, Position position,
                       int salary_per_hour, Project* project, float part)
    : Engineer(id, fi, position, salary_per_hour, project, part) {}

int Programmer::calc_pro_additions() {
  if (this->get_work_time() < this->get_avatage_time()) {
    return (
        this->calc_base(this->salary_per_hour,
                        ((get_avatage_time() - this->get_work_time()) * 3000)));
  } else {
    return 0;
  }
}

TeamLeader::TeamLeader(int id, std::string fi, Position position,
                       int salary_per_hour, Project* project, float part)
    : Programmer(id, fi, position, salary_per_hour, project, part) {}

int TeamLeader::calc_heads() {
  return (this->project->get_number_of_emp()) * 300;
}

void TeamLeader::calc() {
  this->set_payment(
      this->salary_per_hour * this->get_work_time() +
      this->calc_budjet_part(this->get_part(), this->project->get_budjet()) +
      this->calc_heads());
}
