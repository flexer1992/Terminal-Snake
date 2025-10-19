//
// Created by Alex Maximovich on 15.10.2025.
//
#pragma once


#include "Board.h"
#include "Ansi.h"
#include <iostream>

#include "Direction.h"

class TerminalRenderer {
public:
    TerminalRenderer(const Board& board);

    ~TerminalRenderer();

    void render();
    void clear();
private:
    const Board& board;
    void moveCursor(int x, int y);
    void drawCell(int x, int y, char symbol);
};
