#ifndef CHESS_COORDINATES_H
#define CHESS_COORDINATES_H
#include "File.h"
#include "CoordinatesShift.h"


class Coordinates {

public:
    Coordinates(File file, int rank);

    Coordinates shift(CoordinatesShift shift);
    bool isValidToShift(CoordinatesShift shift);

    File getFile();
    int getRank();

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