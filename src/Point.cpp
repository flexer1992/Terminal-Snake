//
// Created by Alex Maximovich on 13.10.2025.
//

#include "Point.h"

Point::Point(int x, int y) : x(x), y(y) {
}

Point::Point() = default;

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::set(int x, int y) {
    this->x = x;
    this->y = y;
}
