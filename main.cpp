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

    Board board = BoardFactory().fromFen("3k4/8/p7/8/R7/8/P7/3K4 w - - 0 1");
    // ConsoleBoardRenderer renderer = ConsoleBoardRenderer();
    // renderer.render(board);

    Game game(board);
    game.loop();

    std::vector<Coordinates> coords = BoardUtils::getHorizontalCoordinatesBetween(Coordinates(File::D, 4), Coordinates(File::H, 2));

    int a = 1;
}

