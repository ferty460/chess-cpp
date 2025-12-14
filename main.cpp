#include <set>
#include <windows.h>

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

    ConsoleBoardRenderer renderer;
    renderer.render(board);

    Coordinates knightCoords(File::G, 8);
    Piece *piece = board.getPiece(knightCoords);
    std::set<Coordinates> coords = piece->getAvailableCoordsToMove(board);

    int a = 1;
}

