#include "header/Piece.h"
#include "../header/Board.h"

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

bool Piece::isSquareAvailableToMove(Coordinates coordinates, Board &board) {
    return board.isSquareEmpty(coordinates) || board.getPiece(coordinates)->getColor() != m_color;
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
