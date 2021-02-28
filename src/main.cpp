#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"

int main() {
  Tester* emp = new Tester;
  emp->setWorkTime(30);
  emp->setSalary(100);
  std::cout << emp->calcBase() << emp->calcProAdditions();
  Programmer* prg = new Programmer;
  Cleaner* cln = new Cleaner;
  Driver* drv = new Driver;
  ProjectManager* mng = new ProjectManager;
  return 0;
}
