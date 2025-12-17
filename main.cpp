#include <iostream>
#include <windows.h>

#include "header/Game.h"
#include "board/Board.h"
#include "board/BoardFactory.h"
#include "utils/BoardUtils.h"

void enableAnsiColorsAndUtf8() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

int main() {
    enableAnsiColorsAndUtf8();

    Board board = BoardFactory().fromFen(
     // "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
        // "4k3/6p1/5p2/4N3/2n1B1b1/3P2P1/2P5/4K3 b KQkq - 0 1"
        // "3k4/8/8/b7/8/8/2PK4/6N1 b KQkq - 0 1"
        "8/8/8/8/6p1/3k1pP1/3p1P2/3K3N w KQkq - 0 1"
    );

    // ConsoleBoardRenderer renderer = ConsoleBoardRenderer();
    // renderer.render(board);

    Game game(board);
    game.loop();

    std::vector<Coordinates> coords = BoardUtils::getHorizontalCoordinatesBetween(Coordinates(File::D, 4), Coordinates(File::H, 2));

    int a = 1;
}

