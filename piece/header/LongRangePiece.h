#ifndef CHESS_LONGRANGEPIECE_H
#define CHESS_LONGRANGEPIECE_H
#include "Piece.h"


class LongRangePiece : public Piece {

public:
    LongRangePiece(Color color, Coordinates coord);
    bool isSquareAvailableToMove(Coordinates coord, Board &board) override;
    bool isSquareAvailableToAttack(Coordinates coordinates, Board &board) override;

};


#endif //CHESS_LONGRANGEPIECE_H