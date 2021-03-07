#include "Manager.h"

#include <cmath>
#include <fstream>
#include <string>

#include "Engineer.h"

ProjectManager::ProjectManager(int a, const std::string s, std::string d, int N, int b, int c, const std::vector<Project *> &p) : Employee (int a, std::string s, std::string d, int b, int c) {
  for (size_t i = 0; i < N; i++) {
    project.push_back(p[i]);
  }
}
int ProjectManager::calcHeads() { return 1000; }
int ProjectManager::calcProAdditions() { return calcHeads(); }
int ProjectManager::calc() {
  return get_payment() * get_worktime() + calcProAdditions() + calcHeads();
}
void ProjectManager::printInfo() {
  std::cout << std::endl
            << this->get_id() << " - " << this->get_name() << " - "
            << this->get_position() << "\nWorktime = " << this->get_worktime()
            << "\nFinal payment = " << this->calc() << std::endl;
}
SeniorManager::SeniorManager(int a, std::string s, std::string d, int N, int b, int c, const std::vector<Project *> &p) : ProjectManager(a, s, d, N, b, c, p) {
}
int SeniorManager::calc() {
  return ProjectManager::calc();
}
void SeniorManager::printInfo() {
  std::cout << std::endl
            << this->get_id() << " - " << this->get_name() << " - "
            << this->get_position() << "\nWorktime = " << this->get_worktime()
            << "\nFinal payment = " << this->calc() << std::endl;
}

