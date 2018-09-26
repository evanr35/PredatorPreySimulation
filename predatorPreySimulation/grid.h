//
// Created by Evan Risas on 5/21/18.
//

#ifndef PREDATORPREYSIMULATION_GRID_H
#define PREDATORPREYSIMULATION_GRID_H


#include <iostream>
//#include "organism.h"


typedef unsigned int uint;
class organism;

class grid {
private:
    organism** board;
    int gridSize;
public:
    grid(int gridSizeParameter);

    ~grid();

    organism* get(int r, int c);

    void set(int r, int c, organism* x);

    bool isOccupied(int r, int c);

    void print();

    int getSingleIndex(int row, int col);

    organism* get(int index);

    bool isOccupied(int index);

    void set(int index, organism* x);

    int getGridSize();

    int getRow(int index);

    int getCol(int index);

    void remove(int index);

    void remove(int r, int c);

    void safeSet(int index);

    void safeSet(int r, int c);

    bool isOutOfBounds(int row, int column);

    bool printSummary();
};


#endif //PREDATORPREYSIMULATION_GRID_H
