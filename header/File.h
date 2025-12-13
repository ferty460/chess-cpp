#ifndef CHESS_HORIZONTAL_H
#define CHESS_HORIZONTAL_H
#include <vector>


enum class File {
    A, B, C, D, E, F, G, H
};

inline std::vector<File> getAllFiles() {
    return { File::A, File::B, File::C, File::D,
             File::E, File::F, File::G, File::H };
}


#endif //CHESS_HORIZONTAL_H