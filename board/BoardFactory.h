#ifndef CHESS_BOARDFACTORY_H
#define CHESS_BOARDFACTORY_H
#include "../piece/header/PieceFactory.h"
#include "Board.h"


class BoardFactory {

    PieceFactory pieceFactory = PieceFactory();

    std::vector<std::string> split(std::string &s, char delim);

public:
    Board fromFen(std::string fen);
    Board copy(Board source);

};


#endif //CHESS_BOARDFACTORY_H