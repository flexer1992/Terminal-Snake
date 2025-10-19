//
// Created by Alex Maximovich on 13.10.2025.
//

#ifndef SNAKEGAME_POINT_H
#define SNAKEGAME_POINT_H
#include "Direction.h"


class Point {

    public:
    Point(int x, int y);

    Point();

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void set(int x, int y);

    private:
        int x = 0;
        int y = 0;
};


#endif //SNAKEGAME_POINT_H