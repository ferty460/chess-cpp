#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Piece.h"


// ферзь
class Queen : public Piece {

public:
    Queen(Color color, Coordinates coord);
    std::string getUnicodeSprite() override;
    std::vector<CoordinatesShift> getMoves() override;

};


#endif //CHESS_QUEEN_H