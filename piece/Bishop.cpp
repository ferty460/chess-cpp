#include "header/Bishop.h"

#include "../board/Board.h"
#include "../utils/BoardUtils.h"

Bishop::Bishop(Color color, Coordinates coord) : LongRangePiece(color, coord) {}

std::string Bishop::getUnicodeSprite() {
    return "♝";
}

std::vector<CoordinatesShift> Bishop::getMoves() {
    return getBishopMoves();
}

