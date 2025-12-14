#include "header/CoordinatesShift.h"

CoordinatesShift::CoordinatesShift(int fileShift, int rankShift)
    : m_fileShift(fileShift), m_rankShift(rankShift) {
}

int CoordinatesShift::getFileShift() {
    return m_fileShift;
}

int CoordinatesShift::getRankShift() {
    return m_rankShift;
}
