#include "Game.h"

#include <iostream>

#include "InputCoordinates.h"
#include "../checker/CheckmateGameChecker.h"
#include "../checker/StalemateGameChecker.h"
#include "../checker/GameState.h"

Game::Game(Board &board) : m_board(board) {
    checkers.push_back(std::make_unique<StalemateGameChecker>());
    checkers.push_back(std::make_unique<CheckmateGameChecker>());
}

GameState Game::determineGameState(Board &board, Color color) {
    for (auto &checker : checkers) {
        GameState state = checker->check(board, color);

        if (state != GameState::ONGOING) {
            return state;
        }
    }

    return GameState::ONGOING;
}

void Game::loop() {
    Color colorToMove = Color::WHITE;

    GameState state = determineGameState(m_board, colorToMove);

    while (state == GameState::ONGOING) {
        m_renderer.render(m_board);

        if (colorToMove == Color::WHITE) {
            std::cout << "ХОД БЕЛЫХ" << std::endl;
        } else {
            std::cout << "ХОД ЧЕРНЫХ" << std::endl;
        }

        Move move = InputCoordinates::inputMove(m_board, colorToMove, m_renderer);
        m_board.makeMove(move);
        colorToMove = getOppositeColor(colorToMove);
        state = determineGameState(m_board, colorToMove);
    }

    m_renderer.render(m_board);
    std::cout << "Игра закончена: " << gameStateToString(state) << std::endl;
}
