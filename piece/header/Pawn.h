#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "Piece.h"


// пешка
class Pawn : public Piece {

public:
    Pawn(Color color, Coordinates coord);
    std::unique_ptr<Piece> clone() const override;

    std::string getUnicodeSprite() override;
    std::vector<CoordinatesShift> getMoves() override;
    bool isSquareAvailableToMove(Coordinates coordinates, Board &board) override;
    std::vector<CoordinatesShift> getAttacks() override;

};


#endif //CHESS_PAWN_H