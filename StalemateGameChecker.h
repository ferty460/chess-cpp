#ifndef CHESS_STALEMATEGAMECHECKER_H
#define CHESS_STALEMATEGAMECHECKER_H
#include "header/GameStateChecker.h"


class StalemateGameChecker : public GameStateChecker {

public:
    StalemateGameChecker() = default;
    GameState check(Board &board, Color color) override;

};


#endif //CHESS_STALEMATEGAMECHECKER_H