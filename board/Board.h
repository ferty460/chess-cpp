#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <map>
#include <memory>

#include "../header/Coordinates.h"


class Piece;

class Board {

    const int INIT_WHITE_PAWN_RANK = 2;
    const int INIT_BLACK_PAWN_RANK = 7;

    std::map<Coordinates, std::unique_ptr<Piece>> pieces;

    void setUpPawns();
    void setUpRooks();
    void setUpKnights();
    void setUpBishops();
    void setUpQueens();
    void setUpKings();

public:
    Piece* getPiece(Coordinates &coordinates);
    void setPiece(Coordinates &coordinates, std::unique_ptr<Piece> piece);
    void removePiece(Coordinates &coordinates);
    void movePiece(Coordinates &from, Coordinates &to);
    bool isSquareEmpty(Coordinates &coordinates);
    static bool isSquareDark(Coordinates &coordinates);
    void setUpDefaultPiecesPositions();

};


#endif //CHESS_BOARD_H