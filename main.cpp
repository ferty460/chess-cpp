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

    Board board = BoardFactory().fromFen("3k4/8/5n2/2N5/3B4/8/8/3K4 w KQkq - 0 11");
    // ConsoleBoardRenderer renderer = ConsoleBoardRenderer();
    // renderer.render(board);

    Game game(board);
    game.loop();

    std::vector<Coordinates> coords = BoardUtils::getDiagonalsCoordinatesBetween(Coordinates(File::D, 4), Coordinates(File::A, 7));

    int a = 1;
}

