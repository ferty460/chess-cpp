#ifndef CHESS_INPUTCOORDINATES_H
#define CHESS_INPUTCOORDINATES_H

#include <set>

#include "Board.h"
#include "Color.h"
#include "Coordinates.h"


class InputCoordinates {

public:
    InputCoordinates();
    static Coordinates input();
    static Coordinates inputPieceCoordsForColor(Color color, Board &board);
    static Coordinates inputAvailableSquare(std::set<Coordinates> availableSquares);

};


#endif //CHESS_INPUTCOORDINATES_H