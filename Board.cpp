#include "header/Board.h"
#include "header/File.h"
#include "piece/header/Pawn.h"

void Board::setPiece(Coordinates coordinates, Piece piece) {
    piece.setCoordinates(coordinates);
    pieces.insert_or_assign( coordinates, piece );
}

void Board::setUpDefaultPiecesPositions() {
    for (auto file : getAllFiles()) {
        Coordinates coordToWhitePawns = Coordinates(file, INIT_WHITE_PAWN_RANK);
        Coordinates coordToBlackPawns = Coordinates(file, INIT_BLACK_PAWN_RANK);

        setPiece(coordToWhitePawns, Pawn(Color::WHITE, coordToWhitePawns));
        setPiece(coordToBlackPawns, Pawn(Color::BLACK, coordToBlackPawns));
    }
}
