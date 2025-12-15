#ifndef CHESS_BOARDUTILS_H
#define CHESS_BOARDUTILS_H
#include <vector>

#include "../header/Coordinates.h"


class BoardUtils {

public:
    static std::vector<Coordinates> getDiagonalsCoordinatesBetween(Coordinates from, Coordinates to);
    static std::vector<Coordinates> getVerticalCoordinatesBetween(Coordinates from, Coordinates to);
    static std::vector<Coordinates> getHorizontalCoordinatesBetween(Coordinates from, Coordinates to);

};


#endif //CHESS_BOARDUTILS_H
