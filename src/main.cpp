//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.
#include <string>
#include "Factory.h"

int main() {
  std::string fileNameE = "./staffInfo.txt";
  std::string fileNameP = "./projectsInfo.txt";
  Factory* myFac = new Factory(fileNameE, fileNameP);
  myFac->readStaff();
  myFac->calcAll();
  myFac->printStaffInfo();
}
