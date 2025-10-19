//
// Created by Alex Maximovich on 15.10.2025.
//

#include "InputHandler.h"
#include <fcntl.h>

InputHandler::InputHandler() {
    enableRawMode();
}

InputHandler::~InputHandler() {
    disableRawMode();
}

std::optional<char> InputHandler::pollKey() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);         // сохранить старые настройки
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);       // выключить canonical mode и echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);  // неблокирующий ввод

    std::optional<char> result;
    char ch;
    if (read(STDIN_FILENO, &ch, 1) > 0)
        result = ch;

    // вернуть всё как было
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    return result;
}

void InputHandler::enableRawMode() {
    tcgetattr(STDIN_FILENO, &originalTermios);
    termios raw = originalTermios;
    raw.c_lflag &= ~(ICANON | ECHO); // отключаем канонический режим и echo
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // неблокирующий ввод
}

void InputHandler::disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios);
}
