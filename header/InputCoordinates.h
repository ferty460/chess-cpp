#ifndef CHESS_INPUTCOORDINATES_H
#define CHESS_INPUTCOORDINATES_H

#include <set>

#include "../board/Board.h"
#include "Color.h"
#include "Coordinates.h"
#include "Move.h"
#include "../render/ConsoleBoardRenderer.h"


class InputCoordinates {

public:
    InputCoordinates();
    static Coordinates input();
    static Coordinates inputPieceCoordsForColor(Color color, Board &board);
    static Coordinates inputAvailableSquare(std::set<Coordinates> availableSquares);
    static Move inputMove(Board &board, Color color, ConsoleBoardRenderer renderer);

};


#endif //CHESS_INPUTCOORDINATES_H