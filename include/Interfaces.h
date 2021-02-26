//  Copyright Baklanov 2021
#ifndef SOMETH
#define SOMETH

class WorkBaseTime {
    virtual int calcBase(int salary, int wtime) = 0;
    virtual int calcBonus() = 0;
};

class ProjectBudget {
    virtual int calcBudjetPart(float part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

class Heading {
    virtual int calcHeads() = 0;
};

#endif
