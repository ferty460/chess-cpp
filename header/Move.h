#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H
#include "Coordinates.h"


class Move {

    Coordinates m_from, m_to;

public:
    Move(Coordinates from, Coordinates to);

    Coordinates getFrom();
    Coordinates getTo();

};


#endif //CHESS_MOVE_H