// Copyright 2021 asma
#include "Project.h"

Project::Project(int _id, int _budget, int _senior_id) {
    id = _id;
    budget = _budget;
    senior_id = _senior_id;
}

int Project::GetBudget() const {
    return budget;
}
