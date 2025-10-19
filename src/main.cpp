#include <iostream>
#include <vector>

#include "Board.h"
#include "Snake.h"
#include "Direction.h"
#include "Game.h"
#include "TerminalRenderer.h"
using namespace std;

int main()
{

    Board board(20, 20);
    TerminalRenderer renderer(board);

    Game game(board, renderer);
    game.run();

    std::cout << "Hello from Apple Silicon!" << std::endl;
    return 0;
}