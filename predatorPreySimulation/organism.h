//
// Created by Evan Risas on 5/21/18.
//

#ifndef PREDATORPREYSIMULATION_ORGANISM_H
#define PREDATORPREYSIMULATION_ORGANISM_H


#include <string>
#include "grid.h"

class organism {
protected:
    int r;
    int c;
    grid& board;
public:
    organism(int x, grid &squareParameter, int y, int Seed);
    virtual void move() = 0;
    virtual std::string toString() = 0;
    virtual void reproduce() = 0;
    virtual bool isPrey();
    virtual void hunt()=0;
    virtual bool starvedCheck()=0;
    virtual int getStepCount()=0;
    virtual void increaseSteps()=0;
    virtual ~organism() = default;
    int row();
    int col();
};


#endif //PREDATORPREYSIMULATION_ORGANISM_H
