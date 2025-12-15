#include "header/Rook.h"

#include "../board/Board.h"
#include "../utils/BoardUtils.h"

Rook::Rook(Color color, Coordinates coord) : Piece(color, coord) {}

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

bool Rook::isSquareAvailableToMove(Coordinates coord, Board &board) {
    bool result = Piece::isSquareAvailableToMove(coord, board);

    if (result) {
        std::vector<Coordinates> coordsBetween;

        if (m_coordinates.getFile() == coord.getFile()) {
            coordsBetween = BoardUtils::getVerticalCoordinatesBetween(m_coordinates, coord);
        } else {
            coordsBetween = BoardUtils::getHorizontalCoordinatesBetween(m_coordinates, coord);
        }

        for (Coordinates coord : coordsBetween) {
            if (!board.isSquareEmpty(coord)) {
                return false;
            }
        }

        return true;
    }

    return false;
}
