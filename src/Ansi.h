//
// Created by Alex Maximovich on 15.10.2025.
//
#pragma once

#ifndef SNAKEGAME_ANSI_H
#define SNAKEGAME_ANSI_H

class Ansi {
public:
    static constexpr const char *ClearScreen = "\x1b[2J";
    static constexpr const char *CursorHome = "\x1b[H";
    static constexpr const char *ClearAndHome = "\x1B[2J\x1B[H";
    static constexpr const char *HideCursor = "\x1B[?25l";
    static constexpr const char *ShowCurs = "\x1B[?25h";
    static constexpr const char *ResetFormatting = "\x1B[0m";
    static constexpr const char *Bold = "\x1B[1m";
    static constexpr const char *Red = "\x1B[31m";
    static constexpr const char *Green = "\x1B[32m";
    static constexpr const char *Yellow = "\x1B[33m";
    static constexpr const char *Blue = "\x1B[34m";

};


#endif //SNAKEGAME_ANSI_H
