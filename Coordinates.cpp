#include "header/Coordinates.h"

Coordinates::Coordinates(File file, int rank) : file(file), rank(rank) {
}

Coordinates Coordinates::shift(CoordinatesShift shift) {
    File fileShift = getAllFiles()[static_cast<int>(file) + shift.getFileShift()];
    int rankShift = rank + shift.getRankShift();

    return {fileShift, rankShift};
}

bool Coordinates::isValidToShift(CoordinatesShift shift) {
    int fileShift = static_cast<int>(file) + shift.getFileShift();
    int rankShift = rank + shift.getRankShift();

    if (fileShift < 0 || fileShift > 7) {
        return false;
    }
    if (rankShift < 1 || rankShift > 8) {
        return false;
    }

    return true;
}

File Coordinates::getFile() const {
    return file;
}

int Coordinates::getRank() const {
    return rank;
}

