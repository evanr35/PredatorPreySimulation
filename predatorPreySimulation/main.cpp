#include <iostream>

#include "simulator.h"


int main() {
    int gridSize; //def 20
    int numDoodleBugs; //def 5
    int numAnts; //def 100
    int timeSteps; //def 1000
    int seed; //def 1
    int pause; //def 0

    // add in print summary method
    // 2 simplify code
    // 3 determine neccesity of having two of each methods


    inputError:
    std::cout << "Enter the length of the grid: " << std::endl;
    std::cin >> gridSize;
    std::cout << "Enter the number of doodle bugs: " << std::endl;
    std::cin >> numDoodleBugs;
    std::cout << "Enter the number of ants: " << std::endl;
    std::cin >> numAnts;
    std::cout << "Enter the number of steps to play: " << std::endl;
    std::cin >> timeSteps;
    std::cout << "Enter the seed for the RNG: " << std::endl;
    std::cin >> seed;
    std::cout << "Enter the step you would like to pause at (0 for no pause): " << std::endl;
    std::cin >> pause;

    if ((numAnts + numDoodleBugs) > gridSize * gridSize) {
        std::cout << "A grid of " + std::to_string(gridSize) + " by " + std::to_string(gridSize) +
                     " can't contain that many organisms." << std::endl;
        goto inputError;
    }

    if(numAnts < 0 || numDoodleBugs < 0 || timeSteps < 0 || pause < 0){
        std::cout << "All fields must be integers greater than or equal to 0" << std::endl;
        goto inputError;
    }

    RandomGenerator randomGenerator(seed);
    simulator sim(gridSize,numDoodleBugs,numAnts,timeSteps,seed,pause, randomGenerator);
    sim.simulate();

    return 0;
}