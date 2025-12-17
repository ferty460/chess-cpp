#ifndef CHESS_COLOR_H
#define CHESS_COLOR_H


enum class Color {

    WHITE, BLACK

};

inline Color getOppositeColor(Color color) {
    return color == Color::WHITE ? Color::BLACK : Color::WHITE;
}

#endif //CHESS_COLOR_H