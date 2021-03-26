#ifndef TP_LAB_6_INTERFACES_H
#define TP_LAB_6_INTERFACES_H

class WorkBaseTime
{
public:
    virtual unsigned int calcBase() = 0;
    virtual unsigned int calcBonus() = 0;
};

class ProjectBudget
{
    virtual unsigned int calcBudgetPart(float part) = 0;
    virtual unsigned int calcProAdditions() = 0;
};

class Heading
{
    virtual unsigned int calcHeads() = 0;
};

#endif //TP_LAB_6_INTERFACES_H
