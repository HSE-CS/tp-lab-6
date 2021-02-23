// Copyright 2021 Smirnov Grigory
#include "../include/Manager.h"

int ProjectManager::getSubbordinates() {
	return subordinates;
}

int ProjectManager::calcHeads() {
	return getSubbordinates() * 1000;
}

void ProjectManager::calc() {
	setPayment(50000 + calcHeads());
}

void SeniorManager::calc() {
	setPayment(90000 + calcHeads());
}

void ProjectManager::printInfo() {
	std::cout << getName() + " " + std::to_string(getId())
		 + " " + std::to_string(getPayment());
}
