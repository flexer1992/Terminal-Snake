/* --- Snake.cpp --- */

/* ------------------------------------------
author: undefined
date: 12/10/2025
------------------------------------------ */

#include "Snake.h"
#include <iostream>
#include <vector>

using namespace std;

Snake::Snake() {
    // Constructor
}

int wrap(int value, int max) {
    return (value + max) % max;
}


Snake::Snake(int x, int y, int size, Direction direction, int boardWidth, int boardHeight) {
    initialSize = size;
    body.reserve(size);

    auto [dx, dy] = toDelta(direction);
    for (int i = 0; i < size; ++i) {
        int px = wrap(x + dx * i, boardWidth);
        int py = wrap(y + dy * i, boardHeight);
        body.emplace_back(px, py);
    }

    std::cout << "Snake segments:\n";
    for (const auto &p: body) {
        std::cout << "(" << p.getX() << ", " << p.getY() << ")\n";
    }
}

Snake::~Snake() {
    // Destructor
}

const vector<Point> &Snake::getBody() const {
    return body;
}

void Snake::move(Direction direction, int boardWidth, int boardHeight) {
    auto [dx, dy] = toDelta(direction);

    Point head = body.front();

    int newX = wrap(head.getX() + dx, boardWidth);
    int newY = wrap(head.getY() + dy, boardHeight);

    Point newHead(newX, newY);

    body.insert(body.begin(), newHead); // добавить голову
    body.pop_back(); // удалить хвост
}


bool Snake::isCollectFood(const Food &food) {
    auto foodPoint = food.getPoint();

    Point head = body.front();

    if (head.getX() == foodPoint.getX() && head.getY() == foodPoint.getY()) {
        return true;
    }

    return false;
}

void Snake::eatFood(Direction direction, int boardWidth, int boardHeight) {
    auto [dx, dy] = toDelta(direction);

    const Point &tail = body.back();
    int newX = wrap(tail.getX() - dx, boardWidth);
    int newY = wrap(tail.getY() - dy, boardHeight);

    body.emplace_back(newX, newY);
}

bool Snake::isSelfCollision() const {
    const Point &head = body.front();

    return std::any_of(body.begin() + 1, body.end(), [&](const Point &p) {
        return p.getX() == head.getX() && p.getY() == head.getY();
    });
}

int Snake::getScore() const {
    return body.size() - initialSize;
}
