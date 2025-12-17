#ifndef CHESS_COORDINATES_H
#define CHESS_COORDINATES_H
#include "File.h"
#include "CoordinatesShift.h"


class Coordinates {

    File file;
    int rank;

public:
    Coordinates(File file, int rank);

    Coordinates shift(CoordinatesShift shift);
    bool isValidToShift(CoordinatesShift shift);

    File getFile() const;
    int getRank() const;

    bool operator<(const Coordinates &coordinates) const {
        if (file != coordinates.file) {
            return file < coordinates.file;
        }

        return rank < coordinates.rank;
    }

};


#endif //CHESS_COORDINATES_H