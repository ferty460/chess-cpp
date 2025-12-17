#include "header/Pawn.h"

#include "../board/Board.h"
#include "../utils/BoardUtils.h"

Pawn::Pawn(Color color, Coordinates coord) : Piece(color, coord) {}

std::unique_ptr<Piece> Pawn::clone() const {
    return std::make_unique<Pawn>(*this);
}


std::string Pawn::getUnicodeSprite() {
    return "♟︎";
}

std::vector<CoordinatesShift> Pawn::getMoves() {
    std::vector<CoordinatesShift> moves;

    if (m_color == Color::WHITE) {
        moves.push_back(CoordinatesShift(0, 1));

        if (m_coordinates.getRank() == 2) {
            moves.push_back(CoordinatesShift(0, 2));
        }

        moves.push_back(CoordinatesShift(-1, 1));
        moves.push_back(CoordinatesShift(1, 1));
    } else {
        moves.push_back(CoordinatesShift(0, -1));

        if (m_coordinates.getRank() == 7) {
            moves.push_back(CoordinatesShift(0, -2));
        }

        moves.push_back(CoordinatesShift(-1, -1));
        moves.push_back(CoordinatesShift(1, -1));
    }

    return moves;
}

bool Pawn::isSquareAvailableToMove(Coordinates coordinates, Board &board) {
    if (m_coordinates.getFile() == coordinates.getFile()) {
        int shift = abs(m_coordinates.getRank() - coordinates.getRank());

        if (shift == 2) {
            std::vector<Coordinates> between = BoardUtils::getVerticalCoordinatesBetween(m_coordinates, coordinates);

            return board.isSquareEmpty(between[0]);
        }

        return board.isSquareEmpty(coordinates);
    }

    if (board.isSquareEmpty(coordinates)) {
        return false;
    }

    return board.getPiece(coordinates)->getColor() != m_color;
}

std::vector<CoordinatesShift> Pawn::getAttacks() {
    std::vector<CoordinatesShift> result;

    if (m_color == Color::WHITE) {
        result.push_back(CoordinatesShift(-1, 1));
        result.push_back(CoordinatesShift(1, 1));
    } else {
        result.push_back(CoordinatesShift(-1, -1));
        result.push_back(CoordinatesShift(1, -1));
    }

    return result;
}
