#ifndef CHESS_IROOK_H
#define CHESS_IROOK_H
#include <vector>

#include "../../core/CoordinatesShift.h"


class IRook {

public:
    virtual ~IRook() = default;
    virtual std::vector<CoordinatesShift> getRookMoves();

};


#endif //CHESS_IROOK_H