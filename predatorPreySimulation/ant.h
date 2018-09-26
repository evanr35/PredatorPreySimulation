//
// Created by Evan Risas on 5/21/18.
//

#ifndef PREDATORPREYSIMULATION_ANT_H
#define PREDATORPREYSIMULATION_ANT_H


#include "organism.h"
#include "grid.h"

class ant : public organism {
private:
    int antTimeSteps;
    int seed;

public:
    ant(int x, int y, grid &squareParameter, int Seed);

    int selectSpace();

    virtual std::string toString();

    virtual void move();

    virtual void reproduce();

    int getStepCount();

    void increaseSteps();

    virtual bool isPrey();

    void hunt();

    bool starvedCheck();

    ~ant();
};


#endif //PREDATORPREYSIMULATION_ANT_H
