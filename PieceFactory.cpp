#include "PieceFactory.h"

#include <memory>

#include "piece/header/Bishop.h"
#include "piece/header/King.h"
#include "piece/header/Knight.h"
#include "piece/header/Pawn.h"
#include "piece/header/Queen.h"
#include "piece/header/Rook.h"

std::unique_ptr<Piece> PieceFactory::fromFenChar(char fenChar, Coordinates coordinates) {
    switch (fenChar) {
        case 'p': return std::make_unique<Pawn>(Color::BLACK, coordinates);
        case 'P': return std::make_unique<Pawn>(Color::WHITE, coordinates);

        case 'r': return std::make_unique<Rook>(Color::BLACK, coordinates);
        case 'R': return std::make_unique<Rook>(Color::WHITE, coordinates);

        case 'n': return std::make_unique<Knight>(Color::BLACK, coordinates);
        case 'N': return std::make_unique<Knight>(Color::WHITE, coordinates);

        case 'b': return std::make_unique<Bishop>(Color::BLACK, coordinates);
        case 'B': return std::make_unique<Bishop>(Color::WHITE, coordinates);

        case 'q': return std::make_unique<Queen>(Color::BLACK, coordinates);
        case 'Q': return std::make_unique<Queen>(Color::WHITE, coordinates);

        case 'k': return std::make_unique<King>(Color::BLACK, coordinates);
        case 'K': return std::make_unique<King>(Color::WHITE, coordinates);

        default:
            throw std::invalid_argument("Invalid FEN char");
    }
}

