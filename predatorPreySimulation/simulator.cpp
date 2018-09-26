//
// Created by Evan Risas on 8/7/18.
//
#include <vector>
#include "simulator.h"
#include "organism.h"
#include "ant.h"
#include "doodleBug.h"
//#include "RandomGenerator.h"
#include <algorithm>
#include <random>

void simulator::simulate(){
for(int C = 0; C < maxSteps; C++){
    tick();
    if(C == pauseStep && pauseStep!=0){
        board.print();
        std::cout<< "Paused on step " << pauseStep << ", press enter to continue" << std::endl;
        std::string filler;
        std::cin>>filler;
    }
    if(C==maxSteps-1){
        board.printSummary();
        std::cout<< "\n" << "Total steps simulated :"  << maxSteps <<  "\n" << std::endl;
        std::cout<< "Total ants simulated :" << totalAnts<< std::endl;
        std::cout<< "Total doodle bugs simulated :" << totalDoodleBugs<< std::endl;
        board.print();
    }
}
}

void simulator::tick() {
    uint squareSize = gridLength * gridLength;

    //get doodleBugs
    std::vector<organism *> doodleBugs;

    for (int i = 0; i < squareSize; i++) {
        organism *current = board.get(i);
        if (current != nullptr && !current->isPrey()) {
            doodleBugs.push_back(current);
        }
    }

    //check if doodleBug starved, and if not, then let it hunt, move, and possibly reproduce
    for(organism * doodleBug: doodleBugs){
       if( doodleBug->starvedCheck()){
           board.remove(doodleBug->row(),doodleBug->col());
           continue;
       }
        doodleBug->increaseSteps();
        doodleBug->hunt();
        doodleBug->move();
        if(doodleBug->getStepCount()%8==0){
            doodleBug->reproduce();
            totalDoodleBugs++;
        }
    }

    //get ants
   std::vector<organism *> ants;

    for (int i = 0; i < squareSize; i++) {
        organism *current = board.get(i);
        if(current==nullptr){
            continue;
        }
        if (current->isPrey()) {
            ants.push_back(current);
        }

    }

    //ants move, then breed
    for(organism *currentAnt: ants){
        currentAnt->increaseSteps();
        currentAnt->move();
        if(currentAnt->getStepCount()%3==0) {
            currentAnt->reproduce();
            totalAnts++;
        }

    }
}

simulator::simulator(uint gridSizeParameter, uint numberOfDoodleBugs, uint numberOfAnts, uint timeLimit, uint seed,
                     uint pauseTime, RandomGenerator &randomGenerator) : maxSteps(timeLimit), curStep(0), pauseStep(pauseTime),
                                       gridLength(gridSizeParameter), board(gridLength) {
    uint squareSize = gridLength * gridLength;
    totalAnts = 0;
    totalDoodleBugs = 0;

    std::vector<uint> freeCells; //initialize vector of positive ints
    for (int i = 0; i < squareSize; i++) {
        freeCells.push_back(i); //put all cell numbers into vector
    }
    //shuffle vector
   randomGenerator.shuffle(freeCells);

          //does not work
  //  auto rng = std::default_random_engine{};
   // std::shuffle(freeCells.begin(), freeCells.end(), rng);

    //fill with ants
    for (int i = 0; i < numberOfAnts; i++) {
        uint curCell = freeCells.back();
        freeCells.pop_back();
        //set them om board;
        board.set(curCell, new ant(curCell / gridLength, curCell % gridLength, board, 0));
        totalAnts++;
    }

    //fill with doodleBugs
    for (int i = 0; i < numberOfDoodleBugs; i++) {
        uint curCell = freeCells.back();
        freeCells.pop_back();
        //set them om board;
        board.set(curCell, new doodleBug(curCell / gridLength, curCell % gridLength, board, 0));
        totalDoodleBugs++;
    }

}

