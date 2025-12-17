#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include "GameState.h"
#include "GameStateChecker.h"
#include "../board/Board.h"
#include "../render/ConsoleBoardRenderer.h"


class Game {

    Board &m_board;
    ConsoleBoardRenderer m_renderer = ConsoleBoardRenderer();
    std::vector<std::unique_ptr<GameStateChecker>> checkers;

public:
    Game(Board &board);

    GameState determineGameState(Board &board, Color color);
    void loop();

};


#endif //CHESS_GAME_H