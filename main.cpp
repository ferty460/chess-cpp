#include <set>
#include <windows.h>

#include "BoardFactory.h"
#include "header/Game.h"
#include "header/Board.h"

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

    Board board = BoardFactory().fromFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    ConsoleBoardRenderer renderer = ConsoleBoardRenderer();
    renderer.render(board);
    // board.setUpDefaultPiecesPositions();

    // Game game(board);
    // game.loop();
}

