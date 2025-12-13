#include "header/Knight.h"

Knight::Knight(Color color, Coordinates coord) : Piece(color, coord) {}

std::string Knight::getUnicodeSprite() {
    return "♞";
}
