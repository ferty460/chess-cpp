#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "LongRangePiece.h"
#include "Piece.h"


// ладья
class Rook : public LongRangePiece {

public:
    Rook(Color color, Coordinates coord);
    std::string getUnicodeSprite() override;
    std::vector<CoordinatesShift> getMoves() override;

};


#endif //CHESS_ROOK_H