//
// Created by Evan Risas on 5/21/18.
//

#include "organism.h"

organism::organism(int x, grid &squareParameter, int y, int Seed) :
        r(x), c(y), board(squareParameter) {
}

int organism::row() {
    return r;
}

int organism::col() {
    return c;
}

bool organism::isPrey() {
    return false;
}
