#include "header/Game.h"

#include <iostream>

#include "header/InputCoordinates.h"
#include "piece/header/Piece.h"

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
        Coordinates from = InputCoordinates::inputPieceCoordsForColor(color, m_board);

        Piece *piece = m_board.getPiece(from);
        std::set<Coordinates> availableSquares = piece->getAvailableCoordsToMove(m_board);

        Coordinates to = InputCoordinates::inputAvailableSquare(availableSquares);

        m_board.movePiece(from, to);

        isWhiteToMove = !isWhiteToMove;
    }
}
