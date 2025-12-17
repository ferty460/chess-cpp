#include "BoardFactory.h"

#include "../piece/header/Pawn.h"

std::vector<std::string> BoardFactory::split(std::string &str, char delim) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delim);

    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delim, start);
    }

    tokens.push_back(str.substr(start));
    return tokens;
}

Board BoardFactory::fromFen(std::string fen) {
    // default setup:
    // rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
    Board board = Board(fen);

    std::vector<std::string> parts = split(fen, ' ');
    std::string piecePositions = parts[0];
    std::vector<std::string> fenRows = split(piecePositions, '/');

    for (int i = 0; i < fenRows.size(); i++) {
        std::string row = fenRows[i];
        int rank = 8 - i;
        int fileIndex = 0;

        for (char fenChar : row) {
            if (std::isdigit(fenChar)) {
                fileIndex += fenChar - '0';
            } else {
                File file = getAllFiles()[fileIndex];
                Coordinates coordinates = Coordinates(file, rank);

                board.setPiece(coordinates, pieceFactory.fromFenChar(fenChar, coordinates));
                fileIndex++;
            }
        }
    }

    return board;
}
