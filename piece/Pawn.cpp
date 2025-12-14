#include "header/Pawn.h"

Pawn::Pawn(Color color, Coordinates coord) : Piece(color, coord) {}

std::string Pawn::getUnicodeSprite() {
    return "♟︎";
}

std::vector<CoordinatesShift> Pawn::getMoves() {
    return {};
}
