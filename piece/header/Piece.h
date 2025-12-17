#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <set>
#include <string>
#include <vector>

#include "../../header/Color.h"
#include "../../header/Coordinates.h"
#include "../../header/CoordinatesShift.h"


class Board;

class Piece {

protected:
    Color m_color;
    Coordinates m_coordinates;

public:
    virtual ~Piece() = default;
    Piece(Color color, Coordinates coordinates);

    virtual std::string getUnicodeSprite() = 0;
    virtual std::vector<CoordinatesShift> getMoves() = 0;
    virtual std::vector<CoordinatesShift> getAttacks();
    virtual std::set<Coordinates> getAttackedSquares(Board &board);
    virtual bool isSquareAvailableToMove(Coordinates coordinates, Board &board);
    virtual bool isSquareAvailableToAttack(Coordinates coordinates, Board &board);

    std::set<Coordinates> getAvailableCoordsToMove(Board &board);

    Color getColor();
    Coordinates &getCoordinates();
    void setColor(Color color);
    void setCoordinates(Coordinates coordinates);
};


#endif //CHESS_PIECE_H