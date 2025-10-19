/* --- Food.cpp --- */

/* ------------------------------------------
author: undefined
date: 12/10/2025
------------------------------------------ */

#include "Food.h"

Food::Food() = default;

Food::Food(int x, int y) : point(x, y) {
}

Food::Food(Point freePoint) {
    point = freePoint;
}

Food::~Food() {
    // Destructor
}

const Point &Food::getPoint() const {
    return point;
}
