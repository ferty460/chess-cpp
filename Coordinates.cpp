#include "header/Coordinates.h"

Coordinates::Coordinates(File file, int rank) : file(file), rank(rank) {
}

File Coordinates::getFile() {
    return file;
}

int Coordinates::getRank() {
    return rank;
}

