// Copyright 2021
#ifndef INCLUDE_WORKBASETIME_H_
#define INCLUDE_WORKBASETIME_H_

class WorkBaseTime {

    virtual double calcBase(int wtime) = 0;
    virtual double calcBonus() = 0;
};
#endif  // !INCLUDE_WORKBASETIME_H_
