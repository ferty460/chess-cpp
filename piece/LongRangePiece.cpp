#include "header/LongRangePiece.h"

#include "../board/Board.h"
#include "../utils/BoardUtils.h"

LongRangePiece::LongRangePiece(Color color, Coordinates coord) : Piece(color, coord) {}

bool LongRangePiece::isSquareAvailableToMove(Coordinates coord, Board &board) {
    bool result = Piece::isSquareAvailableToMove(coord, board);

    if (result) {
        std::vector<Coordinates> coordsBetween;

        if (m_coordinates.getFile() == coord.getFile()) {
            coordsBetween = BoardUtils::getVerticalCoordinatesBetween(m_coordinates, coord);
        } else if (m_coordinates.getRank() == coord.getRank()) {
            coordsBetween = BoardUtils::getHorizontalCoordinatesBetween(m_coordinates, coord);
        } else {
            coordsBetween = BoardUtils::getDiagonalsCoordinatesBetween(m_coordinates, coord);
        }

        for (Coordinates coord : coordsBetween) {
            if (!board.isSquareEmpty(coord)) {
                return false;
            }
        }

        return true;
    }

    return false;
}
