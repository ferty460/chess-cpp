#include "CheckmateGameChecker.h"

#include "../piece/header/King.h"

GameState CheckmateGameChecker::check(Board &board, Color color) {
    King* king = getKing(board, color);

    if (!board.isSquareAttackedByColor(king->getCoordinates(), getOppositeColor(color))) {
        return GameState::ONGOING;
    }

    std::vector<Piece*> pieces = board.getPiecesByColor(color);
    for (Piece* piece : pieces) {
        std::set<Coordinates> coords = piece->getAvailableCoordsToMove(board);

        for (auto coord : coords) {
            Board clone = Board(board);
            clone.makeMove(Move(piece->getCoordinates(), coord));

            King* clonedKing = getKing(clone, color);

            if (!clone.isSquareAttackedByColor(clonedKing->getCoordinates(), getOppositeColor(color))) {
                return GameState::ONGOING;
            }
        }
    }

    if (color == Color::WHITE) {
        return GameState::CHECKMATE_TO_WHITE_KING;
    }

    return GameState::CHECKMATE_TO_BLACK_KING;
}

King *CheckmateGameChecker::getKing(Board &board, Color color) {
    King* king = nullptr;

    for (Piece* piece : board.getPiecesByColor(color)) {
        if (auto* k = dynamic_cast<King*>(piece)) {
            king = k;
            break;
        }
    }

    if (!king) {
        throw std::logic_error("King not found on board");
    }

    return king;
}
