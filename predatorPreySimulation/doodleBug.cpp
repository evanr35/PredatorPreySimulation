//
// Created by Evan Risas on 5/21/18.
//

#include "doodleBug.h"
#include "RandomGenerator.h"

std::string doodleBug::toString() {
    return "X";
}

int doodleBug::selectSpace() {
    int spaceList[4];
    int counter = 0;
    int right = board.getSingleIndex(r, c + 1);
    int left = board.getSingleIndex(r, c - 1);
    int up = board.getSingleIndex(r - 1, c);
    int down = board.getSingleIndex(r + 1, c);

    if (!board.isOutOfBounds(r, c + 1) && !board.isOccupied(right)) {//right is clear
        spaceList[counter] = right;
        counter = counter + 1;
    }

    if (!board.isOutOfBounds(r, c - 1) && !board.isOccupied(left)) {//left is clear
        spaceList[counter] = left;
        counter = counter + 1;
    }

    if (!board.isOutOfBounds(r - 1, c) && !board.isOccupied(up)) {//up is clear
        spaceList[counter] = up;
        counter = counter + 1;
    }

    if (!board.isOutOfBounds(r + 1, c) && !board.isOccupied(down)) {//down is clear
        spaceList[counter] = down;
        counter = counter + 1;
    }

    if (counter != 0) {
        RandomGenerator rng(seed);
        int random = rng.getRandomInt(counter);
        return spaceList[random];
    } else {
        return -1;
    }

}

int doodleBug::selectSpaceHunt() {
    int spaceList[4];
    int counter = 0;
    int right = board.getSingleIndex(r, c + 1);
    int left = board.getSingleIndex(r, c - 1);
    int up = board.getSingleIndex(r - 1, c);
    int down = board.getSingleIndex(r + 1, c);

    if (!board.isOutOfBounds(r, c + 1) && board.isOccupied(right) && board.get(right)->isPrey()) {//right is clear
        spaceList[counter] = right;
        counter = counter + 1;
    }

    if (!board.isOutOfBounds(r, c - 1) && board.isOccupied(left) && board.get(left)->isPrey()) {//left is clear
        spaceList[counter] = left;
        counter = counter + 1;
    }

    if (!board.isOutOfBounds(r - 1, c) && board.isOccupied(up) && board.get(up)->isPrey()) {//up is clear
        spaceList[counter] = up;
        counter = counter + 1;
    }

    if (!board.isOutOfBounds(r + 1, c) && board.isOccupied(down) && board.get(down)->isPrey()) {//down is clear
        spaceList[counter] = down;
        counter = counter + 1;
    }

    if (counter != 0) {
        RandomGenerator rng(seed);
        int random = rng.getRandomInt(counter);
        return spaceList[random];
    } else {
        return -1;
    }

}


void doodleBug::move() {
    int space = selectSpace();
    if (space == -1) {
        return;
    }
    board.safeSet(r, c); //set to null after doodleBUG moves out of space
    this->r = space / board.getGridSize();
    this->c = space % board.getGridSize();
    board.set(space, this);
}

void doodleBug::reproduce() {
    int spaceList[4];
    int counter = 0;
    int right = board.getSingleIndex(r, c + 1);
    int left = board.getSingleIndex(r, c - 1);
    int up = board.getSingleIndex(r - 1, c);
    int down = board.getSingleIndex(r + 1, c);

    if (!board.isOutOfBounds(r, c + 1) && !board.isOccupied(right)) {//right is clear
        spaceList[counter] = right;
        counter = counter + 1;
    }

    if (!board.isOutOfBounds(r, c - 1) && !board.isOccupied(left)) {//left is clear
        spaceList[counter] = left;
        counter = counter + 1;
    }

    if (!board.isOutOfBounds(r - 1, c) && !board.isOccupied(up)) {//up is clear
        spaceList[counter] = up;
        counter = counter + 1;
    }

    if (!board.isOutOfBounds(r + 1, c) && !board.isOccupied(down)) {//down is clear
        spaceList[counter] = down;
        counter = counter + 1;
    }

    if (counter != 0) {
        RandomGenerator rng(seed);
        int random = rng.getRandomInt(counter);
        int space = spaceList[random];
        board.set(space, new doodleBug(space / board.getGridSize(), space % board.getGridSize(), board, 0));
    } else {
        doodleBugTimeSteps--;
    }
}


void doodleBug::increaseSteps() {
    doodleBugTimeSteps++;
    starvationCounter++;
}


int doodleBug::getStepCount() {
    return doodleBugTimeSteps;
}

bool doodleBug::isPrey() {
    return false;
}

void doodleBug::hunt() {
    int space = selectSpaceHunt();
    if (space == -1) {
        return;
    }
    organism *organism = board.get(space);
    if (organism != nullptr && organism->isPrey()) {
        delete organism;
        board.safeSet(space);
        this->starvationCounter = 0;
    }
}

bool doodleBug::starvedCheck() {
    return starvationCounter >= 2;
}

doodleBug::doodleBug(int x, int y, grid &squareParameter, int Seed) : organism(x, squareParameter, y, Seed) {
    doodleBugTimeSteps = 0;
    starvationCounter = 0;
  //  seed = Seed;
}

doodleBug::~doodleBug() {}