//
// Created by Evan Risas on 8/7/18.
//

#ifndef PREDATORPREYSIMULATION_SIMULATOR_H
#define PREDATORPREYSIMULATION_SIMULATOR_H



#include "grid.h"
#include "RandomGenerator.h"


class simulator {
private:
    uint maxSteps;
    uint curStep;
    uint pauseStep;
    uint gridLength;
    int totalAnts;
    int totalDoodleBugs;
    void tick();
public:
    grid board;
    void simulate();
    simulator(uint gridSizeParameter, uint numberOfDoodleBugs, uint numberOfAnts, uint timeLimit, uint seed,
              uint pauseTime, RandomGenerator &randomGenerator);


};

#endif //PREDATORPREYSIMULATION_SIMULATOR_H