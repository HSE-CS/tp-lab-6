// Copyright 2021 Krayushkina

#pragma once
#define INTERFACES_H
#ifdef INTERFACES_H
class WorkBaseTime {
 public:
	virtual float getPaymentbyWorkTime() = 0;
};
class ProjectBudget {
 public:
	virtual float getPaymentbyProject() = 0;
};
class Heading {
 public:
	virtual float getPaymentbyHeading() = 0;
};
#endif // INTERFACES_H