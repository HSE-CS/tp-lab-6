// Copyright 2021 alexgiving

#ifndef INCLUDE_CLEANER_H
#define INCLUDE_CLEANER_H

#include "Personal.h"

class Cleaner : public Personal {
 public:
  explicit Cleaner(size_t, std::string, size_t, size_t, size_t);
  [[nodiscard]] size_t calc() const;
};

#endif // INCLUDE_CLEANER_H
