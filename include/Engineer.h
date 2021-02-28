// Copyright 2021 TimurZaytsev
//

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Interfaces.h"
#include "Personal.h"


class Engineer : public Personal, public ProjectBudget {
 public:
    Engineer(id_type id, const std::string& name,
        unsigned int salary,
        const Project& p);
    ~Engineer() override = default;

    void calc() override;
    int calc_budget_part(float part, int budget) override;

 protected:
    Project _project;
};

class Tester final : public Engineer {
 public:
    Tester(id_type id, const std::string& name,
        unsigned int salary,
        const Project& p);

    void print_info() override;
    int calc_pro_additions() override;
    int calc_bonus() override;
};

class Programmer : public Engineer {
 public:
    Programmer(id_type id, const std::string& name,
        unsigned int salary,
        const Project& p);

    void print_info() override;
    int calc_pro_additions() override;
    int calc_bonus() override;
};

class TeamLeader final : public Programmer, public Heading {
 public:
    TeamLeader(id_type id, const std::string& name,
        unsigned int salary,
        const Project& p);

    void calc() override;
    int calc_heads() override;
    void print_info() override;
};

#endif  // INCLUDE_ENGINEER_H_
