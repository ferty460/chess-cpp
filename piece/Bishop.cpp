#include "header/Bishop.h"

Bishop::Bishop(Color color, Coordinates coord) : Piece(color, coord) {}

std::string Bishop::getUnicodeSprite() {
    return "♝";
}

std::vector<CoordinatesShift> Bishop::getMoves() {
    return {};
}

