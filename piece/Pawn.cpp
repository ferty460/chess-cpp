#include "header/Pawn.h"

#include "../board/Board.h"

Pawn::Pawn(Color color, Coordinates coord) : Piece(color, coord) {}

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
        return board.isSquareEmpty(coordinates);
    }

    if (board.isSquareEmpty(coordinates)) {
        return false;
    }

    return board.getPiece(coordinates)->getColor() != m_color;
}
