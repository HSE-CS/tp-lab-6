// Copyright 2020 S. BOR
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 public:
	virtual unsigned calcBase() = 0;
	virtual unsigned calcBonus(unsigned overtimeJob, unsigned cost) = 0;
};

class ProjectBudget {
 public:
	virtual unsigned calcBudgetPart(float part, int budget) = 0;
	virtual unsigned calcProAdditions() = 0;
};

class Heading {
 public:
	virtual unsigned calcHeads(int numberOfWorkers) = 0;
};

struct Project {
	unsigned id;
	unsigned budget;	
};


#endif  // INCLUDE_INTERFACES_H_
