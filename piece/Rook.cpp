#include "header/Rook.h"

#include "../board/Board.h"
#include "../utils/BoardUtils.h"

Rook::Rook(Color color, Coordinates coord) : LongRangePiece(color, coord) {}

std::unique_ptr<Piece> Rook::clone() const {
    return std::make_unique<Rook>(*this);
}


std::string Rook::getUnicodeSprite() {
    return "♜";
}

std::vector<CoordinatesShift> Rook::getMoves() {
    return getRookMoves();
}
