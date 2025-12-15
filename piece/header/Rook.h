#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Piece.h"


// ладья
class Rook : public Piece {

public:
    Rook(Color color, Coordinates coord);
    std::string getUnicodeSprite() override;
    std::vector<CoordinatesShift> getMoves() override;
    bool isSquareAvailableToMove(Coordinates coordinates, Board &board) override;

};


#endif //CHESS_ROOK_H