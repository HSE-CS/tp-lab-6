// Copyright 2021 Ksuvot
#include "Manager.h"

int ProjectManager::calcHeads() {
  return 1500;
}

void ProjectManager::calc() {
  setPayment(5000 + calcHeads());
}

void SeniorManager::calc() {
  setPayment(10000 + calcHeads());
}
