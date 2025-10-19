/* --- Food.h --- */

/* ------------------------------------------
Author: undefined
Date: 12/10/2025
------------------------------------------ */

#ifndef FOOD_H
#define FOOD_H

#include "Point.h"

class Food {
public:
    Food();
    Food(int x, int y);

    Food(Point point);

    ~Food();
    const Point& getPoint() const;


private:
     Point point;
};

#endif // FOOD_H
