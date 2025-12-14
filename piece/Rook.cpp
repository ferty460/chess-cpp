#include "header/Rook.h"

Rook::Rook(Color color, Coordinates coord) : Piece(color, coord) {}

std::string Rook::getUnicodeSprite() {
    return "♜";
}

std::vector<CoordinatesShift> Rook::getMoves() {
    return {};
}
