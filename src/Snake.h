/* --- Snake.h --- */

#ifndef SNAKE_H
#define SNAKE_H
#pragma once

#include "Point.h"
#include <vector>
#include "Direction.h"
#include "Food.h"

using namespace std;

class Snake {
public:
    Snake();
    Snake(int x, int y, int size, Direction direction, int boardWidth, int boardHeight);
    ~Snake();
    const vector<Point>& getBody() const; // readonly property. return reference to body
    void move(Direction direction, int boardWidth, int boardHeight);
    bool isCollectFood(const Food& food);

    void eatFood(Direction direction, int boardWidth, int boardHeight);
    bool isSelfCollision() const;
    int getScore() const;

private:
    vector<Point> body;
    int initialSize;
};

#endif // SNAKE_H
