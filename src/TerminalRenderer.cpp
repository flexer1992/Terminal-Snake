#include "TerminalRenderer.h"
#include <iostream>

TerminalRenderer::TerminalRenderer(const Board& board)
    : board(board) {
    // Скрываем курсор и очищаем экран один раз
    std::cout << "\x1B[2J\x1B[H\x1B[?25l" << std::flush;
}

TerminalRenderer::~TerminalRenderer() {
    // Возвращаем курсор при выходе
    std::cout << "\x1B[?25h" << std::flush;
}

void TerminalRenderer::render() {
    // Возвращаем курсор в начало экрана
    std::cout << "\x1B[H";

    // Формируем кадр в память, чтобы не дергать консоль посимвольно
    std::string frame;
    frame.reserve(board.getHeight() * (board.getWidth() + 1));

    for (int y = 0; y < board.getHeight(); ++y) {
        for (int x = 0; x < board.getWidth(); ++x) {
            frame += board.getSymbolAt(x, y);
        }
        frame += '\n';
    }

    // Выводим кадр за один раз
    std::cout << frame << std::flush;
}
