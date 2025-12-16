#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "Piece.h"


// пешка
class Pawn : public Piece {

public:
    Pawn(Color color, Coordinates coord);
    std::string getUnicodeSprite() override;
    std::vector<CoordinatesShift> getMoves() override;
    bool isSquareAvailableToMove(Coordinates coordinates, Board &board) override;

};


#endif //CHESS_PAWN_H