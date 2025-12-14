#include <set>
#include <windows.h>

#include "header/Game.h"
#include "header/InputCoordinates.h"
#include "header/Board.h"
#include "piece/header/Piece.h"
#include "render/header/ConsoleBoardRenderer.h"

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

    Board board = Board();
    board.setUpDefaultPiecesPositions();

    Game game(board);
    game.loop();
}

