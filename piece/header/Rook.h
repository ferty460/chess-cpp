#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "IRook.h"
#include "LongRangePiece.h"
#include "Piece.h"


// ладья
class Rook : public LongRangePiece, IRook {

public:
    Rook(Color color, Coordinates coord);
    std::unique_ptr<Piece> clone() const override;

    std::string getUnicodeSprite() override;
    std::vector<CoordinatesShift> getMoves() override;

};


#endif //CHESS_ROOK_H