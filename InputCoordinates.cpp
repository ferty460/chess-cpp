#include "header/InputCoordinates.h"
#include <iostream>
#include <string>

#include "piece/header/Piece.h"

InputCoordinates::InputCoordinates() = default;

Coordinates InputCoordinates::input()  {
    while (true) {
        std::cout << "Пожалуйста, введите координату (например, D1): " << std::endl;

        std::string input;
        std::cin >> input;

        if (input.size() != 2) {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        char file = std::toupper(input[0]);
        char rank = input[1];

        if (file < 'A' || file > 'H' || rank < '1' || rank > '8') {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        return {fromChar(file), rank - '0'};
    }
}

Coordinates InputCoordinates::inputPieceCoordsForColor(Color color, Board &board) {
    while (true) {
        std::cout << "Выберите фигуру" << std::endl;
        Coordinates coord = input();

        if (board.isSquareEmpty(coord)) {
            std::cout << "Пустая ячейка" << std::endl;
            continue;
        }

        Piece *piece = board.getPiece(coord);
        if (piece->getColor() != color) {
            std::cout << "Чужая фигура" << std::endl;
            continue;
        }

        std::set<Coordinates> availableCoords = piece->getAvailableCoordsToMove(board);
        if (availableCoords.empty()) {
            std::cout << "Фигура заблокирована" << std::endl;
            continue;
        }

        return coord;
    }
}

Coordinates InputCoordinates::inputAvailableSquare(std::set<Coordinates> availableSquares) {
    while (true) {
        std::cout << "Введите ход для выбранной фигуры" << std::endl;
        Coordinates coord = input();

        if (!availableSquares.contains(coord)) {
            std::cout << "Поле недоступно для этой фигуры" << std::endl;
            continue;
        }

        return coord;
    }
}
