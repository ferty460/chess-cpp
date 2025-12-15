#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include "../board/Board.h"
#include "../render/ConsoleBoardRenderer.h"


class Game {

    Board &m_board;
    ConsoleBoardRenderer m_renderer = ConsoleBoardRenderer();

public:
    Game(Board &board);

    void loop();

};


#endif //CHESS_GAME_H