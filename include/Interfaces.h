//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_INTERFACES_H
#define TP_LAB_6_INTERFACES_H

class IWorkBaseTime{
    virtual int calcBase(int salary, int wtime)=0;
    virtual int calcBonus()=0;
};

class IProjectBudget{
    virtual int calcBudgetPart(float part, int budget)=0;
    virtual int calcProAdditions()=0;
};

class IHeading{
    virtual int calcHeads()=0;
};

#endif //TP_LAB_6_INTERFACES_H
