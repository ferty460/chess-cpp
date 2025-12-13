#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include "../../header/Color.h"
#include "../../header/Coordinates.h"


class Piece {

private:
    Color m_color;
    Coordinates m_coordinates;

public:
    Piece(Color color, Coordinates coordinates);
    Color getColor();
    Coordinates getCoordinates();
    void setColor(Color color);
    void setCoordinates(Coordinates coordinates);

};


#endif //CHESS_PIECE_H