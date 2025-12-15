#ifndef CHESS_IROOK_H
#define CHESS_IROOK_H
#include <vector>

#include "../../header/CoordinatesShift.h"


class IRook {

public:
    virtual std::vector<CoordinatesShift> getRookMoves();

};


#endif //CHESS_IROOK_H