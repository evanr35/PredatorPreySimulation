//
// Created by Evan Risas on 5/21/18.
//

#ifndef PREDATORPREYSIMULATION_DOODLEBUG_H
#define PREDATORPREYSIMULATION_DOODLEBUG_H


#include "organism.h"
#include "grid.h"

class doodleBug : public organism {
private:
    uint doodleBugTimeSteps;
    uint starvationCounter;
    int seed;

public:
    doodleBug(int x, int y, grid &squareParameter, int Seed);

    int selectSpace();

    virtual std::string toString();

    virtual void move();

    virtual void reproduce();

    int getStepCount();

    void increaseSteps();

    virtual bool isPrey();

    void hunt();

    bool starvedCheck();

    int selectSpaceHunt();

    ~doodleBug();
};


#endif //PREDATORPREYSIMULATION_DOODLEBUG_H
