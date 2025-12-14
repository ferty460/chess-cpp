#include "header/Queen.h"

Queen::Queen(Color color, Coordinates coord) : Piece(color, coord) {}

std::string Queen::getUnicodeSprite() {
    return "♛";
}

std::vector<CoordinatesShift> Queen::getMoves() {
    return {};
}
