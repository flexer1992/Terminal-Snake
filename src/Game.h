/* --- Game.h --- */

/* ------------------------------------------
Author: undefined
Date: 12/10/2025
------------------------------------------ */

#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "TerminalRenderer.h"

#include <iostream>

#include "Food.h"
#include "InputHandler.h"
#include "Snake.h"

class Game {
public:
    Game(Board& board, TerminalRenderer& renderer);
    void run(); // запускаем игровой цикл
    ~Game();

private:
    Board& board;
    TerminalRenderer renderer;
    int tickDelayMs = 100;
    InputHandler input;
    Food food;
    Snake snake;
    Direction direction;

    void generateFood();
    void generateSnake();
};

#endif // GAME_H
