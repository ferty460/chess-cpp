#include "header/Piece.h"

Piece::Piece(Color color, Coordinates coordinates)
    : m_color(color), m_coordinates(coordinates) {
}

Color Piece::getColor() {
    return m_color;
}

Coordinates Piece::getCoordinates() {
    return m_coordinates;
}

void Piece::setColor(Color color) {
    m_color = color;
}

void Piece::setCoordinates(Coordinates coordinates) {
    m_coordinates = coordinates;
}