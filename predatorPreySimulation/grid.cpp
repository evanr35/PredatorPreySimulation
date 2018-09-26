//
// Created by Evan Risas on 5/21/18.
//

#include "grid.h"
#include "ant.h"
#include "doodleBug.h"

organism *grid::get(int r, int c) {
    return board[getSingleIndex(r, c)];
}

organism *grid::get(int index) {
    return board[index];
}

void grid::set(int r, int c, organism *x) {
    int index = getSingleIndex(r,c);
    if(index==-1){
        return;
    }
    if (get(r, c) != nullptr)
        delete get(r, c);

    board[getSingleIndex(r, c)] = x;
}

void grid::set(int index, organism *x) {
    if(isOutOfBounds(index/gridSize, index % gridSize)){
        return;
    }

    if (get(index) != nullptr) {
        delete board[index];
    }
    board[index] = x;
}

void grid::print() {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (isOccupied(i, j)) {
                std::cout << board[getSingleIndex(i,j)]->toString();
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

}

bool grid::isOccupied(int r, int c) {
    return board[getSingleIndex(r,c)] != nullptr;
}

bool grid::isOccupied(int index) {
    return get(index) != nullptr;
}

int grid::getSingleIndex(int row, int col) {
    int answer = (row * gridSize) + col;
    if(answer<0 || answer>=gridSize*gridSize){
        return -1;
    }
    return answer;
}

int grid::getGridSize() {
    return gridSize;
}

int grid::getRow(int index){
    return index / gridSize;
}

int grid::getCol(int index){
    return index % gridSize;
}

void grid::remove(int index){
    set(index, nullptr);
}

void grid::remove(int r, int c){
    set(getSingleIndex(r,c), nullptr);
}

void grid::safeSet(int index){
    board[index] = nullptr;
}

void grid::safeSet(int r, int c){
    board[r*gridSize+c] = nullptr;
}

bool grid::isOutOfBounds(int row, int column)
{
    return row < 0 || row >= gridSize || column < 0 || column >= gridSize;
}

bool grid::printSummary() {
    std::cout<< "Summary :" << std::endl;


}

grid::grid(int gridSizeParameter) {
    gridSize = gridSizeParameter;
    board = new organism *[gridSize * gridSize];
}

grid::~grid() {
    for (int i = 0; i < gridSize * gridSize; i++) {
        if(board[i]!= nullptr) {
            safeSet(i);
            delete board[i];
        }
    }
    delete[] board;
}
