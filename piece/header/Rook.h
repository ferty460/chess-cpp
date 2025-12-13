#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Piece.h"


// ладья
class Rook : public Piece {

public:
    Rook(Color color, Coordinates coord);
    std::string getUnicodeSprite() override;

};


#endif //CHESS_ROOK_H