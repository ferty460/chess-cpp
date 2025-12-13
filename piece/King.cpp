#include "header/King.h"

King::King(Color color, Coordinates coord) : Piece(color, coord) {}

std::string King::getUnicodeSprite() {
    return "♚";
}
