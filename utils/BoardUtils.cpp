#include "BoardUtils.h"

// коорды должны лежать на одной диагонали
std::vector<Coordinates> BoardUtils::getDiagonalsCoordinatesBetween(Coordinates from, Coordinates to) {
    std::vector<Coordinates> result;

    int fileShift = static_cast<int>(from.getFile()) < static_cast<int>(to.getFile()) ? 1 : -1;
    int rankShift = from.getRank() < to.getRank() ? 1 : -1;

    for (
        int fileIndex = static_cast<int>(from.getFile()) + fileShift,
        rank = from.getRank() + rankShift;

        fileIndex != static_cast<int>(to.getFile()) && rank != to.getRank();

        fileIndex += fileShift,
        rank += rankShift
    ) {
        result.push_back(Coordinates(getAllFiles()[fileIndex], rank));
    }

    return result;
}

// коорды должны лежать на одной вертикали
std::vector<Coordinates> BoardUtils::getVerticalCoordinatesBetween(Coordinates from, Coordinates to) {
    std::vector<Coordinates> result;

    int rankShift = from.getRank() < to.getRank() ? 1 : -1;

    for (int rank = from.getRank() + rankShift; rank != to.getRank(); rank += rankShift) {
        result.push_back(Coordinates(from.getFile(), rank));
    }

    return result;
}

// коорды должны лежать на одной горизонтали
std::vector<Coordinates> BoardUtils::getHorizontalCoordinatesBetween(Coordinates from, Coordinates to) {
    std::vector<Coordinates> result;

    int fileShift = static_cast<int>(from.getFile()) < static_cast<int>(to.getFile()) ? 1 : -1;

    for (int fileIndex = static_cast<int>(from.getFile()) + fileShift; fileIndex != static_cast<int>(to.getFile()); fileIndex += fileShift) {
        result.push_back(Coordinates(getAllFiles()[fileIndex], from.getRank()));
    }

    return result;
}
