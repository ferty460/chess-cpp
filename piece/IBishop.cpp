#include "header/IBishop.h"

std::vector<CoordinatesShift> IBishop::getBishopMoves() {
    std::vector<CoordinatesShift> result;

    for (int i = -7; i <= 7; i++) {
        if (i == 0) {
            continue;
        }

        result.push_back(CoordinatesShift(i, i));
    }

    for (int i = -7; i <= 7; i++) {
        if (i == 0) {
            continue;
        }

        result.push_back(CoordinatesShift(i, -i));
    }

    return result;
}
