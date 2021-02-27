// Copyright 2021 alexgiving

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Personal.h"
#include "Project.h"
#include <string>
#include <vector>

class ProjectManager : public Personal, public Project {
 private:
  float part = 0;
  size_t heads = 0;
  std::vector<Project*> *projects{};

 public:
  ProjectManager();
  ProjectManager(size_t, std::string, size_t, Project* proj, size_t);
  void setProject(Project*);
  void setPart(float);
  void calcHeads(size_t);
  float calcPM();
  std::vector<Project*>* getProjects();
  [[nodiscard]] float getPart() const;
  [[nodiscard]] size_t getHeads() const;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager();
  SeniorManager(size_t, std::string, size_t, std::vector<Project *>*);
  size_t calc();
};

#endif //  INCLUDE_MANAGER_H_
