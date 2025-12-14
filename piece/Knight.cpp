#include "header/Knight.h"

Knight::Knight(Color color, Coordinates coord) : Piece(color, coord) {}

std::string Knight::getUnicodeSprite() {
    return "♞";
}

std::vector<CoordinatesShift> Knight::getMoves() {
    return {
        CoordinatesShift{ 1, 2 },
        CoordinatesShift{ 2, 1 },
        CoordinatesShift{ 1, -2 },
        CoordinatesShift{ 2, -1 },
        CoordinatesShift{ -1, -2 },
        CoordinatesShift{ -2, -1 },
        CoordinatesShift{ -1, 2 },
        CoordinatesShift{ -2, 1 }
    };
}
