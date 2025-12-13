#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "Piece.h"


// конь
class Knight : public Piece {

public:
    Knight(Color color, Coordinates coord);
    std::string getUnicodeSprite() override;

};


#endif //CHESS_KNIGHT_H