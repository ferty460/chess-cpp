#include "header/Bishop.h"

#include "../board/Board.h"
#include "../utils/BoardUtils.h"

Bishop::Bishop(Color color, Coordinates coord) : LongRangePiece(color, coord) {}

std::string Bishop::getUnicodeSprite() {
    return "♝";
}

std::vector<CoordinatesShift> Bishop::getMoves() {
    std::vector<CoordinatesShift> result;

    for (int i = -7; i <= 7; i++) {
        if (i == 0) {
            continue;
        }

        result.push_back(CoordinatesShift(i, i));
    }

    for (int i = -7; i <= 7; i++) {
        if (i == 0) {
            continue;
        }

        result.push_back(CoordinatesShift(i, -i));
    }

    return result;
}

