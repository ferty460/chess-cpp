#ifndef CHESS_CHECKMATEGAMECHECKER_H
#define CHESS_CHECKMATEGAMECHECKER_H
#include "GameStateChecker.h"


class King;

class CheckmateGameChecker : public GameStateChecker {

    King* getKing(Board &board, Color color);

public:
    CheckmateGameChecker() = default;
    GameState check(Board &board, Color color) override;

};


#endif //CHESS_CHECKMATEGAMECHECKER_H