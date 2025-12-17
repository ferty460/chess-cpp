#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "IBishop.h"
#include "LongRangePiece.h"
#include "Piece.h"


// слон
class Bishop : public LongRangePiece, IBishop {

public:
    Bishop(Color color, Coordinates coord);
    std::unique_ptr<Piece> clone() const override;

    std::string getUnicodeSprite() override;
    std::vector<CoordinatesShift> getMoves() override;

};


#endif //CHESS_BISHOP_H