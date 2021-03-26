// Copyright 2021 Krayushkina

#include "Manager.h"
#include <map>
extern std::map<std::string, int> projects;

Manager::Manager(std::string name, unsigned int id,
	std::string position, std::string project, float contribution)
:Employee(name, id) {
	this->position = position;
	this->project = project;
	this->contribution = contribution;
}

float Manager::getPaymentbyProject() {
	return projects[project] * contribution;
}

float Manager::getPayment() {
	payment = getPaymentbyProject();
	return payment;
}

ProjectManager::ProjectManager(std::string name,
	unsigned int id, std::string position, std::string project,
	float contribution, unsigned int subordinates)
	: Manager(name, id, position, project, contribution) {
	this->subordinates = subordinates;
}

float ProjectManager::getPaymentbyHeading() {
	return subordinates * 500;
}

float ProjectManager::getPayment() {
	payment = getPaymentbyProject() + getPaymentbyHeading();
	return payment;
}

SeniorManager::SeniorManager(std::string name, unsigned int id,
	std::string position, std::string project, float contribution,
	unsigned int subordinates)
:ProjectManager(name, id, position, project, contribution,
	subordinates) {}