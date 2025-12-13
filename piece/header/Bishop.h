#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Piece.h"


// слон
class Bishop : public Piece {

public:
    Bishop(Color color, Coordinates coord);
    std::string getUnicodeSprite() override;

};


#endif //CHESS_BISHOP_H