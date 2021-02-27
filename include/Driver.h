// Copyright 2021 alexgiving


#ifndef INCLUDE_DRIVER_H_
#define INCLUDE_DRIVER_H_

#include "Personal.h"
#include <string>

class Driver : public Personal {
 public:
  explicit Driver(size_t, std::string, size_t, size_t);
  [[nodiscard]] size_t calc() const;
  [[nodiscard]] size_t calcBonus() const;
};

#endif  // INCLUDE_DRIVER_H_
