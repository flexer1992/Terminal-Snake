#include "Board.h"

#include <random>

Board::Board(int width, int height) : width(width), height(height), board(height, std::vector<char>(width, '.')) {
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

char Board::getCell(int x, int y) const {
    return isInside(x, y) ? board[y][x] : ' ';
}

void Board::setCell(int x, int y, char value) {
    if (isInside(x, y)) {
        board[y][x] = value;
    }
}

char Board::getSymbolAt(int x, int y) const {
    return board[y][x];
}

void Board::clear(char fill) {
    for (auto &row: board) {
        std::fill(row.begin(), row.end(), fill);
    }
}

Point Board::getFreeRandomPoint() const {
    const int maxAttempts = 1000;
    for (int i = 0; i < maxAttempts; ++i) {
        Point p = getRandomPoint();
        if (getSymbolAt(p.getX(), p.getY()) == '.') {
            return p;
        }
    }
    throw std::runtime_error("No free point found after 1000 attempts");
}


Board::~Board() {
    // Destructor
}

bool Board::isInside(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

Point Board::getRandomPoint() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distX(0, width - 1);
    std::uniform_int_distribution<> distY(0, height - 1);

    return Point(distX(gen), distY(gen));
}
