//
// Created by Evan Risas on 5/21/18.
//

#include "ant.h"
#include "RandomGenerator.h"

std::string ant::toString() {
    return "O";
}

int ant::selectSpace() {
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

void ant::move() {
    int space = selectSpace();
    if (space == -1) {
        return;
    }
    board.safeSet(r, c); //set to null after ant moves out of space
    this->r = space / board.getGridSize();
    this->c = space % board.getGridSize();
    board.set(space, this);
}

void ant::reproduce() {
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
        board.set(space, new ant(space / board.getGridSize(), space % board.getGridSize(), board, 0));
    } else {
        antTimeSteps--;
    }
}

void ant::increaseSteps() {
    antTimeSteps++;
}

int ant::getStepCount() {
    return antTimeSteps;
}

bool ant::isPrey() {
    return true;
}

void ant::hunt() {
}

bool ant::starvedCheck() {
    return false;
}

ant::ant(int x, int y, grid &squareParameter, int Seed) : organism(x, squareParameter, y, Seed) {
    antTimeSteps = 0;
    //seed = Seed;
}

ant::~ant() {}
