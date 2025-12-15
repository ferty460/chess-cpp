#include "header/Bishop.h"

#include "../board/Board.h"
#include "../utils/BoardUtils.h"

Bishop::Bishop(Color color, Coordinates coord) : Piece(color, coord) {}

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

bool Bishop::isSquareAvailableToMove(Coordinates coord, Board &board) {
    bool result = Piece::isSquareAvailableToMove(coord, board);

    if (result) {
        std::vector<Coordinates> coordsBetween = BoardUtils::getDiagonalsCoordinatesBetween(m_coordinates, coord);

        for (Coordinates coord : coordsBetween) {
            if (!board.isSquareEmpty(coord)) {
                return false;
            }
        }

        return true;
    }

    return false;
}

