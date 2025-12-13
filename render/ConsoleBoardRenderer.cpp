#include "header/ConsoleBoardRenderer.h"

#include <iostream>

void ConsoleBoardRenderer::render(Board &board) {
    for (int rank = 8; rank >= 1; rank--) {
        std::string line = "";

        for (auto file : getAllFiles()) {
            Coordinates coords{ file, rank };

            if (board.isSquareEmpty(coords)) {
                line += getSpriteForEmptySquare(coords);
            } else {
                line += getPieceSprite(*board.getPiece(coords));
            }
        }

        line += ANSI_RESET;
        std::cout << line << std::endl;
    }
}

std::string ConsoleBoardRenderer::getSpriteForEmptySquare(Coordinates coords) {
    return colorizeSprite("   ", Color::WHITE, Board::isSquareDark(coords));
}

std::string ConsoleBoardRenderer::getPieceSprite(Piece &piece) {
    std::string sprite = " " + piece.getUnicodeSprite() + " ";
    Color color = piece.getColor();
    bool isSquareDark = Board::isSquareDark(piece.getCoordinates());

    return colorizeSprite(sprite, color, isSquareDark);
}

std::string ConsoleBoardRenderer::colorizeSprite(std::string sprite, Color pieceColor, bool isSquareDark) {
    std::string result = sprite;

    if (pieceColor == Color::WHITE) {
        result = ANSI_WHITE_PIECE_COLOR + result;
    } else {
        result = ANSI_BLACK_PIECE_COLOR + result;
    }

    if (isSquareDark) {
        result = ANSI_BLACK_SQUARE_BG + result;
    } else {
        result = ANSI_WHITE_SQUARE_BG + result;
    }

    return result;
}
