#include "header/Piece.h"
#include "../board/Board.h"

Piece::Piece(Color color, Coordinates coordinates)
    : m_color(color), m_coordinates(coordinates) {
}

Color Piece::getColor() {
    return m_color;
}

Coordinates &Piece::getCoordinates() {
    return m_coordinates;
}

void Piece::setColor(Color color) {
    m_color = color;
}

void Piece::setCoordinates(Coordinates coordinates) {
    m_coordinates = coordinates;
}

std::vector<CoordinatesShift> Piece::getAttacks() {
    return getMoves();
}

std::set<Coordinates> Piece::getAttackedSquares(Board &board) {
    std::set<Coordinates> result;
    std::vector<CoordinatesShift> pieceAttacks = getAttacks();

    for (CoordinatesShift attack : pieceAttacks) {
        if (m_coordinates.isValidToShift(attack)) {
            Coordinates shiftedCoords = m_coordinates.shift(attack);

            if (isSquareAvailableToAttack(shiftedCoords, board)) {
                result.insert(shiftedCoords);
            }
        }
    }

    return result;
}

bool Piece::isSquareAvailableToMove(Coordinates coordinates, Board &board) {
    return board.isSquareEmpty(coordinates) || board.getPiece(coordinates)->getColor() != m_color;
}

bool Piece::isSquareAvailableToAttack(Coordinates coordinates, Board &board) {
    return true;
}

std::set<Coordinates> Piece::getAvailableCoordsToMove(Board &board) {
    std::set<Coordinates> result;

    for (auto shift : getMoves()) {
        if (m_coordinates.isValidToShift(shift)) {
            Coordinates newCoords = m_coordinates.shift(shift);

            if (isSquareAvailableToMove(newCoords, board)) {
                result.insert(newCoords);
            }
        }
    }

    return result;
}
