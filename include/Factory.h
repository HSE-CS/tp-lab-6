#include "headers.h"

class Project {
 public:
  int is;
  std::string name;
  int budget;
  Project(int is, std::string name, int budget)
      : is(is), name(std::move(name)), budget(budget) {}
};
