#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <map>
#include <memory>

#include "Move.h"
#include "../header/Color.h"
#include "../header/Coordinates.h"


class Piece;

class Board {

    const int INIT_WHITE_PAWN_RANK = 2;
    const int INIT_BLACK_PAWN_RANK = 7;

    std::string startingFen;
    std::map<Coordinates, std::unique_ptr<Piece>> pieces;
    std::vector<Move> moves;

    void setUpPawns();
    void setUpRooks();
    void setUpKnights();
    void setUpBishops();
    void setUpQueens();
    void setUpKings();

public:
    Board(std::string startingFen);
    Board(const Board& other);

    Piece* getPiece(Coordinates &coordinates);
    std::string getStartingFen();
    std::vector<Move> getMoves();
    void setPiece(Coordinates &coordinates, std::unique_ptr<Piece> piece);

    std::vector<Piece*> getPiecesByColor(Color color);
    void removePiece(Coordinates &coordinates);
    void makeMove(Move move);
    bool isSquareEmpty(Coordinates &coordinates);
    bool isSquareAttackedByColor(Coordinates &coordinates, Color color);
    static bool isSquareDark(Coordinates &coordinates);
    void setUpDefaultPiecesPositions();

};


#endif //CHESS_BOARD_H