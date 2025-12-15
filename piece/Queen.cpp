#include "header/Queen.h"

Queen::Queen(Color color, Coordinates coord) : LongRangePiece(color, coord) {}

std::string Queen::getUnicodeSprite() {
    return "♛";
}

std::vector<CoordinatesShift> Queen::getMoves() {
    std::vector<CoordinatesShift> moves = getBishopMoves();
    std::vector<CoordinatesShift> rookMoves = getRookMoves();
    moves.insert(moves.end(), rookMoves.begin(), rookMoves.end());

    return moves;
}
