#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "Piece.h"


// король
class King : public Piece {

public:
    King(Color color, Coordinates coord);
    std::string getUnicodeSprite() override;
    std::vector<CoordinatesShift> getMoves() override;

};


#endif //CHESS_KING_H