#ifndef CHESS_COORDINATES_H
#define CHESS_COORDINATES_H
#include "File.h"


class Coordinates {

public:
    Coordinates(File file, int rank);

    bool operator<(const Coordinates &coordinates) const {
        if (file != coordinates.file) {
            return file < coordinates.file;
        }

        return rank < coordinates.rank;
    }

private:
    File file;
    int rank;

};


#endif //CHESS_COORDINATES_H