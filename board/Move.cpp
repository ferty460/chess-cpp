#include "Move.h"

Move::Move(Coordinates from, Coordinates to) : m_from(from), m_to(to) {
}

Coordinates Move::getFrom() {
    return m_from;
}

Coordinates Move::getTo() {
    return m_to;
}

