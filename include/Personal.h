// Copyright 2021 TimurZaytsev
//

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include <string>
#include "Interfaces.h"


class Personal : public Employee, public WorkBaseTime {
public:
	Personal(id_type id, const std::string& name, unsigned int salary);
	~Personal() override = default;
	int calc_base(int salary, int wt) override;

protected:
	unsigned int _salary; 
};

class Cleaner final : public Personal {
public:
	Cleaner(id_type id, const std::string& name, unsigned int salary);

	void calc() override;
	void print_info() override;
	int calc_bonus() override;
};

class Driver final : public Personal {
public:
	Driver(id_type id, const std::string& name, unsigned int salary);

	void calc() override;
	void print_info() override;
	int calc_bonus() override;
};

#endif  // INCLUDE_PERSONAL_H_
