#include "header/Knight.h"

Knight::Knight(Color color, Coordinates coord) : Piece(color, coord) {}

std::unique_ptr<Piece> Knight::clone() const {
    return std::make_unique<Knight>(*this);
}


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
