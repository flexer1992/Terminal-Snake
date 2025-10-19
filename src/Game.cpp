/* --- Game.cpp --- */

/* ------------------------------------------
author: undefined
date: 12/10/2025
------------------------------------------ */

#include "Game.h"

#include <thread>


Game::Game(Board &board, TerminalRenderer &renderer) : board(board), renderer(renderer) {
    generateFood();
    generateSnake();
    direction = Direction::Right;
}

void Game::run() {
    std::cout << "Starting game loop" << std::endl;
    // renderer.clear(); //
    while (true) {
        board.clear();


        auto foodPoint = food.getPoint();
        board.setCell(foodPoint.getX(), foodPoint.getY(), 'O');

        for (const Point &segment: snake.getBody()) {
            board.setCell(segment.getX(), segment.getY(), '*');
        }

        auto key = input.pollKey();

        if (key.has_value()) {
            switch (key.value()) {
                case 'q':
                    return;
                case 'w':
                    direction = Direction::Up;
                    break;
                case 's':
                    direction = Direction::Down;
                    break;
                case 'a':
                    direction = Direction::Left;
                    break;
                case 'd':
                    direction = Direction::Right;
                    break;
            }
        }

        renderer.render(); // отрисовать текущее состояние


        if (snake.isCollectFood(food)) {
            snake.eatFood(direction, board.getWidth(), board.getHeight());
            generateFood();
        }

        snake.move(direction, board.getWidth(), board.getHeight());


        if (snake.isSelfCollision()) {
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(tickDelayMs));
    }

    std::cout << "Game over. Your score: " << snake.getScore() << std::endl;
}

Game::~Game() {
    // Destructor
}

void Game::generateFood() {
    auto randomPoint = board.getFreeRandomPoint();
    food = Food(randomPoint);
}

void Game::generateSnake() {
    auto randomPoint = board.getFreeRandomPoint();
    int x = randomPoint.getX();
    int y = randomPoint.getY();
    snake = Snake(x, y, 3, Direction::Left, board.getWidth(), board.getHeight());
}
