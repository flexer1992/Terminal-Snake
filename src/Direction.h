//
// Created by Alex Maximovich on 13.10.2025.
//

#ifndef SNAKEGAME_DIRECTION_H
#define SNAKEGAME_DIRECTION_H
#pragma once
#include <__utility/pair.h>


enum class Direction {
    Up = 0,
    Down = 1,
    Left = 2,
    Right = 3,
};

inline std::pair<int, int> toDelta(Direction dir) {
    switch (dir) {
        case Direction::Up:    return {0, -1};
        case Direction::Down:  return {0, 1};
        case Direction::Left:  return {-1, 0};
        case Direction::Right: return {1, 0};
    }
    return {0, 0}; // fallback
}

#endif //SNAKEGAME_DIRECTION_H