#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <string>

#include "../../header/Color.h"
#include "../../header/Coordinates.h"


class Piece {

    Color m_color;
    Coordinates m_coordinates;

public:
    virtual ~Piece() = default;

    Piece(Color color, Coordinates coordinates);

    virtual std::string getUnicodeSprite() = 0;
    Color getColor();
    Coordinates &getCoordinates();
    void setColor(Color color);
    void setCoordinates(Coordinates coordinates);
};


#endif //CHESS_PIECE_H