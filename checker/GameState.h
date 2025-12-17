#ifndef CHESS_GAMESTATE_H
#define CHESS_GAMESTATE_H
#include <string>

enum class GameState {

    ONGOING,
    STALEMATE,
    CHECKMATE_TO_WHITE_KING,
    CHECKMATE_TO_BLACK_KING,

};

inline std::string gameStateToString(GameState state) {
    switch(state) {
        case GameState::STALEMATE:
            return "Безвыходное положение";
        case GameState::CHECKMATE_TO_WHITE_KING:
            return "Мат белому королю!";
        case GameState::CHECKMATE_TO_BLACK_KING:
            return "Мат черному королю!";
        default:
            return "UNKNOWN";
    }
}

#endif //CHESS_GAMESTATE_H