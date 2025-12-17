#include "header/Game.h"

#include <iostream>

#include "header/InputCoordinates.h"

Game::Game(Board &board) : m_board(board) {
}

void Game::loop() {
    bool isWhiteToMove = true;

    while (true) {
        m_renderer.render(m_board);

        if (isWhiteToMove) {
            std::cout << "ХОД БЕЛЫХ" << std::endl;
        } else {
            std::cout << "ХОД ЧЕРНЫХ" << std::endl;
        }

        Color color = isWhiteToMove ? Color::WHITE : Color::BLACK;
        Move move = InputCoordinates::inputMove(m_board, color, m_renderer);

        m_board.makeMove(move);

        isWhiteToMove = !isWhiteToMove;
    }
}
