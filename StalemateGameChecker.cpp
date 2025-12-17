#include "StalemateGameChecker.h"

#include <set>

#include "piece/header/Piece.h"

GameState StalemateGameChecker::check(Board &board, Color color) {
    std::vector<Piece*> pieces = board.getPiecesByColor(color);

    for (Piece *piece : pieces) {
        std::set<Coordinates> availableCoords = piece->getAvailableCoordsToMove(board);

        if (!availableCoords.empty()) {
            return GameState::ONGOING;
        }
    }

    return GameState::STALEMATE;
}
