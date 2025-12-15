//
// Created by admin on 15.12.2025.
//

#include "header/IRook.h"

std::vector<CoordinatesShift> IRook::getRookMoves() {
    std::vector<CoordinatesShift> result;

    for (int i = -7; i <= 7; i++) {
        if (i == 0) {
            continue;
        }

        result.push_back(CoordinatesShift(i, 0));
    }

    for (int i = -7; i <= 7; i++) {
        if (i == 0) {
            continue;
        }

        result.push_back(CoordinatesShift(0, i));
    }

    return result;
}
