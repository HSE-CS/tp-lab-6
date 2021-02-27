#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "Employee.h"
#include "Engineer.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Staff.h"

TEST(Driver, creation) {
  uint32_t id(1), salary(1);
  std::string firstname("A"), surname("B");
  Driver d(id, firstname, surname, salary);
}

TEST(Driver, calc_bonus) {
  uint32_t id(1), salary(1);
  std::string firstname("A"), surname("B");
  Driver d(id, firstname, surname, salary);
  ASSERT_EQ(d.calcBonus(), BONUS);
}

TEST(Staff, calc_base) {
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Driver d(id, firstname, surname, salary);
  d.setWorkTime(worktime);
  ASSERT_EQ(d.calcBase(salary, worktime), salary * worktime);
}

TEST(Janitor, creation) {
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Janitor j(id, firstname, surname, salary);
}

TEST(Janitor, calc_bonus) {
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Janitor j(id, firstname, surname, salary);
  ASSERT_EQ(j.calcBonus(), 0);
}

TEST(Programmer, creation) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Programmer p(id, firstname, surname, salary, project);
}

TEST(Programmer, calc_bonus) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Programmer p(id, firstname, surname, salary, project);
  ASSERT_EQ(p.calcBonus(), BONUS);
}

TEST(Programmer, calc_pro_additions) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Programmer p(id, firstname, surname, salary, project);
  ASSERT_EQ(p.calcProAdditions(), PROGRAMMER_PRO_ADDITIONS);
}

TEST(Programmer, calc_budget) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Programmer p(id, firstname, surname, salary, project);
  ASSERT_EQ(p.calcBudgetPart(0.2, 100), 20);
}

TEST(Tester, creation) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Tester p(id, firstname, surname, salary, project);
}

TEST(Tester, calc_bonus) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Tester p(id, firstname, surname, salary, project);
  ASSERT_EQ(p.calcBonus(), BONUS);
}

TEST(Tester, calc_pro_additons) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  Tester p(id, firstname, surname, salary, project);
  ASSERT_EQ(p.calcProAdditions(), TESTER_PRO_ADDITIONS);
}

TEST(TeamLeader, creation) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  TeamLeader p(id, firstname, surname, salary, project);
}

TEST(TeamLeader, calc_bonus) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  TeamLeader p(id, firstname, surname, salary, project);
  ASSERT_EQ(p.calcBonus(), BONUS);
}

TEST(TeamLeader, calc_pro_additons) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  TeamLeader p(id, firstname, surname, salary, project);
  ASSERT_EQ(p.calcProAdditions(), PROGRAMMER_PRO_ADDITIONS);
}

TEST(TeamLeader, calc_heads) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1), salary(1), worktime(10);
  std::string firstname("A"), surname("B");
  TeamLeader p(id, firstname, surname, salary, project);
  ASSERT_EQ(p.calcHeads(), TEAMLEADER_PER_HEAD * project.staff_num);
}

TEST(ProjectManager, creation) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1);
  std::string firstname("A"), surname("B");
  ProjectManager p(id, firstname, surname, project);
}

TEST(ProjectManager, calc_heads) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1);
  std::string firstname("A"), surname("B");
  ProjectManager p(id, firstname, surname, project);
  ASSERT_EQ(p.calcHeads(), project.staff_num * MANAGER_PER_HEAD);
}
TEST(ProjectManager, calc_pro_additons) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  uint32_t id(1);
  std::string firstname("A"), surname("B");
  ProjectManager p(id, firstname, surname, project);
  ASSERT_EQ(p.calcProAdditions(), MANAGER_PRO_ADDITIONS);
}

TEST(SeniorManager, creation) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  std::vector<Project> v;
  v.push_back(project);
  uint32_t id(1);
  std::string firstname("A"), surname("B");
  SeniorManager p(id, firstname, surname, v);
}

TEST(SeniorManager, calc_pro_additions) {
  Project project{.id = 1, .budget = 100, .staff_num = 5};
  std::vector<Project> v;
  v.push_back(project);
  uint32_t id(1);
  std::string firstname("A"), surname("B");
  SeniorManager p(id, firstname, surname, v);
  ASSERT_EQ(p.calcProAdditions(), MANAGER_PRO_ADDITIONS);
}

TEST(SeniorManager, calc_heads) {
  Project project1{.id = 1, .budget = 100, .staff_num = 5};
  Project project2{.id = 1, .budget = 100, .staff_num = 1};
  std::vector<Project> v;
  v.push_back(project1);
  v.push_back(project2);
  uint32_t id(1);
  std::string firstname("A"), surname("B");
  SeniorManager p(id, firstname, surname, v);
  ASSERT_EQ(p.calcHeads(), MANAGER_PER_HEAD * project1.staff_num +
                               MANAGER_PER_HEAD * project2.staff_num);
}
