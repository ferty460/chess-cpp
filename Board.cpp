#include "header/Board.h"
#include "header/File.h"
#include "piece/header/Bishop.h"
#include "piece/header/King.h"
#include "piece/header/Knight.h"
#include "piece/header/Pawn.h"
#include "piece/header/Queen.h"
#include "piece/header/Rook.h"

Piece* Board::getPiece(Coordinates &coordinates) {
    auto it = pieces.find(coordinates);
    return it != pieces.end() ? it->second.get() : nullptr;
}

void Board::setPiece(Coordinates &coordinates, std::unique_ptr<Piece> piece) {
    piece->setCoordinates(coordinates);
    pieces.insert_or_assign(coordinates, std::move(piece));
}

bool Board::isSquareEmpty(Coordinates &coordinates) {
    return !pieces.contains(coordinates);
}

bool Board::isSquareDark(Coordinates &coordinates) {
    int fileIndex = static_cast<int>(coordinates.getFile()) + 1;
    int rank = coordinates.getRank();

    return (fileIndex + rank) % 2 == 0;
}

void Board::setUpPawns() {
    for (auto file : getAllFiles()) {
        Coordinates coordToWhitePawns = Coordinates(file, INIT_WHITE_PAWN_RANK);
        Coordinates coordToBlackPawns = Coordinates(file, INIT_BLACK_PAWN_RANK);

        setPiece(coordToWhitePawns, std::make_unique<Pawn>(Color::WHITE, coordToWhitePawns));
        setPiece(coordToBlackPawns, std::make_unique<Pawn>(Color::BLACK, coordToBlackPawns));
    }
}

void Board::setUpRooks() {
    Coordinates coord1(File::A, 1);
    Coordinates coord2(File::H, 1);
    Coordinates coord3(File::A, 8);
    Coordinates coord4(File::H, 8);

    setPiece(coord1, std::make_unique<Rook>(Color::WHITE, coord1));
    setPiece(coord2, std::make_unique<Rook>(Color::WHITE, coord2));
    setPiece(coord3, std::make_unique<Rook>(Color::BLACK, coord3));
    setPiece(coord4, std::make_unique<Rook>(Color::BLACK, coord4));
}

void Board::setUpKnights() {
    Coordinates coord1(File::B, 1);
    Coordinates coord2(File::G, 1);
    Coordinates coord3(File::B, 8);
    Coordinates coord4(File::G, 8);

    setPiece(coord1, std::make_unique<Knight>(Color::WHITE, coord1));
    setPiece(coord2, std::make_unique<Knight>(Color::WHITE, coord2));
    setPiece(coord3, std::make_unique<Knight>(Color::BLACK, coord3));
    setPiece(coord4, std::make_unique<Knight>(Color::BLACK, coord4));
}

void Board::setUpBishops() {
    Coordinates coord1(File::C, 1);
    Coordinates coord2(File::F, 1);
    Coordinates coord3(File::C, 8);
    Coordinates coord4(File::F, 8);

    setPiece(coord1, std::make_unique<Bishop>(Color::WHITE, coord1));
    setPiece(coord2, std::make_unique<Bishop>(Color::WHITE, coord2));
    setPiece(coord3, std::make_unique<Bishop>(Color::BLACK, coord3));
    setPiece(coord4, std::make_unique<Bishop>(Color::BLACK, coord4));
}

void Board::setUpQueens() {
    Coordinates coord1(File::D, 1);
    Coordinates coord2(File::D, 8);

    setPiece(coord1, std::make_unique<Queen>(Color::WHITE, coord1));
    setPiece(coord2, std::make_unique<Queen>(Color::BLACK, coord2));
}

void Board::setUpKings() {
    Coordinates coord1(File::E, 1);
    Coordinates coord2(File::E, 8);

    setPiece(coord1, std::make_unique<King>(Color::WHITE, coord1));
    setPiece(coord2, std::make_unique<King>(Color::BLACK, coord2));
}

void Board::setUpDefaultPiecesPositions() {
    setUpPawns();
    setUpRooks();
    setUpKnights();
    setUpBishops();
    setUpQueens();
    setUpKings();
}
