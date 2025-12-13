#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <map>

#include "Coordinates.h"
#include "../piece/header/Piece.h"


class Board {

    const int INIT_WHITE_PAWN_RANK = 2;
    const int INIT_BLACK_PAWN_RANK = 7;

public:
    void setPiece(Coordinates coordinates, Piece piece);
    void setUpDefaultPiecesPositions();

private:
    std::map<Coordinates, Piece> pieces;

};


#endif //CHESS_BOARD_H