#include "header/King.h"

#include "../board/Board.h"

King::King(Color color, Coordinates coord) : Piece(color, coord) {}

std::unique_ptr<Piece> King::clone() const {
    return std::make_unique<King>(*this);
}


std::string King::getUnicodeSprite() {
    return "♚";
}

std::vector<CoordinatesShift> King::getMoves() {
    std::vector<CoordinatesShift> moves;

    for (int fileShift = -1; fileShift <= 1; fileShift++) {
        for (int rankShift = -1; rankShift <= 1; rankShift++) {
            if (fileShift == 0 && rankShift == 0) {
                continue;
            }

            moves.push_back(CoordinatesShift(fileShift, rankShift));
        }
    }

    return moves;
}

bool King::isSquareAvailableToMove(Coordinates coordinates, Board &board) {
    bool result = Piece::isSquareAvailableToMove(coordinates, board);

    if (result) {
        return !board.isSquareAttackedByColor(coordinates, getOppositeColor(m_color));
    }

    return false;
}
