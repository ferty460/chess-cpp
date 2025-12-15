#ifndef CHESS_PIECEFACTORY_H
#define CHESS_PIECEFACTORY_H
#include <memory>

#include "piece/header/Piece.h"


class PieceFactory {

public:
    std::unique_ptr<Piece> fromFenChar(char fenChar, Coordinates coordinates);

};


#endif //CHESS_PIECEFACTORY_H
