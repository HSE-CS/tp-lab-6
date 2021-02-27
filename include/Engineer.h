// Copyright 2021 alexgiving

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"
#include "Project.h"

class Engineer : public Personal, public Project {
 private:
  float part = 0;
  Project* project{};

 public:
  explicit Engineer(size_t, std::string, size_t, Project*, size_t, float);
  void setProject(Project*);
  void setPart(float);
  float calc();
  [[nodiscard]] float getPart() const;
  Project* getProject();
};

class Programmer : public Personal, public Project {
 private:
  float part = 0;
  bool deadline = false;
  Project* project{};

 public:
  explicit Programmer(size_t, std::string, size_t, Project*, size_t,
                      float, bool);
  void setProject(Project*);
  void setPart(float);
  void setDeadline(bool);
  float calcProAdittions();
  float calc();
  [[nodiscard]] bool getDeadline() const;
  [[nodiscard]] float getPart() const;
};

class Tester : public Personal, public Project {
 private:
  float part = 0;
  size_t bugs = 0;
  Project* project{};

 public:
  explicit Tester(size_t, std::string, size_t, Project* proj, size_t salary,
                  float, size_t);
  void setProject(Project*);
  void setPart(float);
  void setBugs(size_t);
  float calc();
  unsigned calcProAdittions();
  [[nodiscard]] size_t getBugs() const;
  [[nodiscard]] float getPart() const;
};

class TeamLeader : public Personal, public Project {
 private:
  float part = 0;
  Project* project{};

 public:
  TeamLeader(size_t, std::string, size_t, Project*, size_t);
  void setProject(Project*);
  void setPart(float);
  static size_t calcHeads();
  float calc();
  size_t calcProAdittions();
  [[nodiscard]] float getPart() const;
};
#endif  //  INCLUDE_ENGINEER_H_
