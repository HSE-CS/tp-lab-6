// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class IWorkBaseTime {
 public:
	virtual int calcBase(int salary, int wtime) = 0;
	virtual int calcBonus() = 0;
};

class IProjectBudget {
 public:
	virtual int calcBudgetPart(float part, int budget) = 0;
	virtual int calcProAdditions() = 0;
};

class IHeading {
	virtual int calcHeads() = 0;
};

#endif  INCLUDE_INTERFACES_H_
