#ifndef CHESS_GAMESTATECHECKER_H
#define CHESS_GAMESTATECHECKER_H
#include "GameState.h"
#include "../board/Board.h"


class GameStateChecker {

public:
    virtual ~GameStateChecker() = default;

    virtual GameState check(Board &board, Color color) = 0;

};


#endif //CHESS_GAMESTATECHECKER_H