#include "header/Rook.h"

#include "../board/Board.h"
#include "../utils/BoardUtils.h"

Rook::Rook(Color color, Coordinates coord) : LongRangePiece(color, coord) {}

std::string Rook::getUnicodeSprite() {
    return "♜";
}

std::vector<CoordinatesShift> Rook::getMoves() {
    std::vector<CoordinatesShift> result;

    for (int i = -7; i <= 7; i++) {
        if (i == 0) {
            continue;
        }

        result.push_back(CoordinatesShift(i, 0));
    }

    for (int i = -7; i <= 7; i++) {
        if (i == 0) {
            continue;
        }

        result.push_back(CoordinatesShift(0, i));
    }

    return result;
}
