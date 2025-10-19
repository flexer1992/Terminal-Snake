/* --- Board.h --- */

/* ------------------------------------------
Author: undefined
Date: 12/10/2025
------------------------------------------ */

#pragma once

#ifndef BOARD_H
#define BOARD_H




#include <vector>
#include <iostream>

#include "Point.h"

using namespace std;

class Board {
public:
    Board(int width, int height);
    int getWidth() const;
    int getHeight() const;

    char getCell(int x, int y) const;
    void setCell(int x, int y, char value);
    char getSymbolAt(int x, int y) const;

    void clear(char fill = '.');
    Point getFreeRandomPoint() const;
    ~Board();

private:
    vector<vector<char>> board;
    int width, height;

    bool isInside(int x, int y) const;
    Point getRandomPoint() const;
};

#endif // BOARD_H
