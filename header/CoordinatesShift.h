#ifndef CHESS_COORDINATESSHIFT_H
#define CHESS_COORDINATESSHIFT_H


class CoordinatesShift {

    int m_fileShift;
    int m_rankShift;

public:
    CoordinatesShift(int fileShift, int rankShift);

    int getFileShift();
    int getRankShift();

};


#endif //CHESS_COORDINATESSHIFT_H