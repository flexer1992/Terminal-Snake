//
// Created by Alex Maximovich on 15.10.2025.
//

#ifndef SNAKEGAME_INPUTHANDLER_H
#define SNAKEGAME_INPUTHANDLER_H

#pragma once
#include <termios.h>
#include <unistd.h>
#include <optional>

class InputHandler {
public:
    InputHandler();

    ~InputHandler();

    std::optional<char> pollKey(); // Возвращает символ, если нажата клавиша

private:
    termios originalTermios;

    void enableRawMode();

    void disableRawMode();
};


#endif //SNAKEGAME_INPUTHANDLER_H
