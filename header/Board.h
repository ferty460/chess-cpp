#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <map>
#include <memory>

#include "Coordinates.h"
#include "../piece/header/Piece.h"


class Board {

    const int INIT_WHITE_PAWN_RANK = 2;
    const int INIT_BLACK_PAWN_RANK = 7;

    std::map<Coordinates, std::unique_ptr<Piece>> pieces;

public:
    Piece* getPiece(Coordinates &coordinates);
    void setPiece(Coordinates &coordinates, std::unique_ptr<Piece> piece);
    bool isSquareEmpty(Coordinates &coordinates);
    static bool isSquareDark(Coordinates &coordinates);

    void setUpPawns();

    void setUpRooks();

    void setUpKnights();

    void setUpBishops();

    void setUpQueens();

    void setUpKings();

    void setUpDefaultPiecesPositions();

};


#endif //CHESS_BOARD_H