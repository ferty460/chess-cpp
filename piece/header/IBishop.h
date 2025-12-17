#ifndef CHESS_IBISHOP_H
#define CHESS_IBISHOP_H
#include <vector>

#include "../../core/CoordinatesShift.h"

class IBishop {

public:
    virtual ~IBishop() = default;
    virtual std::vector<CoordinatesShift> getBishopMoves();

};

#endif //CHESS_IBISHOP_H