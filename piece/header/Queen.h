#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "IBishop.h"
#include "IRook.h"
#include "LongRangePiece.h"
#include "Piece.h"


// ферзь
class Queen : public LongRangePiece, IBishop, IRook {

public:
    Queen(Color color, Coordinates coord);
    std::unique_ptr<Piece> clone() const override;

    std::string getUnicodeSprite() override;
    std::vector<CoordinatesShift> getMoves() override;

};


#endif //CHESS_QUEEN_H