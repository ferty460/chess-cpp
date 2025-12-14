#ifndef CHESS_CONSOLEBOARDRENDERER_H
#define CHESS_CONSOLEBOARDRENDERER_H
#include <string>

#include "../../header/Board.h"
#include "../../header/Color.h"

class ConsoleBoardRenderer {

    const std::string ANSI_RESET = "\u001B[0m";
    const std::string ANSI_WHITE_PIECE_COLOR = "\u001B[97m";
    const std::string ANSI_BLACK_PIECE_COLOR = "\u001B[30m";
    const std::string ANSI_WHITE_SQUARE_BG = "\u001B[47m";
    const std::string ANSI_BLACK_SQUARE_BG = "\u001B[0;100m";

    std::string getSpriteForEmptySquare(Coordinates coords);
    std::string getPieceSprite(Piece &piece);
    std::string colorizeSprite(std::string sprite, Color pieceColor, bool isSquareDark);

public:

    void render(Board &board);

};


#endif //CHESS_CONSOLEBOARDRENDERER_H